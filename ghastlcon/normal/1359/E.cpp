#pragma GCC optimize("O3,inline,unroll-loops")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 500020
#define MOD 998244353
using namespace std;

namespace Comb
{
    int f[N], g[N];
 
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
 
    void InitComb(void)
    {
        int i;
 
        for(i = f[0] = 1; i < N; i ++)
            f[i] = (long long)f[i - 1] * i % MOD;
        g[N - 1] = Power(f[N - 1], MOD - 2);
        for(i = N - 2; i > -1; i --)
            g[i] = (long long)g[i + 1] * (i + 1) % MOD;
 
        return;
    }

    int C(int n, int m)
    {
        return n >= m ? (long long)f[n] * g[m] % MOD * g[n - m] % MOD : 0;
    }
}

int main(void)
{
    int n, k;
    int i, o;

    Comb::InitComb();
    cin >> n >> k;
    for(i = 1, o = 0; i <= n; i ++)
        o = (o + Comb::C(n / i - 1, k - 1)) % MOD;
    cout << o << endl;

    return 0;
}