#include <cstdio>
#include <algorithm>
const int M = 44, N = 300005, MOD = 998244353;
int f[N], inv[N], finv[N], l[N], r[N], d[N], a[M], b[M], vis[N], dp[N][M];

int addmod(int x) { return x < MOD ? x : x - MOD; }
int add(int x, int y) { return addmod(x + y); }
int submod(int x) { return x < 0 ? x + MOD : x; }
int sub(int x, int y) { return submod(x - y); }
int mul(int x, int y) { return 1LL * x * y % MOD; }

void precalc(int n)
{
    f[0] = finv[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        inv[i] = i == 1 ? 1 : MOD - mul(MOD / i, inv[MOD % i]);
        f[i] = mul(f[i - 1], i);
        finv[i] = mul(finv[i - 1], inv[i]);
    }
}

int choose(int m, int n)
{
    if (m < n || n < 0)
        return 0;
    return mul(f[m], mul(finv[n], finv[m - n]));
}

void update(int id, int &t, int &c, int &lft, int &rgt)
{
    if (vis[id] < t)
    {
        vis[id] = t;
        ++c;
    }
    lft = std::max(lft, l[id]);
    rgt = std::min(rgt, r[id]);
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    precalc(n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &l[i], &r[i]);
        ++d[l[i]];
        --d[r[i] + 1];
    }
    for (int cnt = 0, i = 1; i <= n; ++i)
    {
        cnt += d[i];
        for (int j = 0; j <= m * 2; ++j)
            dp[i][j] = add(dp[i - 1][j], choose(cnt - j, i - j));
    }
    for (int i = 1; i <= m; ++i)
        scanf("%d%d", &a[i], &b[i]);
    int res = 0;
    for (int i = 0; i < 1 << m; ++i)
    {
        int cnt = 0, l = 1, r = n;
        for (int j = 1; j <= m; ++j)
            if (i >> j - 1 & 1)
            {
                update(a[j], i, cnt, l, r);
                update(b[j], i, cnt, l, r);
            }
        if (l > r)
            continue;
        int sum = sub(dp[r][cnt], dp[l - 1][cnt]);
        if (__builtin_popcount(i) & 1)
            res = sub(res, sum);
        else 
            res = add(res, sum);
    }
    printf("%d\n", res);
}