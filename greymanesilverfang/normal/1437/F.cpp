#include <cstdio>
#include <algorithm>
const int N = 6000, MOD = 998244353;
int a[N], l[N], r[N], f[N], inv[N], finv[N], dp[N];

int mod(int x)
{
    return x < MOD ? x : x - MOD;
}

int mul(long long x, long long y)
{
    return x * y % MOD;
}

int solve()
{
    int n; scanf("%d", &n);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
    f[0] = finv[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = mul(f[i - 1], i);
        finv[i] = mul(finv[i - 1], inv[i]);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            if (a[j] * 2 <= a[i])
                l[i] = j;
        for (int j = n; j >= 1; --j)
            if (a[i] * 2 <= a[j])
                r[i] = j;
    }
    if (r[n - 1] != n)
        return 0;
    dp[n] = 1;
    for (int i = n - 1; i >= 1; --i)
        for (int j = r[i]; j <= n; ++j)
            dp[i] = mod(dp[i] + mul(dp[j], mul(f[n - l[i] - 2], finv[n - l[j] - 1])));
    // for (int i = 1; i <= n; ++i)
        // printf("dp[%d] = %d\n", i, dp[i]);
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = mod(res + mul(dp[i], mul(f[n - 1], finv[n - l[i] - 1])));
    return res;
}

int main()
{
    printf("%d\n", solve());
}