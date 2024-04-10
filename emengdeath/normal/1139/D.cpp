#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 1;
const int mod  = 1e9 + 7;
long long f[N];
int a[N], d[N], mu[N];
int m;
long long ans;
long long calc(long long x, long long y)
{
    x %= mod;
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
long long ni(long long x)
{
    return calc(x, mod - 2);
}
long long work(int x, int y)
{
    long long s = 0;
    for (int i = 1; (long long) i * i <= y;  i ++)
        if (y % i == 0)
        {
            s += (long long)mu[i] * (x / i) % mod;
            if (i * i != y)
                s += (long long)mu[y / i] * (x / (y / i)) % mod;
            s %= mod;
        }
    return s;
}
int main()
{
    mu[1] = 1;
    for (int i = 2; i < N ; i ++)
    {
        if (!a[i])
            d[a[i] = ++d[0]] = i, mu[i] = mod-1;
        for (int j = 1; j <= a[i] && (long long)d[j] * i < N; j ++){
            a[d[j] * i] = j;
            if (j == a[i])
                mu[d[j] * i] = 0;
            else
                mu[d[j] * i] = mod - mu[i];
        }
    }
    cin >> m ;
    for (int x = m ; x >= 1; x  --) {
        (f[x] += ni(m)) %= mod;
        if (x == 1) continue;
        long long q = (m / x) * ni(m) % mod;
        f[x] = f[x] * ni((1 - q + mod) % mod) % mod;
        for (int i = 1; (long long) i * i <= x ; i ++)
            if (x % i == 0)
            {
                q = work(m / i, x / i) * ni(m) % mod;
                (f[i] += f[x] * q % mod) %= mod;
                if (x / i != i && i != 1)
                {
                    i = x / i;
                    q = work(m / i, x / i) * ni(m) % mod;
                    (f[i] += f[x] * q % mod) %= mod;
                    i = x / i;
                }
            }
    }
    for (int i = 1; i <= m ; i ++)
        ans += f[i];
    cout << ans % mod;
    return 0;
}