#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct tfo
{
    Int mark1,mark2;
};

tfo CoolTFO[1501][1501];
char field[1501][1501];
bool endless=false;
Int n,m;

Int FX(Int x)
{
    if (x==0)
    return n;
    else if (x==n+1)
    return 1;
    else
    return x;
}

Int FY(Int y)
{
    if (y==0)
    return m;
    else if (y==m+1)
    return 1;
    else
    return y;
}

bool Good(Int x,Int y)
{
    if (field[x][y]=='#')
    return false;
    else
    return true;
}

void DFS(Int x,Int y,Int m1,Int m2)
{
    Int ch1,ch2;

    if (CoolTFO[x][y].mark1!=-999999999)
    {
        if (CoolTFO[x][y].mark1==m1 && CoolTFO[x][y].mark2==m2)
        return;
        else
        {
            endless=true;
            return;
        }
    }

    CoolTFO[x][y].mark1=m1;
    CoolTFO[x][y].mark2=m2;

    Int nx,ny;

    nx=FX(x-1);
    ny=FY(y);
    if (Good(nx,ny))
    {
        if (x==1)
        DFS(nx,ny,m1-1,m2);
        else
        DFS(nx,ny,m1,m2);
    }
    /////////////////////////
    nx=FX(x+1);
    ny=FY(y);
    if (Good(nx,ny))
    {
        if (x==n)
        DFS(nx,ny,m1+1,m2);
        else
        DFS(nx,ny,m1,m2);
    }
    /////////////////////////
    nx=FX(x);
    ny=FY(y-1);
    if (Good(nx,ny))
    {
        if (y==1)
        DFS(nx,ny,m1,m2-1);
        else
        DFS(nx,ny,m1,m2);
    }
    /////////////////////////
    nx=FX(x);
    ny=FY(y+1);
    if (Good(nx,ny))
    {
        if (y==m)
        DFS(nx,ny,m1,m2+1);
        else
        DFS(nx,ny,m1,m2);
    }

    return;
}

int main()
{
    Int i,j;
    Int sx,sy;

    for (i=0;i<=1500;i++)
    {
        for (j=0;j<=1500;j++)
        {
            CoolTFO[i][j].mark1=-999999999;
            CoolTFO[i][j].mark2=-999999999;
        }
    }

    scanf("%I64d %I64d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",field[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (field[i][j]=='S')
            {
                sx=i;
                sy=j;
                break;
            }
        }
    }

    DFS(sx,sy,1,1);

    if (!endless)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

    return 0;
}