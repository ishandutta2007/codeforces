#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

int n;
char grid[111][111];

int main()
{
    int i,j;
    int ctr=0;
    Int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);
    }

    for (i=1;i<=n;i++)
    {
        ctr=0;
        for (j=1;j<=n;j++)
        {
            if (grid[i][j]=='C')
            ctr++;
        }

        ans+=( (Int)ctr*(Int)(ctr-1) )/2LL;
    }

    for (i=1;i<=n;i++)
    {
        ctr=0;
        for (j=1;j<=n;j++)
        {
            if (grid[j][i]=='C')
            ctr++;
        }

        ans+=( (Int)ctr*(Int)(ctr-1) )/2LL;
    }

    printf("%lld\n",ans);

    return 0;
}