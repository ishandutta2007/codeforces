#include <cstdio>
using namespace std;
int n, a[200005];
long long fac[500005], inv[500005];
const long long mod = 1e9 + 7;
long long qpow(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
long long C(long long x, long long y)
{
    if (x < y)
        return 0;
    // printf("ans += C(%d,%d)\n", x, y);
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
int main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 500000; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = qpow(fac[i], mod - 2);
    }
    scanf("%d", &n);
    long long ans = 0;
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
        ans += C(a[i] + i, i + 1);
    }
    printf("%lld\n", ans % mod);
}