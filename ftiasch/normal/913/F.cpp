#include <cstdio>

const int N = 2001;
const int MOD = 998244353;

int inv(int a)
{
    return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int powp[N], powq[N], coef[N][N], one[N], ans[N];

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("F.in", "r", stdin);
#endif
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int p = 1LL * a * inv(b) % MOD;
    int q = 1 + (MOD - p);
    powp[0] = powq[0] = coef[0][0] = 1;
    for (int i = 1; i <= n; ++ i) {
        powp[i] = 1LL * powp[i - 1] * p % MOD;
        powq[i] = 1LL * powq[i - 1] * q % MOD;
        for (int j = 0; j < i; ++ j) {
            update(coef[i][j],     1LL * coef[i - 1][j] * powp[j] % MOD);
            update(coef[i][j + 1], 1LL * coef[i - 1][j] * powq[i - 1 - j] % MOD);
        }
        one[i] = 1;
        for (int j = 1; j < i; ++ j) {
            update(one[i], MOD - 1LL * one[j] * coef[i][j] % MOD);
        }
        int sum = 1LL * one[i] * (i * (i - 1) / 2) % MOD;
        for (int j = 1; j < i; ++ j) {
            update(sum, 1LL * one[j] * coef[i][j] % MOD * (1LL * ans[j] + ans[i - j] + i * (i - 1) / 2 - (i - j) * (i - j - 1) / 2) % MOD);
        }
        ans[i] = i == 1 ? 0 : 1LL * sum * inv((1 + MOD - one[i]) % MOD) % MOD;
    }
    printf("%d\n", ans[n]);
}