#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

struct tai
{
    Int move;
    Int square;
};

char table[9][9];
bool canstep[9][9][11];
tai tail[10000001];
Int tL=0;
Int uk;

int main()
{
    Int i,j,in;
    Int x,y;
    
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=8;j++)
        {
            cin>>table[i][j];
        }
    }
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=8;j++)
        {
            for (in=1;in<=10;in++)
            {
                canstep[i][j][in]=true;
                
                if (i>in-1)
                {
                    if (table[i-in+1][j]=='S')
                    canstep[i][j][in]=false;
                }
                if (i>in)
                {
                    if (table[i-in][j]=='S')
                    canstep[i][j][in]=false;
                }
            }
        }
    }
    tL=1;
    tail[tL].square=57;
    tail[tL].move=0;
    uk=1;
    
    while(uk<=tL)
    {
        if (tail[uk].square%8!=0)
        x=tail[uk].square/8+1;
        else
        x=tail[uk].square/8;
        
        y=tail[uk].square-(x-1)*8;
        
        if (tail[uk].move==9)
        {
            printf("WIN\n");
            return 0;
        }
        
        if ( (x==1 && y==7) || (x==2 && y==7) || (x==2 && y==8) )
        {
            printf("WIN\n");
            return 0;
        }
        
        for (i=x-1;i<=x+1;i++)
        {
            for (j=y-1;j<=y+1;j++)
            {
                if (i>=1 && i<=8 && j>=1 && j<=8)
                {
                    if (canstep[i][j][tail[uk].move+1])
                    {
                        tL++;
                        tail[tL].move=tail[uk].move+1;
                        tail[tL].square=(i-1)*8+j;
                    }
                }
            }
        }
        uk++;
    }
    
    printf("LOSE\n");
    return 0;
}