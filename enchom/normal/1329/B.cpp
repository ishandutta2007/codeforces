#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long llong;

int t;
llong m;
llong d;
llong F[41][41];

llong solve(int len, int lastPow)
{
    if (F[len][lastPow] != -1)
        return F[len][lastPow];

    int i;
    llong ans = 0;

    if (len > 1)
    {
        for (i=0;i<lastPow;i++)
        {
            ans += solve(len-1, i);
            ans %= m;
        }
    }
    else
    {
        ans = 1;
    }

    llong L = (1LL<<lastPow);
    llong R = 2LL * L - 1LL;

    R = min(R, d);

    llong coef = max(0LL, R - L + 1LL);

    ans *= coef;
    ans %= m;

    F[len][lastPow] = ans;

    return ans;
}

int main()
{
    int i,j;
    int t;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        memset(F,-1,sizeof(F));

        scanf("%lld %lld",&d,&m);

        llong ans = 0;
        for (i=1;i<=31;i++)
        {
            for (j=0;j<30;j++)
            {
                ans += solve(i, j);
                ans %= m;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}