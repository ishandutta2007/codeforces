#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long llong;

llong M;
int n;

llong FastPow(llong k, llong p)
{
    if (p == 0)
        return 1LL;

    llong P = FastPow(k, p/2LL);

    P = (P * P) % M;

    if (p % 2 == 1)
        P = (P * k) % M;

    return P;
}

llong Inv(llong k)
{
    return FastPow(k, M - 2);
}

llong fact[511];
llong cMem[511][511];
llong G[511];

void prec()
{
    int i;

    fact[0] = 1LL;
    for (i=1;i<=500;i++)
    {
        fact[i] = (fact[i-1] * (llong)i) % M;
    }

    memset(cMem, -1, sizeof(cMem));
    memset(G, -1, sizeof(G));
}

llong C(llong N, llong K)
{
    if (cMem[N][K] != -1)
        return cMem[N][K];

    llong top = fact[N];
    llong bot = (Inv(fact[K]) * Inv(fact[N - K])) % M;

    cMem[N][K] = (top * bot) % M;
    return cMem[N][K];
}

llong computeG(int k)
{
    if (G[k] != -1)
        return G[k];

    int i;

    G[k] = 0;
    for (i=1;i<=k;i++)
    {
        int lft = i - 1, rt = k - i;

        G[k] += C(k - 1, lft);
        if (G[k] >= M)
            G[k] -= M;
    }

    return G[k];
}

llong F[511][511];

int main()
{
    int i, j, in;

    scanf("%d %lld", &n, &M);
    prec();

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=i;j++)
        {
            if (i == j)
                F[i][j] = computeG(i);

            for (in=i;in>=3;in--)
            {
                int segLen = i - in + 1;
                if (segLen > j)
                    break;

                llong addOn = F[in - 2][j - segLen] * computeG(segLen);
                addOn %= M;
                addOn *= C(j, segLen);
                addOn %= M;

                F[i][j] += addOn;
                if (F[i][j] >= M)
                    F[i][j] -= M;
            }
        }
    }

    llong ans = 0;
    for (i=1;i<=n;i++)
    {
        ans += F[n][i];
    }
    ans %= M;

    printf("%lld\n", ans);

    return 0;
}