#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 5020
#define MOD 1000000007
using namespace std;

int f[N][N], g[N];

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

int main(void)
{
    int n, k;
    int i, j, o;

    for(i = f[0][0] = 1; i < N; i ++)
        for(j = 1; j <= i; j ++)
            f[i][j] = (f[i - 1][j - 1] + (long long)f[i - 1][j] * j % MOD) % MOD;

    cin >> n >> k;
    for(i = g[0] = 1; i <= min(k, n); i ++)
        g[i] = (long long)g[i - 1] * (n - i + 1) % MOD;
    for(i = o = 0; i <= min(k, n); i ++)
        o = (o + (long long)f[k][i] * g[i] % MOD * Power(2, n - i)) % MOD;
    cout << o << endl;

    return 0;
}