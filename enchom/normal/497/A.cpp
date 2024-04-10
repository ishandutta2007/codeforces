#include <iostream>
#include <stdio.h>
using namespace std;

char grid[1003][1003];
int n,m;
bool Better[1003];

int main()
{
    int i,j;
    bool ToRemove=false;
    int ans=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=m;i++)
    {
        ToRemove=false;

        for (j=2;j<=n;j++)
        {
            if (grid[j][i]<grid[j-1][i] && !Better[j])
            {
                ToRemove=true;
            }
        }

        if (ToRemove)
        {
            ans++;
        }
        else
        {
            for (j=2;j<=n;j++)
            {
                if (grid[j][i]>grid[j-1][i])
                {
                    Better[j]=true;
                }
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}