#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 60020
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

    void Init(void)
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
        return (long long)f[n] * g[m] % MOD * g[n - m] % MOD;
    }
}

int x[N], y[N];

__attribute__((always_inline)) int Mod(int x)
{
    return x + ((x >> 31) & MOD);
}

void Karatsuba(int *x, int *y, int *z, int n)
{
    int k, i, j;

    if(n <= 8)
    {
        for(i = 0; i < n + n - 1; i ++)
            z[i] = 0;
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++)
                z[i + j] = Mod(z[i + j] + (long long)x[i] * y[j] % MOD - MOD);

        return;
    }

    k = n >> 1;
    Karatsuba(x, y, z, k);
    z[n - 1] = 0;
    Karatsuba(x + k, y + k, z + n, k);

    int f[k];
    int g[k];
    int h[n];
    // memset(f, 0, sizeof(int) * (n - k));
    // memset(g, 0, sizeof(int) * (m - k));
    // memset(h, 0, sizeof(int) * (n - k + m - k - 1));
    for(i = 0; i < k; i ++)
    {
        f[i] = Mod(x[i] + x[i + k] - MOD);
        g[i] = Mod(y[i] + y[i + k] - MOD);
    }

    Karatsuba(f, g, h, k);
    // printf("len %d %d %d\n",n-k,m-k,n-k+m-k-1);
    // printf("f: ");for(i=0;i<n-k;i++)cout<<f[i]<<' ';cout<<endl;
    // printf("g: ");for(i=0;i<m-k;i++)cout<<g[i]<<' ';cout<<endl;
    // printf("h: ");for(i=0;i<n-k+m-k-1;i++)cout<<h[i]<<' ';cout<<endl;
    // printf("z: ");for(i=0;i<n+m-1;i++)cout<<h[i]<<' ';cout<<endl;
    for(i = 0; i < n - 1; i ++)
        h[i] = Mod(Mod(h[i] - z[i]) - z[i + n]);

    for(i = 0; i < n - 1; i ++)
        z[i + k] = Mod(z[i + k] + h[i] - MOD);

    // delete[] f;
    // delete[] g;
    // delete[] h;
    return;
}

void Transform(int *x, int *y, int n, int l)
{
    int *t, *z;
    int m, i;

    for(m = 1; m < n; m <<= 1)
        ;
    t = new int[m];
    z = new int[m << 1];
    for(i = 0; i < m; i ++)
        t[i] = (long long)x[i] * Comb::Power(2, l * i) % MOD;
    Karatsuba(t, y, z, m);

    for(i = 0; i < m; i ++)
        x[i] = z[i];

    delete[] t;
    delete[] z;
    return;
}

int main(void)
{
    long long n;
    int m;
    int i, o;

    Comb::Init();
    cin >> n >> m;
    if(n > m)
    {
        cout << 0 << endl;

        return 0;
    }

    x[0] = 1;
    for(i = 1; i <= m; i ++)
        y[i] = Comb::g[i];

    for(i = 0; n; n >>= 1, i ++)
    {
        if(n & 1)
            Transform(x, y, m + 1, 1 << i);
        Transform(y, y, m + 1, 1 << i);
        // cout<<n<<' '<<endl;
    }
    // for(int i=0;i<=m;i++)cout<<((long long)x[i]*Comb::f[i]%MOD+MOD)%MOD<<' ';cout<<endl;

    for(i = o = 0; i <= m; i ++)
        o = Mod(o + (long long)x[i] * Comb::f[i] % MOD * Comb::C(m, i) % MOD - MOD);
    printf("%d\n", o);

    return 0;
}