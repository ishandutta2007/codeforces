#include <cstdio>
const int LIM = 1e5, MAX = LIM+1, MOD = 998244353, INV8 = 873463809;
long long cnt[MAX], dp[MAX];

int mul(long long x, long long y)
{
    return (x % MOD) * (y % MOD) % MOD;
}

int pow(int x, long long y)
{
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
            res = mul(res, x);
        x = mul(x, x);
        y /= 2;
    }
    return res;
}

int main()
{
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
    {
        int val, freq; scanf("%d%d", &val, &freq);
        cnt[val] += freq;
    }
    for (int i = LIM; i >= 1; --i)
    {
        long long size, sum, sqr;
        size = sum = sqr = 0;
        for (int j = i; j <= LIM; j += i)
        {
            size += cnt[j];
            sum += mul(cnt[j], j);
            sqr += mul(cnt[j], mul(j, j));
            dp[i] += MOD - dp[j] % MOD;
        }
        dp[i] += mul(mul(pow(2, size), INV8), mul(mul(sum, sum), size) + mul(sqr, size - 2));
    }
    printf("%lld\n", dp[1] % MOD);
}