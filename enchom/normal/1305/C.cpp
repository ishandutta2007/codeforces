#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long llong;

int n,m;
llong a[200111];

llong ABS(llong a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    int i,j;

    scanf("%d %d",&n,&m);

    if (n > m + 2)
    {
        printf("0\n");
        return 0;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }

    llong ans = 1;
    for (i=1;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            ans *= ABS(a[i] - a[j]);
            ans %= (llong)m;
        }
    }

    printf("%lld\n",ans);

    return 0;
}