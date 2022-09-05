#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, rt, w[maxn], sz[maxn];
bool solved[maxn];
double f[maxn], g[maxn];
vector<array<int, 2>> G[maxn];
pair<double, int> ans{1e30, 0};

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w}), G[v].push_back({u, w});
    }
    function<void(int, int, int)> find_rt = [&](int u, int fa, int all) {
        sz[u] = 1;
        int mx = 0;
        for (auto &e : G[u]) if (!solved[e[0]] && e[0] ^ fa) {
            find_rt(e[0], u, all), sz[u] += sz[e[0]];
            mx = max(mx, sz[e[0]]);
        }
        if (max(mx, all - sz[u]) <= all / 2) rt = u;
    };
    auto calc = [&](int s) {
        function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
            f[u] = d * sqrt(d) * w[u], g[u] = sqrt(d) * w[u];
            for (auto &e : G[u]) if (e[0] ^ fa) {
                dfs(e[0], u, d + e[1]);
                f[u] += f[e[0]], g[u] += g[e[0]];
            }
        };
        dfs(s, 0, 0), ans = min(ans, {f[s], s});
    };
    function<void(int)> solve = [&](int x) {
        solved[x] = 1, calc(x);
        function<void(int, int)> dfs = [&](int u, int fa) {
            sz[u] = 1;
            for (auto &e : G[u]) if (!solved[e[0]] && e[0] ^ fa) {
                dfs(e[0], u), sz[u] += sz[e[0]];
            }
        };
        int y = 0;
        for (auto &e : G[x]) {
            if (!solved[e[0]] && (!y || g[e[0]] > g[y])) y = e[0];
        }
        if (y) find_rt(y, x, sz[y]), solve(rt);
    };
    find_rt(1, 0, n), solve(rt);
    printf("%d %.9f\n", ans.second, ans.first);
    return 0;
}