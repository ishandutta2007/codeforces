#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 120
#define MOD 1000000007
using namespace std;

bool e[N][N];
int f[N][N], g[N];
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

int Gauss(int n)
{
    int i, j, k, o;
    int t, v;

    // for(i=0;i<n;i++){for(j=0;j<n;j++)cout<<f[i][j]<<' ';cout<<endl;}cout<<endl;

    for(i = 0, o = 1; i < n; i ++)
    {
        for(j = i; j < n && !f[j][i]; j ++)
            ;
        if(j >= n)
            return 0;
        if(i != j)
        {
            swap(f[i], f[j]);
            o = Mod(-o);
        }

        o = (long long)o * f[i][i] % MOD;
        t = Power(f[i][i], MOD - 2);
        for(j = i + 1; j < n; j ++)
        {
            v = (long long)f[j][i] * t % MOD;
            for(k = i; k < n; k ++)
                f[j][k] = Mod(f[j][k] - (long long)v * f[i][k] % MOD);
        }
    }

    return o;
}

int main(void)
{
    int n, u, v;
    int i, j, k;

    cin >> n;
    for(i = 1; i < n; i ++)
    {
        cin >> u >> v;
        e[u - 1][v - 1] = e[v - 1][u - 1] = true;
    }

    for(k = 0; k < n; k ++)
    {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++)
                if(i != j && e[i][j])
                {
                    f[i][i] = Mod(f[i][i] + k - MOD);
                    f[i][j] = Mod(f[i][j] - k      );
                }
                else if(i != j)
                {
                    f[i][i] = Mod(f[i][i] + 1 - MOD);
                    f[i][j] = Mod(f[i][j] - 1      );
                }
        v = Gauss(n - 1);
        // cout << v << endl;

        g[0] = 1;
        for(i = 0; i < n; i ++)
            if(i != k)
                for(j = n - 1; j > -1; j --)
                {
                    g[j] = (long long)g[j] * Mod(-i) % MOD;
                    if(j)
                        g[j] = Mod(g[j] + g[j - 1] - MOD);
                }
        // for(i=0;i<n;i++)cout<<g[i]<<' ';cout<<endl;
        for(i = 0; i < n; i ++)
            if(i != k)
                v = (long long)v * Power(Mod(k - i), MOD - 2) % MOD;
        for(i = 0; i < n; i ++)
            o[i] = Mod(o[i] + (long long)g[i] * v % MOD - MOD);
    }

    for(i = 0; i < n; i ++)
        printf("%d%c", o[i], " \n"[i == n - 1]);

    return 0;
}