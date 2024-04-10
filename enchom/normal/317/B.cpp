#include <iostream>
#include <stdio.h>
using namespace std;
typedef int Int;

struct cell
{
    Int x,y;
};

Int grid[301][301];
cell toupdate[2][900001];
Int L[2];
Int UTFO[301][301];
Int Key=1;

int main()
{
    Int i,j;
    Int n,q;
    Int send;
    Int ctr=0;
    Int cur=0;
    Int op=1;
    Int mx,my;
    Int X,Y;

    for (i=0;i<=300;i++)
    {
        for (j=0;j<=300;j++)
        {
            grid[i][j]=0;
            UTFO[i][j]=0;
        }
    }

    scanf("%d",&n);

    grid[150][150]=n;

    toupdate[cur][1].x=150;
    toupdate[cur][1].y=150;
    L[cur]=1;
    L[op]=0;

    while(L[cur]>0)
    {
        Key++;
        for (i=1;i<=L[cur];i++)
        {
            ctr++;
            mx=toupdate[cur][i].x;
            my=toupdate[cur][i].y;

            send=grid[mx][my]/4;

            grid[mx][my]=grid[mx][my]%4;

            grid[mx][my+1]+=send;
            if (UTFO[mx][my+1]!=Key && grid[mx][my+1]>=4)
            {
                L[op]++;
                toupdate[op][L[op]].x=mx;
                toupdate[op][L[op]].y=my+1;
                UTFO[mx][my+1]=Key;
            }
            grid[mx][my-1]+=send;
            if (UTFO[mx][my-1]!=Key && grid[mx][my-1]>=4)
            {
                L[op]++;
                toupdate[op][L[op]].x=mx;
                toupdate[op][L[op]].y=my-1;
                UTFO[mx][my-1]=Key;
            }
            grid[mx+1][my]+=send;
            if (UTFO[mx+1][my]!=Key && grid[mx+1][my]>=4)
            {
                L[op]++;
                toupdate[op][L[op]].x=mx+1;
                toupdate[op][L[op]].y=my;
                UTFO[mx+1][my]=Key;
            }
            grid[mx-1][my]+=send;
            if (UTFO[mx-1][my]!=Key && grid[mx-1][my]>=4)
            {
                L[op]++;
                toupdate[op][L[op]].x=mx-1;
                toupdate[op][L[op]].y=my;
                UTFO[mx-1][my]=Key;
            }
        }
        L[cur]=0;
        op=cur;
        cur=cur^1;
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d",&X,&Y);

        mx=150+X;
        my=150+Y;

        if (mx<0 || mx>300 || my<0 || my>300)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",grid[mx][my]);
        }
    }

    return 0;
}