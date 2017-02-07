#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<ctype.h>


    union REGS i,o;
    initmouse()
    {
    i.x.ax=0;
    int86(0x33,&i,&o);
    return(o.x.ax);
    }
class movie
{
public:
void play();
void check(char *mn,char *cho,int &wi,int &ri);
void showmouseptr()
    {
     i.x.ax=1;
    int86(0x33,&i,&o);
    }
void restrictmouseptr(int x1,int y1,int x2,int y2)
    {
    i.x.ax=7;
    i.x.cx=x1;
    i.x.dx=x2;
    int86(0x33,&i,&o);

    i.x.ax=8;
    i.x.cx=y1;
    i.x.dx=y2;
    int86(0x33,&i,&o);
    }
    void getmousepos(int *button,int *x,int *y)
    {
    i.x.ax=3;
    int86(0x33,&i,&o);
    *button=o.x.bx;
    *x=o.x.cx;
    *y=o.x.dx;
    }
    void welcome()
    {
	cleardevice();
	setbkcolor(BLUE);
	settextstyle(3,0,8);
	outtextxy(100,50,"W");
	delay(200);
	settextstyle(1,0,6);
	outtextxy(200,50,"E");
	delay(200);
	settextstyle(1,0,4);
	outtextxy(250,50,"L");
	delay(200);
	settextstyle(1,0,2);
	outtextxy(300,50,"C");
	delay(200);
	settextstyle(1,0,4);
	outtextxy(350,50,"O");
	delay(200);
	settextstyle(1,0,6);
	outtextxy(400,50,"M");
	delay(200);
	settextstyle(1,0,8);
	outtextxy(500,50,"E");
	delay(500);
	settextstyle(9,0,2);
	outtextxy(220,200,"LET'S PLAY");
	delay(500);
	settextstyle(9,0,2);
	outtextxy(100,250,"BOLLYWOOD/HOLLYWOOD");

    }

void instructions()
{
setbkcolor(GREEN);
settextstyle(3,0,1);
rectangle(620,5,637,25);
settextstyle(8,0,3);
outtextxy(100,50,"WELCOME to the GAME");
settextstyle(3,0,1);
outtextxy(110,120,"* About the Game *");
outtextxy(110,150,"1.Game consists of two players.");
outtextxy(110,170,"2.One player thinks of a movie and the");
outtextxy(130,190,"second player guesses it.");
outtextxy(110,210,"3.Player guessing the name can have 9 wrong chances.");
outtextxy(110,230,"4.Player will get points:(10*number of attempts left).");
outtextxy(110,250,"5.Player guessing the name will get a hint");
outtextxy(130,270,"when the last attempt is left.");

}
};

