#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007LL;

llong FastPow(llong k, llong p)
{
    if (p == 0)
        return 1LL;

    llong P = FastPow(k, p / 2LL);

    P = (P * P) % MOD;

    if (p % 2LL == 1LL)
    {
        P = (P * k) % MOD;
    }

    return P;
}

llong Inv(llong x)
{
    return FastPow(x, MOD - 2LL);
}

int n;
llong a[21];
llong probs[21][21];

inline bool bit(int k, int b)
{
    return ( k & (1<<b) ) > 0;
}

string tob(int k)
{
    if (k == 0)
        return "0";

    string s;

    while(k > 0)
    {
        s.push_back(k%2 + '0');
        k /= 2;
    }

    reverse(s.begin(), s.end());

    return s;
}

llong F[100111];
llong caseProbPrec[15][100111];

int main()
{
    int i, j, in, ja;

    scanf("%d", &n);

    for (i=0;i<n;i++)
    {
        scanf("%lld", &a[i]);
    }

    llong ans = 0LL;
    for (int iter = 0; iter < n; iter++)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                probs[i][j] = (a[i] * Inv(a[i] + a[j])) % MOD;
            }
        }

        for (i=0;i<n-1;i++)
        {
            for (int sub = 0; sub < (1<<(n-1)); sub++)
            {
                caseProbPrec[i][sub] = probs[i][n-1];
                for (j=0;j<n-1;j++)
                {
                    if (bit(sub, j))
                    {
                        caseProbPrec[i][sub] *= probs[i][j];
                        caseProbPrec[i][sub] %= MOD;
                    }
                }
            }
        }

        F[0] = 1LL;
        for (int mask = 1; mask < (1<<(n-1)); mask++)
        {
            F[mask] = 1LL;
            for (int sub = ((mask - 1) & mask); sub >= 0; sub = (sub - 1) & mask)
            {
                llong caseProb = F[sub];
                for (i=0;i<n-1;i++)
                {
                    if (bit(mask, i) && !bit(sub, i))
                    {
                        caseProb *= caseProbPrec[i][sub];
                        caseProb %= MOD;
                    }
                }
                //printf("Case prob %lld\n", caseProb);

                F[mask] -= caseProb;
                if (F[mask] < 0)
                    F[mask] += MOD;

                if (sub == 0)
                    break;
            }
        }

        ans += F[ (1<<(n-1)) - 1 ];
        if (ans >= MOD)
            ans -= MOD;

        swap(a[iter], a[n-1]);
    }

    printf("%lld\n", ans);

    return 0;
}