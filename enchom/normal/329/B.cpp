#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

struct t
{
    Int x,y,dist;
};

char grid[1001][1001];
Int n,m;
Int sx,sy,fx,fy;
bool TFO[1001][1001];
t tail[1000001];
Int tL;

bool OK(Int x,Int y)
{
    if (x<1 || y<1 || x>n || y>m)
    return false;
    if (TFO[x][y] || grid[x][y]=='T')
    return false;

    return true;
}

Int BFS()
{
    Int uk=1;
    Int lim=999999999;
    Int battles=0;
    Int nx,ny;

    tL=1;
    tail[1].x=fx;
    tail[1].y=fy;
    tail[1].dist=0;

    while(uk<=tL)
    {
        if (tail[uk].dist>lim)
        break;

        if ( grid[ tail[uk].x ][ tail[uk].y ]>='0' && grid[ tail[uk].x ][ tail[uk].y ]<='9' )
        {
            battles=battles+(grid[ tail[uk].x ][ tail[uk].y ]-'0');
        }

        if ( tail[uk].x==sx && tail[uk].y==sy )
        {
            lim=tail[uk].dist;
        }

        ///
        nx=tail[uk].x+1;
        ny=tail[uk].y;
        if (OK(nx,ny))
        {
            tL++;
            tail[tL].x=nx;
            tail[tL].y=ny;
            tail[tL].dist=tail[uk].dist+1;
            TFO[nx][ny]=true;
        }
        ///
        nx=tail[uk].x;
        ny=tail[uk].y+1;
        if (OK(nx,ny))
        {
            tL++;
            tail[tL].x=nx;
            tail[tL].y=ny;
            tail[tL].dist=tail[uk].dist+1;
            TFO[nx][ny]=true;
        }
        ///
        nx=tail[uk].x-1;
        ny=tail[uk].y;
        if (OK(nx,ny))
        {
            tL++;
            tail[tL].x=nx;
            tail[tL].y=ny;
            tail[tL].dist=tail[uk].dist+1;
            TFO[nx][ny]=true;
        }
        ///
        nx=tail[uk].x;
        ny=tail[uk].y-1;
        if (OK(nx,ny))
        {
            tL++;
            tail[tL].x=nx;
            tail[tL].y=ny;
            tail[tL].dist=tail[uk].dist+1;
            TFO[nx][ny]=true;
        }
        ///

        uk++;
    }

    return battles;
}

int main()
{
    Int i,j;

    memset(TFO,false,sizeof(TFO[0][0])*1001*1001);

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            if (grid[i][j]=='E')
            {
                fx=i;
                fy=j;
            }
        }
    }

    printf("%I64d\n",BFS());
}