#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
char grid[1011][1011];

int R[1011][1011];
int D[1011][1011];

int GetR(int x1,int y1,int x2,int y2)
{
    if (x2<x1 || y2<y1)
    return 0;

    return R[x2][y2]-R[x1-1][y2]-R[x2][y1-1]+R[x1-1][y1-1];
}

int GetD(int x1,int y1,int x2,int y2)
{
    if (x2<x1 || y2<y1)
    return 0;

    return D[x2][y2]-D[x1-1][y2]-D[x2][y1-1]+D[x1-1][y1-1];
}

int main()
{
    int i,j;
    int curval;
    int q;
    int x1,y1,x2,y2;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            curval=0;

            if (j==m)
            curval=0;
            else if (grid[i][j]=='.' && grid[i][j+1]=='.')
            curval=1;

            R[i][j]=R[i-1][j]+R[i][j-1]-R[i-1][j-1]+curval;

            ///

            curval=0;

            if (i==n)
            curval=0;
            else if (grid[i][j]=='.' && grid[i+1][j]=='.')
            curval=1;

            D[i][j]=D[i-1][j]+D[i][j-1]-D[i-1][j-1]+curval;
        }
    }

    scanf("%d",&q);

    for (i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",GetR(x1,y1,x2,y2-1)+GetD(x1,y1,x2-1,y2));
    }

    return 0;
}