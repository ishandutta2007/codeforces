#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#define N 1000020
#define MOD 998244353
using namespace std;

int f[N];

int main(void)
{
    int n;
    int i, t;

    cin >> n;
    for(i = 2, t = 1; i <= n; i ++)
    {
        t = (long long)t * i % MOD;
        f[i] = (long long)i * (f[i - 1] + 1) % MOD;
    }
    cout << ((long long)n * t % MOD - f[n] + MOD) % MOD << endl;

    return 0;
}