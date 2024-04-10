#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010, P = 998244353;
int n, ans, pw[maxn], sz[maxn], f[maxn][2];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = pw[0] = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] << 1) % P;
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        f[v][0] = 1, sz[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), sz[v] += sz[u];
            int a = f[v][0], b = f[v][1];
            f[v][0] = 1LL * a * (f[u][1] + pw[sz[u] - 1]) % P;
            f[v][1] = (1LL * a * f[u][0] + 1LL * b * pw[sz[u]]) % P;
        }
        ans = (ans + 1LL * f[v][1] * pw[n - sz[v] + 1]) % P;
    };
    dfs(1, 0), printf("%d\n", ans);
    return 0;
}