#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;
typedef long long Int;

bool TFO[1001][1001];
const Int OFFSET=500;

void Move(Int* x,Int* y,Int dir)
{
    if (dir==1)
    {
        *x=*x+1;
    }
    if (dir==2)
    {
        *y=*y+1;
    }
    if (dir==3)
    {
        *x=*x-1;
    }
    if (dir==4)
    {
        *y=*y-1;
    }
    return;
}

Int FIX(Int num)
{
    if (num==5)
    return 1;
    else
    return num;
}

int main()
{
    Int x,y;
    Int cx=0,cy=0;
    Int dir=1;
    Int turns=0;
    Int copyx,copyy;
    Int i,j;
    
    for (i=0;i<=1000;i++)
    {
        for (j=0;j<=1000;j++)
        {
            TFO[i][j]=false;
        }
    }
    
    scanf("%I64d %I64d",&x,&y);
    
    TFO[OFFSET][OFFSET]=true;
    
    while(cx!=x || cy!=y)
    {
        Move(&cx,&cy,dir);
        
        TFO[cx+OFFSET][cy+OFFSET]=true;
        
        copyx=cx;
        copyy=cy;
        Move(&copyx,&copyy,FIX(dir+1));
        
        if ( !TFO[copyx+OFFSET][copyy+OFFSET] )
        {
            dir=FIX(dir+1);
            if (cx!=x || cy!=y)
            turns++;
        }
    }
    
    printf("%I64d\n",turns);
    
    return 0;
}