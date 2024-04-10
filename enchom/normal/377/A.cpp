#include <iostream>
#include <stdio.h>
using namespace std;

int n,m,k;
char grid[501][501];
bool TFO[501][501];
pair<int,int> WhoHasOut[250001];
int outctr=0;

int ABS(int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

void DFS(int x,int y)
{
    if (x<1 || y<1 || x>n || y>m)
    return;
    if (grid[x][y]!='.')
    return;
    if (TFO[x][y])
    return;

    TFO[x][y]=true;

    int i,j;

    for (i=x-1;i<=x+1;i++)
    {
        for (j=y-1;j<=y+1;j++)
        {
            if (ABS(i-x)+ABS(j-y)==1)
            {
                DFS(i,j);
            }
        }
    }

    outctr++;

    WhoHasOut[outctr].first=x;
    WhoHasOut[outctr].second=y;
}

int main()
{
    int i,j;
    int marked=0;

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]=='.')
            {
                DFS(i,j);
            }
        }
    }

    for (i=1;i<=outctr;i++)
    {
        if (marked==k)
        break;

        marked++;
        grid[ WhoHasOut[i].first ][ WhoHasOut[i].second ]='X';
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            printf("%c",grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}