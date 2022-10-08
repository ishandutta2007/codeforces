#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 998244353LL;

int t;
int n;
llong nums[200111];

llong prefixes[200111];
llong suffixes[200111];

llong pow2[200111];
llong fact[200111];

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

llong Inv(llong k)
{
    return FastPow(k, MOD - 2LL);
}

llong C(llong N, llong K)
{
    return ( fact[N] * Inv( (fact[K] * fact[N - K]) % MOD ) ) % MOD;
}

struct tracker
{
    llong val;
    int L, R;
};


int main()
{
    //freopen("test.txt", "r", stdin);

    int test;
    int i, j;

    pow2[0] = 1LL;
    fact[0] = 1LL;
    for (i=1;i<=200000;i++)
    {
        pow2[i] = (pow2[i-1] * 2LL) % MOD;
        fact[i] = (fact[i-1] * (llong)i) % MOD;
    }

    scanf("%d", &t);

    for (test=1;test<=t;test++)
    {
        scanf("%d", &n);

        prefixes[0] = 0LL;
        for (i=1;i<=n;i++)
        {
            scanf("%lld", &nums[i]);
            prefixes[i] = prefixes[i - 1] + nums[i];
            //printf("%d ", prefixes[i]);
        }
        //printf("\n");

        suffixes[n + 1] = 0LL;
        for (i=n;i>=1;i--)
        {
            suffixes[i] = suffixes[i + 1] + nums[i];
        }

        /*for (i=1;i<=n;i++)
        {
            printf("%d ", suffixes[i]);
        }
        printf("\n");*/

        if (n == 1)
        {
            printf("1\n");
            continue;
        }

        tracker pref;
        pref.L = 1;
        pref.R = 1;
        pref.val = prefixes[1];

        tracker suff;
        suff.L = n;
        suff.R = n;
        suff.val = suffixes[n];

        llong splitsUntilNow = 0LL;

        while(pref.L <= suff.R)
        {
            pref.val = prefixes[pref.L];
            suff.val = suffixes[suff.L];

            while(pref.R < n && prefixes[pref.R + 1] == pref.val)
                pref.R++;
            while(suff.L > 1 && suffixes[suff.L - 1] == suff.val)
                suff.L--;

            //printf("\n%d-%d and %d-%d\n", pref.L, pref.R, suff.L, suff.R);
            //printf("Splits until now are %lld\n", splitsUntilNow);

            if (pref.val < suff.val)
            {
                pref.L = pref.R + 1;
                pref.R = pref.R + 1;
            }
            else if (suff.val < pref.val)
            {
                suff.R = suff.L - 1;
                suff.L = suff.L - 1;
            }
            else
            {
                llong curSplits = 0;

                if (pref.R + 1 < suff.L) /// Regular case
                {
                    int prefSize = pref.R - pref.L + 1;
                    int sufSize = suff.R - suff.L + 1;

                    for (i=1;i<=min(prefSize, sufSize);i++)
                    {
                        curSplits += C(prefSize, i) * C(sufSize, i);
                        curSplits %= MOD;
                    }
                }
                else /// Merger case
                {
                    int totalLength = suff.R - pref.L + 1;

                    curSplits = pow2[totalLength - 1];
                    curSplits = (curSplits - 1 + MOD) % MOD;
                }

                //printf("Cursplits determined to be %d\n", curSplits);

                splitsUntilNow = splitsUntilNow + (curSplits * splitsUntilNow) + curSplits;
                splitsUntilNow %= MOD;

                pref.L = pref.R + 1;
                pref.R = pref.R + 1;
                suff.R = suff.L - 1;
                suff.L = suff.L - 1;
            }
        }

        splitsUntilNow += 1;
        splitsUntilNow %= MOD;
        printf("%lld\n", splitsUntilNow);
    }

    return 0;
}