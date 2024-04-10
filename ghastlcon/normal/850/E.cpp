#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 20
#define MOD 1000000007
using namespace std;

int a[1 << N | 1];
int c[1 << N | 1], k[N + 1];

void FWT(int *f, int n, int w)
{
    int i, j, l;
    int k;

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
            {
                k = f[i + j];
                f[i + j] = (k + f[i + j + (1 << l)]) % MOD;
                f[i + j + (1 << l)] = (k - f[i + j + (1 << l)]) % MOD;
                if(w < 0)
                {
                    f[i + j] = (long long)f[i + j] * 500000004 % MOD;
                    f[i + j + (1 << l)] = (long long)f[i + j + (1 << l)] * 500000004 % MOD;
                }
            }

    return;
}

long long Scan(void)
{
    int c;

    while((c = getchar()) < '0' || c > '9')
        ;

    return c & 15;
}

int main(void)
{
    int n;
    int i, o;

    scanf("%d", &n);
    for(i = 0; i < (1 << n); i ++)
        a[i] = Scan();

    for(i = 1; i < (1 << n); i ++)
        c[i] = c[i & (i - 1)] + 1;
    for(i = k[0] = 1; i <= n; i ++)
        k[i] = (k[i - 1] + k[i - 1]) % MOD;

    FWT(a, 1 << n, 1);
    for(i = 0; i < (1 << n); i ++)
        a[i] = (long long)a[i] * a[i] % MOD;
    FWT(a, 1 << n, -1);

    for(i = o = 0; i < (1 << n); i ++)
        o = (o + (long long)a[i] * k[n - c[i]] % MOD) % MOD;
    printf("%lld\n", (long long)o * 3 % MOD);

    return 0;
}