void movie::check(char *mn,char *cho,int &wi,int &ri)
{
int pos=0,pos1=0,flag=0,i;
    for(i=0;mn[i]!='\0';i++)
	{
	    if(mn[i]==cho[0])
	    {
	    pos=i+1;
	    flag=1;
	    ri++;
	    if(pos<=23)
	    outtextxy(100+(pos-1)*20,100,cho);
	    else
	    {
	    pos1=pos-23;
	    outtextxy(100+(pos1-1)*20,130,cho);
	    }
	    }
	}
	if(flag==0)
	{
	wi++;
	line(120+(wi-1)*50,35,110+(wi-1)*50,80);
	cout<<'\a';
	}
}
void movie::play()
{
int gdriver = DETECT, gmode, errorcode,gm,maxx,maxy,mx,my,button,prevx,prevy;
initgraph(&gdriver, &gmode, "../bgi");
char name1[20],name2[20],mn[50],ht[30],ch,ch1[2]={'B'},cho[2]={'V'};
int i,j,y,t=0,nl,t1=0,x=0,q=0,w=0,pos,pos1,ri=0,wi=0,nls=0,choice;
    maxx=getmaxx();
    maxy=getmaxy();
    cleardevice();
    welcome();
    delay(1000);
    setviewport(1,1,maxx-1,maxy-1,1);
    restrictmouseptr(1,1,maxx-1,maxy-1);
    showmouseptr();
    cleardevice();
    instructions();
    delay(4000);
    cleardevice();
    setbkcolor(DARKGRAY);
    settextstyle(3,0,2);
    outtextxy(200,100,"Enter your choice");
    outtextxy(200,150,"1.BOLLYWOOD");
    outtextxy(200,200,"2.HOLLYWOOD");
    outtextxy(203,282,"YOUR CHOICE-  _");
    gotoxy(47,19);
    cin>>choice;
    settextstyle(3,0,1);
    rectangle(520,400,590,435);
    outtextxy(530,405,"START");

    switch(choice)
    {
	case 1:while(!kbhit())
	{
	getmousepos(&button,&mx,&my);
	if((button &1)==1)
	{
	if(mx>520 && mx<590 && my>400 && my<435)
	{
	cleardevice();
	setbkcolor(RED);
	settextstyle(6,0,1);
	outtextxy(40,55,"Enter Movie name :");
	outtextxy(40,88,"Enter Hint Actor or Actress Name :");
	gotoxy(25,5);
	gets(mn);
	gotoxy(40,7);
	gets(ht);
	nl=strlen(mn);
	for(i=0;mn[i]!='\0';i++)
	{
	if(isalpha(mn[i])&&(mn[i]!='a'&&mn[i]!='e'&&mn[i]!='i'&&mn[i]!='o'&&mn[i]!='u'))
	nls++;
	}
	break;
	}
	}
	}
	cleardevice();
	settextstyle(4,0,5);
	outtextxy(100,30,"B O L L Y W O O D");
	settextstyle(4,0,2);
	for(i=0;i<nl;i++)
	    {
	    if((mn[i]!='a'||mn[i]!='e'||mn[i]!='i'||mn[i]!='o'||mn[i]!='u')&& mn[i]!=' ')
	    outtextxy(100+t,100+t1,"_");
	    if(mn[i]=='a')
	    outtextxy(100+t,100+t1,"a");
	    if(mn[i]=='e')
	    outtextxy(100+t,100+t1,"e");
	    if(mn[i]=='i')
	    outtextxy(100+t,100+t1,"i");
	    if(mn[i]=='o')
	    outtextxy(100+t,100+t1,"o");
	    if(mn[i]=='u')
	    outtextxy(100+t,100+t1,"u");
	    if(mn[i]==' ')
	    outtextxy(100+t,100+t1,"/");
	    t+=20;
		if(i==22)
		{
		t1+=30;
		t=0;
		}
	    }
	settextstyle(1,0,1);
	for(i=6;i>0;i--)
	    {
	    for(j=0;j<i;j++)
		{
		rectangle(170+x+q,200+w,200+x+q,230+w);
		outtextxy(180+x+q,203+w,ch1);
		if(ch1[0]=='D'||ch1[0]=='H'||ch1[0]=='N'||ch1[0]=='T')
		ch1[0]+=2;
		else
		ch1[0]++;
		x+=40;
		}
	    x=0;
	    q+=21;
	    w+=40;
	    }
while(!kbhit())
    {

    getmousepos(&button,&mx,&my);

	if((button &1)==1)
	{
	    if(mx>170 && mx<200 && my>200 && my<230)
	    {
	    cho[0]='b';
	    check(mn,cho,wi,ri);
	    }

	    if(mx>210 && mx<240 && my>200 && my<230)
	    {
	    cho[0]='c';
	    check(mn,cho,wi,ri);
	    }
	    if(mx>250 && mx<280 && my>200 && my<230)
	    {
	    cho[0]='d';
	    check(mn,cho,wi,ri);
	    }
	    if(mx>290 && mx<320 && my>200 && my<230)
	    {
	    cho[0]='f';
	    check(mn,cho,wi,ri);
	    }
	if(mx>330 && mx<360 && my>200 && my<230)
	{
	cho[0]='g';
	check(mn,cho,wi,ri);
	    }
	if(mx>370 && mx<400 && my>200 && my<230)
	{
	cho[0]='h';
	check(mn,cho,wi,ri);
	    }
	if(mx>191 && mx<221 && my>240 && my<270)
	{
	cho[0]='j';
	check(mn,cho,wi,ri);
	    }
	if(mx>231 && mx<261 && my>240 && my<270)
	{
	cho[0]='k';
	check(mn,cho,wi,ri);
	    }
	if(mx>271 && mx<301 && my>240 && my<270)
	{
	cho[0]='l';
	check(mn,cho,wi,ri);
	    }
	if(mx>311 && mx<341 && my>240 && my<270)
	{
	cho[0]='m';
	check(mn,cho,wi,ri);
	    }
	if(mx>351 && mx<381 && my>240 && my<270)
	{
	cho[0]='n';
	check(mn,cho,wi,ri);
	    }
	if(mx>212 && mx<242 && my>280 && my<310)
	{
	cho[0]='p';
	check(mn,cho,wi,ri);
	    }
	if(mx>252 && mx<282 && my>280 && my<310)
	{
	cho[0]='q';
	check(mn,cho,wi,ri);
	    }
	if(mx>292 && mx<322 && my>280 && my<310)
	{
	cho[0]='r';
	check(mn,cho,wi,ri);
	    }
	if(mx>332 && mx<362 && my>280 && my<310)
	{
	cho[0]='s';
	check(mn,cho,wi,ri);
	    }
	if(mx>233 && mx<263 && my>320 && my<350)
	{
	cho[0]='t';
	check(mn,cho,wi,ri);
	    }
	if(mx>273 && mx<303 && my>320 && my<350)
	{
	cho[0]='v';
	check(mn,cho,wi,ri);
	    }
	if(mx>313 && mx<343 && my>320 && my<350)
	{
	cho[0]='w';
	check(mn,cho,wi,ri);
	    }
	if(mx>254 && mx<284 && my>360 && my<390)
	{
	cho[0]='x';
	check(mn,cho,wi,ri);
	    }
	if(mx>294 && mx<324 && my>360 && my<390)
	{
	cho[0]='y';
	check(mn,cho,wi,ri);
	    }
	if(mx>275 && mx<305 && my>400 && my<430)
	{
	cho[0]='z';
	check(mn,cho,wi,ri);
	    }
	if(wi==8)
	{
	outtextxy(500,200,"Hint");
	outtextxy(500,230,ht);
	}
	if(wi==9||ri==nls)
	{
	if(wi==9)
	outtextxy(200,450,"YOU LOSE THE GAME");
	if(ri==nls)
	{
	outtextxy(200,450,"YOU WON THE GAME");
	gotoxy(57,28);
	rectangle(440,422,533,450);
	cout<<"SCORE : "<<(9-wi)*10;
	}
	break;
	}
	settextstyle(1,0,1);
	outtextxy(15,350,"PRESS ENTER AFTER");
	outtextxy(15,380,"  EVERY GUESS");
	getch();
	}
	}


	case 2:while(!kbhit())
	{
	getmousepos(&button,&mx,&my);
	if((button &1)==1)
	{
	if(mx>520 && mx<590 && my>400 && my<435)
	{
	cleardevice();
	setbkcolor(BROWN);
	settextstyle(6,0,1);
	outtextxy(40,55,"Enter Movie name :");
	outtextxy(40,88,"Enter Hint Actor or Actress Name :");
	gotoxy(25,5);
	gets(mn);
	gotoxy(40,7);
	gets(ht);
	nl=strlen(mn);
	for(i=0;mn[i]!='\0';i++)
	{
	if(isalpha(mn[i])&&(mn[i]!='a'&&mn[i]!='e'&&mn[i]!='i'&&mn[i]!='o'&&mn[i]!='u'))
	nls++;
	}
	break;
	}
	}
	}
	 cleardevice();
	settextstyle(4,0,5);
	outtextxy(100,30,"H O L L Y W O O D");
	settextstyle(4,0,2);
	for(i=0;i<nl;i++)
	    {
	    if((mn[i]!='a'||mn[i]!='e'||mn[i]!='i'||mn[i]!='o'||mn[i]!='u')&& mn[i]!=' ')
	    outtextxy(100+t,100+t1,"_");
	    if(mn[i]=='a')
	    outtextxy(100+t,100+t1,"a");
	    if(mn[i]=='e')
	    outtextxy(100+t,100+t1,"e");
	    if(mn[i]=='i')
	    outtextxy(100+t,100+t1,"i");
	    if(mn[i]=='o')
	    outtextxy(100+t,100+t1,"o");
	    if(mn[i]=='u')
	    outtextxy(100+t,100+t1,"u");
	    if(mn[i]==' ')
	    outtextxy(100+t,100+t1,"/");
	    t+=20;
		if(i==22)
		{
		t1+=30;
		t=0;
		}
	    }
	settextstyle(1,0,1);
	for(i=6;i>0;i--)
	    {
	    for(j=0;j<i;j++)
		{
		rectangle(170+x+q,200+w,200+x+q,230+w);
		outtextxy(180+x+q,203+w,ch1);
		if(ch1[0]=='D'||ch1[0]=='H'||ch1[0]=='N'||ch1[0]=='T')
		ch1[0]+=2;
		else
		ch1[0]++;
		x+=40;
		}
	    x=0;
	    q+=21;
	    w+=40;
	    }
while(!kbhit())
    {

    getmousepos(&button,&mx,&my);

	if((button &1)==1)
	{
	    if(mx>170 && mx<200 && my>200 && my<230)
	    {
	    cho[0]='b';
	    check(mn,cho,wi,ri);
	    }

	    if(mx>210 && mx<240 && my>200 && my<230)
	    {
	    cho[0]='c';
	    check(mn,cho,wi,ri);
	    }
	    if(mx>250 && mx<280 && my>200 && my<230)
	    {
	    cho[0]='d';
	    check(mn,cho,wi,ri);
	    }
	    if(mx>290 && mx<320 && my>200 && my<230)
	    {
	    cho[0]='f';
	    check(mn,cho,wi,ri);
	    }
	if(mx>330 && mx<360 && my>200 && my<230)
	{
	cho[0]='g';
	check(mn,cho,wi,ri);
	    }
	if(mx>370 && mx<400 && my>200 && my<230)
	{
	cho[0]='h';
	check(mn,cho,wi,ri);
	    }
	if(mx>191 && mx<221 && my>240 && my<270)
	{
	cho[0]='j';
	check(mn,cho,wi,ri);
	    }
	if(mx>231 && mx<261 && my>240 && my<270)
	{
	cho[0]='k';
	check(mn,cho,wi,ri);
	    }
	if(mx>271 && mx<301 && my>240 && my<270)
	{
	cho[0]='l';
	check(mn,cho,wi,ri);
	    }
	if(mx>311 && mx<341 && my>240 && my<270)
	{
	cho[0]='m';
	check(mn,cho,wi,ri);
	    }
	if(mx>351 && mx<381 && my>240 && my<270)
	{
	cho[0]='n';
	check(mn,cho,wi,ri);
	    }
	if(mx>212 && mx<242 && my>280 && my<310)
	{
	cho[0]='p';
	check(mn,cho,wi,ri);
	    }
	if(mx>252 && mx<282 && my>280 && my<310)
	{
	cho[0]='q';
	check(mn,cho,wi,ri);
	    }
	if(mx>292 && mx<322 && my>280 && my<310)
	{
	cho[0]='r';
	check(mn,cho,wi,ri);
	    }
	if(mx>332 && mx<362 && my>280 && my<310)
	{
	cho[0]='s';
	check(mn,cho,wi,ri);
	    }
	if(mx>233 && mx<263 && my>320 && my<350)
	{
	cho[0]='t';
	check(mn,cho,wi,ri);
	    }
	if(mx>273 && mx<303 && my>320 && my<350)
	{
	cho[0]='v';
	check(mn,cho,wi,ri);
	    }
	if(mx>313 && mx<343 && my>320 && my<350)
	{
	cho[0]='w';
	check(mn,cho,wi,ri);
	    }
	if(mx>254 && mx<284 && my>360 && my<390)
	{
	cho[0]='x';
	check(mn,cho,wi,ri);
	    }
	if(mx>294 && mx<324 && my>360 && my<390)
	{
	cho[0]='y';
	check(mn,cho,wi,ri);
	    }
	if(mx>275 && mx<305 && my>400 && my<430)
	{
	cho[0]='z';
	check(mn,cho,wi,ri);
	    }
	if(wi==8)
	{
	outtextxy(500,200,"Hint");
	outtextxy(500,230,ht);
	}
	if(wi==9||ri==nls)
	{
	if(wi==9)
	outtextxy(200,450,"YOU LOSE THE GAME");
	if(ri==nls)
	{
	outtextxy(200,450,"YOU WON THE GAME");
	gotoxy(57,28);
	rectangle(440,422,533,450);
	cout<<"SCORE : "<<(9-wi)*10;
	}
	break;
	}
	settextstyle(1,0,1);
	outtextxy(15,350,"PRESS ENTER AFTER");
	outtextxy(15,380,"  EVERY GUESS");
	getch();



	}
    }


}
}


void main()
{
       clrscr();
       movie m;
       m.play();
       getch();
}
