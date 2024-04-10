#include <bits/stdc++.h>

const int N = 100;
const int MOD = 1e9 + 7;

void update(int& x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

int n, leaf, dp[N][5], val[N], res[N], coef[N];
std::vector<int> tree[N];

void dfs(int x, int p, int u)
{
    memset(dp[u], 0, sizeof(dp[u]));
    dp[u][0] = (MOD - n + MOD - 1LL * tree[u].size() * x % MOD) % MOD;
    dp[u][2] = 1;
    int tmp[] = {1, 1, 1};
    int x2 = MOD - 1LL * x * x % MOD;
    for (int v : tree[u]) {
        if (v == p || v == leaf) {
            continue;
        }
        dfs(x, u, v);
        int new_dp[] = {0, 0, 0, 0};
        for (int cnt = 0; cnt < 2; ++ cnt) {
            for (int son_cnt = 0; cnt + son_cnt < 2; ++ son_cnt) {
                int sum = cnt + son_cnt;
                update(new_dp[0 | sum], 1LL * dp[u][0 | cnt] * dp[v][0 | son_cnt] % MOD);
                update(new_dp[2 | sum], 1LL * dp[u][2 | cnt] * dp[v][0 | son_cnt] % MOD);
                update(new_dp[0 | sum], 1LL * dp[u][2 | cnt] * dp[v][2 | son_cnt] % MOD * x2 % MOD);
            }
        }
        memcpy(dp[u], new_dp, sizeof(new_dp));
        tmp[2] = (1LL * tmp[2] * dp[v][0] + 2LL * tmp[1] * dp[v][4] % MOD * (MOD - x)) % MOD;
        tmp[1] = (1LL * tmp[1] * dp[v][0] + 1LL * tmp[0] * dp[v][4] % MOD * (MOD - x)) % MOD;
        tmp[0] = 1LL * tmp[0] * dp[v][0] % MOD;
    }
    dp[u][4] = tmp[1];
    update(dp[u][0 | 1], tmp[2]);
}

int inv(int a)
{
    return a == 1 ? 1 : 1LL * (MOD - MOD / a) * inv(MOD % a) % MOD;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("D.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0, a, b; i < n - 1; ++ i) {
        scanf("%d%d", &a, &b);
        a --;
        b --;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    leaf = 1;
    while (tree[leaf].size() != 1) {
        leaf ++;
    }
    for (int x = 0; x < n; ++ x) {
        dfs((x + MOD - 1) % MOD, -1, 0);
        val[x] = (dp[0][0] + dp[0][1]) % MOD;
        if (n - 1 & 1) {
            val[x] = MOD - val[x];
        }
    }
    for (int i = 0; i < n; ++ i) {
        memset(coef, 0, sizeof(coef));
        coef[0] = val[i];
        int deg = 0;
        int mul = 1;
        for (int j = 0; j < n; ++ j) {
            if (i != j) {
                mul = 1LL * mul * inv((i + MOD - j) % MOD) % MOD;
                for (int k = deg + 1; k > 0; -- k) {
                    coef[k] = (coef[k - 1] + 1LL * coef[k] * (MOD - j)) % MOD;
                }
                deg ++;
                coef[0] = 1LL * coef[0] * (MOD - j) % MOD;
            }
        }
        for (int i = 0; i < n; ++ i) {
            update(res[i], 1LL * mul * coef[i] % MOD);
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%d\n", res[i]);
    }
}