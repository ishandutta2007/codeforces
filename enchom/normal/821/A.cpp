#include <iostream>
#include <stdio.h>
using namespace std;

int n;
int grid[52][52];

int main()
{
    int i,j,in,ja;
    bool good=true;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            scanf("%d",&grid[i][j]);
        }
    }

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if (grid[i][j]!=1)
            {
                good=false;
                for (in=1;in<=n;in++)
                {
                    for (ja=1;ja<=n;ja++)
                    {
                        if (grid[i][in]+grid[ja][j]==grid[i][j])
                        good=true;
                    }
                }

                if (!good)
                {
                    printf("No\n");
                    return 0;
                }
            }
        }
    }

    printf("Yes\n");

    return 0;
}