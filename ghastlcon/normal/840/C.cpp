#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 320
#define MOD 1000000007
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
        return m < 0 || m > n ? 0 : (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
    }
}

int a[N], b[N];
int f[N][N];

inline int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

int main(void)
{
    int n;
    int i, j, k, s, c;

    Comb::InitComb();
    cin >> n;
    for(i = 0; i < n; i ++)
    {
        cin >> a[i];
        for(j = 2, k = a[i], s = 1; j * j <= k; j ++)
        {
            for(c = 0; !(k % j); k /= j, c ^= 1)
                ;
            if(c)
                s *= j;
        }
        a[i] = s * k;
    }

    sort(a, a + n);
    for(i = c = 0; i < n; i = j)
    {
        for(j = i; j < n && a[j] == a[i]; j ++)
            ;
        b[++ c] = j - i;
    }
    // for(i=0;i<c;i++)cout<<b[i]<<' ';cout<<endl;

    f[0][0] = 1;
    for(i = 1; i <= c; i ++)
        for(j = 0; j <= n; j ++)
            for(k = 0; k < b[i]; k ++)
                if(b[i] - k <= j)
                {
                    if(k & 1)
                        f[i][j] = Mod(f[i][j] - (long long)f[i - 1][j - (b[i] - k)] * Comb::C(b[i] - 1, k) % MOD * Comb::g[b[i] - k] % MOD      );
                    else
                        f[i][j] = Mod(f[i][j] + (long long)f[i - 1][j - (b[i] - k)] * Comb::C(b[i] - 1, k) % MOD * Comb::g[b[i] - k] % MOD - MOD);
                }
    // for(i=0;i<=n;i++)cout<<f[c][i]<<' ';cout<<endl;

    for(i = s = 0; i <= n; i ++)
        s = Mod(s + (long long)Comb::f[i] * f[c][i] % MOD - MOD);
    for(i = 1; i <= c; i ++)
        s = (long long)s * Comb::f[b[i]] % MOD;
    cout << s << endl;

    return 0;
}