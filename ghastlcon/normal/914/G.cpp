#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 17
#define MOD 1000000007
using namespace std;

namespace Final
{
    int f[1 << N | 1], g[1 << N | 1], h[1 << N | 1];
}

int c[N + 1][1 << N | 1], v[N + 1][1 << N | 1];
int f[1 << N | 1], g[1 << N | 1];
int k[1 << N | 1];

void FWT(int *f, int n, int w)
{
    int i, j, l;
    int k;

    for(l = 0; (1 << l) < n; l ++)
        for(i = 0; i < n; i += 1 << (l + 1))
            for(j = 0; j < (1 << l); j ++)
                if(w == 1 || w == -1)
                    f[i + j] = (f[i + j] + w * f[i + j + (1 << l)]) % MOD;
                else if(w == 2 || w == -2)
                    f[i + j + (1 << l)] = (f[i + j + (1 << l)] + (w < 0 ? -1 : 1) * f[i + j]) % MOD;
                else
                {
                    k = f[i + j];
                    f[i + j] = (f[i + j] + f[i + j + (1 << l)]) % MOD;
                    f[i + j + (1 << l)] = (k - f[i + j + (1 << l)]) % MOD;
                    if(w < 0)
                    {
                        f[i + j] = (long long)f[i + j] * 500000004 % MOD;
                        f[i + j + (1 << l)] = (long long)f[i + j + (1 << l)] * 500000004 % MOD;
                    }
                }

    return;
}

int main(void)
{
    int n, x;
    int i, j, t;

    for(i = 1; i < (1 << N); i ++)
        k[i] = k[i & (i - 1)] + 1;

    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &x);
        c[k[x]][x] ++;
    }
    for(i = 2, f[1] = 1; i < (1 << N); i ++)
        f[i] = (f[i - 1] + f[i - 2]) % MOD;

    // for(i=0;i<8;i++)cout<<c[k[i]][i]<<' ';cout<<endl;

    for(i = 0; i < (1 << N); i ++)
    {
        g[i] = c[k[i]][i];
        Final::g[i] = (long long)c[k[i]][i] * f[i] % MOD;
    }

    // for(i=0;i<8;i++)cout<<g[i]<<' ';cout<<endl;
    FWT(g, 1 << N, 3);
    for(i = 0; i < (1 << N); i ++)
        g[i] = (long long)g[i] * g[i] % MOD;
    FWT(g, 1 << N, -3);
    for(i = 0; i < (1 << N); i ++)
        Final::h[i] = (long long)g[i] * f[i] % MOD;
    // for(i=0;i<8;i++)cout<<g[i]<<' ';cout<<endl;

    for(i = 0; i <= N; i ++)
        FWT(c[i], 1 << N, 2);
    for(i = 1; i <= N; i ++)
        for(j = 0; j <= i; j ++)
            for(t = 0; t < (1 << N); t ++)
                v[i][t] = (v[i][t] + (long long)c[j][t] * c[i - j][t] % MOD) % MOD;
    for(i = 0; i <= N; i ++)
        FWT(v[i], 1 << N, -2);
    for(i = 0; i < (1 << N); i ++)
        Final::f[i] = (long long)v[k[i]][i] * f[i] % MOD;
    // for(i=0;i<8;i++)cout<<v[k[i]][i]<<' ';cout<<endl;

    // for(i=0;i<16;i++)cout<<Final::f[i]<<' ';cout<<endl;
    // for(i=0;i<16;i++)cout<<Final::g[i]<<' ';cout<<endl;
    // for(i=0;i<16;i++)cout<<Final::h[i]<<' ';cout<<endl;

    FWT(Final::f, 1 << N, 1);
    FWT(Final::g, 1 << N, 1);
    FWT(Final::h, 1 << N, 1);
    for(i = 0; i < (1 << N); i ++)
        Final::f[i] = (long long)Final::f[i] * Final::g[i] % MOD * Final::h[i] % MOD;
    FWT(Final::f, 1 << N, -1);

    for(i = t = 0; i < N; i ++)
        t = (t + Final::f[1 << i]) % MOD;
    printf("%d\n", (t + MOD) % MOD);

    return 0;
}