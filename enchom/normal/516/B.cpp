#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int n,m;
char grid[2011][2011];
vector< pair<int,int> > q;

int N[2011][2011];

void Check(int x,int y)
{
    N[x][y]--;

    if (N[x][y]==1)
    {
        q.push_back(make_pair(x,y));
        N[x][y]=9999999;
    }

    return;
}

int NB(int x,int y)
{
    int ctr=0;

    if (grid[x-1][y]=='.')
    ctr++;
    if (grid[x][y-1]=='.')
    ctr++;
    if (grid[x+1][y]=='.')
    ctr++;
    if (grid[x][y+1]=='.')
    ctr++;

    return ctr;
}

int main()
{
    int i,j;
    int uk=0;
    int x,y;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=0;i<=n+1;i++)
    {
        grid[i][0]='*';
        grid[i][m+1]='*';
    }

    for (i=0;i<=m+1;i++)
    {
        grid[0][i]='*';
        grid[n+1][i]='*';
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]=='.')
            N[i][j]=NB(i,j);
            else
            N[i][j]=9999999;

            if (N[i][j]==1)
            {
                q.push_back( make_pair(i,j) );
                N[i][j]=9999999;
            }
        }
    }

    while(uk<q.size())
    {
        x=q[uk].first;
        y=q[uk].second;

        if (grid[x][y]!='.')
        {
            uk++;
            continue;
        }

        if (grid[x][y+1]=='.')
        {
            grid[x][y]='<';
            grid[x][y+1]='>';

            Check(x+1,y+1);
            Check(x,y+2);
            Check(x-1,y+1);
        }
        else if (grid[x+1][y]=='.')
        {
            grid[x][y]='^';
            grid[x+1][y]='v';

            Check(x+1,y+1);
            Check(x+2,y);
            Check(x+1,y-1);
        }
        else if (grid[x][y-1]=='.')
        {
            grid[x][y]='>';
            grid[x][y-1]='<';

            Check(x,y-2);
            Check(x-1,y-1);
            Check(x+1,y-1);
        }
        else if (grid[x-1][y]=='.')
        {
            grid[x][y]='v';
            grid[x-1][y]='^';

            Check(x-1,y+1);
            Check(x-1,y-1);
            Check(x-2,y);
        }
        else
        {
            printf("Not unique\n");
            return 0;
        }

        uk++;
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (grid[i][j]=='.')
            {
                printf("Not unique\n");
                return 0;
            }
        }
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