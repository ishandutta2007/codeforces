#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;

llong FastPow(llong k, llong p)
{
    if (p == 0LL)
        return 1LL;

    llong P = FastPow(k, p / 2LL);
    P = (P * P) % MOD;

    if (p % 2LL == 1LL)
        P = (P * k) % MOD;

    return P;
}

llong Inv(llong x)
{
    return FastPow(x, MOD - 2LL);
}

int t;
int n;

llong F[1000111];
llong pow2[1000111];
llong accs[1000111];

llong sumPow2s(int lst)
{
    if (lst < 0)
        return 0LL;

    llong ans = pow2[lst + 1] - 1LL + MOD;
    if (ans >= MOD)
        ans -= MOD;

    return ans;
}

int main()
{
    //freopen("test.txt", "r", stdin);
    int test;
    int i, j;

    pow2[0] = 1LL;
    for (i=1;i<=1000001;i++)
    {
        pow2[i] = (pow2[i - 1] * 2LL) % MOD;
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        for (i=0;i<=n+1;i++)
        {
            accs[i] = 0;
        }

        llong acc = 1LL;
        accs[n - 1] = (-1) + MOD;
        for (i=n;i>=1;i--)
        {
            int sz = (i - 1) / 2;
            int L = i - sz;

            //printf("Adding change %lld\n", accs[i]);
            acc += accs[i];
            if (acc >= MOD)
                acc -= MOD;

            //printf("Accumulator %lld at %d\n", acc, i);

            F[i] = acc;

            acc += F[i];
            if (acc >= MOD)
                acc -= MOD;

            //printf("Bumping to %lld and reducing future %d with %lld\n", acc, L - 1, F[i]);
            accs[L - 1] = accs[L - 1] - F[i] + MOD;
            if (accs[L - 1] >= MOD)
                accs[L - 1] -= MOD;
        }

        for (i=1;i<=n;i++)
        {
            //printf("F[%d] = %lld\n", i, F[i]);
        }

        llong invp2n = Inv(pow2[n]);

        for (i=1;i<=n;i++)
        {
            llong rhs = F[i];
            llong lhs = 1LL + sumPow2s(i / 2 - 1);
            if (lhs >= MOD)
                lhs -= MOD;

            rhs *= 2LL;
            if (rhs >= MOD)
                rhs -= MOD;

            llong res = rhs * lhs;
            res %= MOD;
            res *= invp2n;
            res %= MOD;

            //printf("debug %lld/%lld\n", rhs * lhs, pow2[n]);
            printf("%lld\n", res);
        }
    }

    return 0;
}