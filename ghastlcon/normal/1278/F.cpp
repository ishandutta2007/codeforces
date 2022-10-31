#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 5020
#define MOD 998244353
using namespace std;

int f[N][N];

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

int P(int n, int m)
{
    int i, o;

    if(m < 0 || m > n)
        return 0;

    for(i = o = 1; i <= m; i ++)
        o = (long long)o * (n - i + 1) % MOD;

    return o;
}

int main(void)
{
    int n, m, k;
    int i, j, o;

    cin >> n >> m >> k;
    for(i = f[0][0] = 1; i <= k; i ++)
        for(j = 1; j <= i; j ++)
            f[i][j] = Mod(f[i - 1][j - 1] + (long long)f[i - 1][j] * j % MOD - MOD);
    // for(i=0;i<=k;i++)for(j=0;j<=i;j++)printf("%d%c",f[i][j]," \n"[j==i]);

    m = Power(m, MOD - 2);
    for(i = o = 0; i <= k; i ++)
        o = Mod(o + (long long)f[k][i] * P(n, i) % MOD * Power(m, i) % MOD - MOD);
    cout << o << endl;

    return 0;
}