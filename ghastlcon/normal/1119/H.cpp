#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 131073
#define M 3
#define MOD 998244353
using namespace std;

int f[1 << M][N];
int o[N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

int Power(int x, int y)
{
    int o;

    for(o = 1; y; y >>= 1)
    {
        if(y & 1)
            o = (long long)o * x % MOD;
        x = (long long)x * x % MOD;
    }

    return o;
}

void FWT(int *f, int n, int w)
{
    int i, j, l;
    int k;

    for(l = 0; l < n; l ++)
        for(i = 0; i < (1 << n); i += 2 << l)
            for(j = 0; j < (1 << l); j ++)
            {
                k = f[i + j];
                f[i + j] = Mod(k + f[i + j + (1 << l)] - MOD);
                f[i + j + (1 << l)] = Mod(k - f[i + j + (1 << l)]);
            }
    if(w == -1)
        for(i = 0; i < (1 << n); i ++)
            f[i] = (long long)f[i] * Mod(-((MOD - 1) >> n)) % MOD;

    return;
}

int main(void)
{
    int n, m, x[M], w[M];
    int i, j, k, t, s;

    scanf("%d %d", &n, &m);
    for(i = 0; i < M; i ++)
        scanf("%d", &x[i]);
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < M; j ++)
            scanf("%d", &w[j]);
        for(j = 0; j < (1 << M); j ++)
        {
            for(k = t = 0; k < M; k ++)
                if(j & (1 << k))
                    t ^= w[k];
            f[j][t] ++;
        }
    }
    for(i = 0; i < (1 << M); i ++)
        FWT(f[i], m, 1);
    // for(i=0;i<(1<<M);i++){for(j=0;j<(1<<m);j++)cout<<f[i][j]<<' ';cout<<endl;}

    for(i = 0; i < (1 << m); i ++)
    {
        // printf("at pos %d:\n", i);
        o[i] = 1;
        for(j = 0; j < (1 << M); j ++)
        {
            for(k = t = 0; k < (1 << M); k ++)
                t = Mod((t + (__builtin_parity(j & k) ? -1 : 1) * f[k][i]) % MOD);
            for(k = s = 0; k < M; k ++)
                s = Mod((s + (j & (1 << k) ? -1 : 1) * x[k]) % MOD);
            // cout<<t<<endl;
            o[i] = (long long)o[i] * Power(s, (long long)t * Mod(-((MOD - 1) >> M)) % MOD) % MOD;
                // printf("%c%c", __builtin_parity(j & k) ? '-' : '+', k + 'a');
            // printf("=%d\n", f[j][i]);
        }
    }
    // for(i = 0; i < (1 << m); i ++)
    // {
    //     t = Mod(((long long)n + f[i] + g[i] + h[i]) % MOD * Mod(-((MOD - 1) >> 2)) % MOD);
    //     u = Mod(((long long)n + f[i] - g[i] - h[i]) % MOD * Mod(-((MOD - 1) >> 2)) % MOD);
    //     v = Mod(((long long)n - f[i] + g[i] - h[i]) % MOD * Mod(-((MOD - 1) >> 2)) % MOD);
    //     w = Mod(((long long)n - f[i] - g[i] + h[i]) % MOD * Mod(-((MOD - 1) >> 2)) % MOD);
    //     // cout<<t<<' '<<u<<' '<<v<<' '<<w<<endl;
    //     o[i] = 1;
    //     o[i] = (long long)o[i] * Power(((long long)x + y + z) % MOD, t) % MOD;
    //     o[i] = (long long)o[i] * Power(((long long)x + y - z) % MOD, u) % MOD;
    //     o[i] = (long long)o[i] * Power(((long long)x - y + z) % MOD, v) % MOD;
    //     o[i] = (long long)o[i] * Power(((long long)x - y - z) % MOD, w) % MOD;
    //     o[i] = Mod(o[i]);
    // }

    FWT(o, m, -1);
    for(i = 0; i < (1 << m); i ++)
        printf("%d ", o[i]);
    printf("\n");

    return 0;
}