#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;
int t, n, k;
llong p2[200111];
llong p2n[200111];

int main()
{
    int i, j;
    int test;

    p2[0] = 1LL;
    for (i=1;i<=200001;i++)
    {
        p2[i] = (p2[i-1] * 2LL) % MOD;
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d %d", &n, &k);

        p2n[0] = 1LL;
        for (i=1;i<=200001;i++)
        {
            p2n[i] = (p2n[i-1] * p2[n]) % MOD;
        }

        llong ans = 0LL;
        llong getHereEq = 1LL;

        for (i=1;i<=k;i++)
        {
            //printf("Getting to %d is %lld\n", i, getHereEq);

            /// Wins at this position
            if (n % 2 == 0)
            {
                //printf("Win of %lld\n", getHereEq * p2[k - i]);
                ans += getHereEq * p2n[k - i];
                ans %= MOD;
            }

            llong newGetHereEq = 0LL;
            /// Continue equals with 1 here
            if (n % 2 == 1)
            {
                newGetHereEq += getHereEq;
            }

            /// Continue equals with 0 here
            newGetHereEq += getHereEq * p2[n - 1];
            if (n % 2 == 0)
                newGetHereEq += (MOD - getHereEq);

            getHereEq = newGetHereEq % MOD;
        }

        //printf("Final get here is %lld\n", getHereEq);
        ans += getHereEq;
        ans %= MOD;

        printf("%lld\n", ans);
    }

    return 0;
}