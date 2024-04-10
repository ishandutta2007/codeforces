#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 100020
#define MOD 1000000007
using namespace std;

namespace Sieve
{
    int p[N], c;
    bool u[N];
    int f[N];

    void Sieve(void)
    {
        int i, j;

        f[1] = 1;
        for(i = 2; i < N; i ++)
        {
            if(!u[i])
            {
                p[c ++] = i;
                f[i] = -1;
            }

            for(j = 0; j < c && i * p[j] < N; j ++)
            {
                u[i * p[j]] = true;
                if(!(i % p[j]))
                    break;
                f[i * p[j]] = -f[i];
            }
        }

        return;
    }
}

int f[N];
vector<int> k[N];

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

int Calc(int n, int x, int y)
{
    int i, o;

    for(i = o = 0; i < (signed)k[x / y].size(); i ++)
        o += Sieve::f[k[x / y][i]] * (n / y / k[x / y][i]);
    // printf("<= %d, gcd(%d,%d)=%d : %d\n", n, x, y, y, o);

    return (long long)o * f[y] % MOD;
}

int main(void)
{
    int n;
    int i, j, o;

    cin >> n;
    for(i = 1; i <= n; i ++)
        for(j = i; j <= n; j += i)
            k[j].push_back(i);
    Sieve::Sieve();

    f[1] = 1;
    for(i = 2; i <= n; i ++)
    {
        for(j = 0; j < (signed)k[i].size() - 1; j ++)
            f[i] = (f[i] + Calc(n, i, k[i][j])) % MOD;
        f[i] = (long long)(f[i] + n) * Power(n - n / i, MOD - 2) % MOD;
    }
    // for(i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;

    for(i = 1, o = 0; i <= n; i ++)
        o = (o + f[i]) % MOD;
    cout << (long long)o * Power(n, MOD - 2) % MOD << endl;

    return 0;
}