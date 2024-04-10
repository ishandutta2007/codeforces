#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong xsum = 0, ysum = 0;
llong ctr = 0;
char grid[1111][1111];
int n,m;

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",grid[i]+1);

        for (j=1;j<=m;j++)
        {
            if (grid[i][j] == 'B')
            {
                xsum += i;
                ysum += j;
                ctr++;
            }
        }
    }

    printf("%lld %lld\n",xsum/ctr,ysum/ctr);

    return 0;
}