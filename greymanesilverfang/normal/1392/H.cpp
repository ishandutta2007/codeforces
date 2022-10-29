#include<cstdio>
const int MAX = 4e6+5, MOD = 998244353;
int inv[MAX];

int addmod(int x) {
    return x < MOD ? x : x - MOD;
}
int add(int x, int y) {
    return addmod(x + y);
}
int mul(int x, int y) {
    return 1LL * x * y % MOD;
}

void precalc() {
    inv[1] = 1;
    for (int i = 2; i < MAX; ++i)
        inv[i] = MOD - mul(MOD / i, inv[MOD % i]);
}

int main() {
    precalc();
    int n, m; scanf("%d%d", &n, &m);
    int cur = 1, res = 0, sum = 0;
    for (int i = 1; i <= n; ++i)
        cur = mul(cur, mul(i, inv[m + i])) + 1;
    for (int i = 1; i <= m; ++i)
        cur = mul(cur, i);
    for (int i = 1; i <= n; ++i) {
        cur = mul(cur, mul(m + i, inv[i]));
        res = mul(add(sum, cur), inv[i]);
        sum = add(sum, mul(res, m));
    }
    for (int i = 1; i <= m - 1; ++i)
        res = mul(res, inv[n + i]);
    printf("%d\n", res);
}