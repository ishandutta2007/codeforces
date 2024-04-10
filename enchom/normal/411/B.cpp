#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int grid[101][101];
int n,m,k;
int cells[101];
bool locked[101];
bool lockedcpu[101];
int when_locked[101];

int main()
{
    int i,j;

    scanf("%d %d %d",&n,&m,&k);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    for (i=1;i<=m;i++)
    {
        memset(cells,0,sizeof(cells));

        for (j=1;j<=n;j++)
        {
            if (lockedcpu[j])
            continue;

            if (grid[j][i]>0)
            {
                if ( locked[ grid[j][i] ] )
                {
                    lockedcpu[j]=true;
                    when_locked[j]=i;
                }
                else
                cells[ grid[j][i] ]++;
            }
        }

        for (j=1;j<=k;j++)
        {
            if (cells[j]>1)
            {
                locked[j]=true;
            }
        }

        for (j=1;j<=n;j++)
        {
            if (lockedcpu[j])
            continue;

            if (grid[j][i]>0)
            {
                if ( locked[ grid[j][i] ] )
                {
                    when_locked[j]=i;
                    lockedcpu[j]=true;
                }
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d\n",when_locked[i]);
    }

    return 0;
}