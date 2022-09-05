#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, X, c[maxn];
long long dist[maxn];
vector<pair<int, int>> G[maxn];
vector<int> son[maxn];
vector<vector<short>> _f, _g, f[maxn], g[maxn];

void chk(short &x, short y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d", &n, &X);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    int s = accumulate(c + 1, c + n + 1, 0);
    function<void(int, int)> dfs = [&](int v, int fa) {
        son[v].push_back(v);
        for (auto e : G[v]) if (e.first ^ fa) {
            dist[e.first] = dist[v] + e.second, dfs(e.first, v);
            for (int x : son[e.first]) son[v].push_back(x);
        }
        f[v] = g[v] = vector<vector<short>>(son[v].size() + 1, vector<short>(son[v].size(), n + 1));
        f[v][1][0] = !c[v], g[v][0][0] = 0;
        vector<int> tmp(n + 1);
        for (int i = 0; i < son[v].size(); i++) {
            tmp[son[v][i]] = i;
        }
        int sz = 1;
        for (auto e : G[v]) if (e.first ^ fa) {
            int u = e.first;
            _f = _g = vector<vector<short>>(sz + son[u].size() + 1, vector<short>(sz + son[u].size(), n + 1));
            for (int j = 0; j <= sz; j++) {
                for (int _i = 0; _i <= min(s, (int)son[u].size()); _i++) {
                    short mn = n + 1;
                    for (int $ = 0; $ < son[u].size(); $++) {
                        if (dist[son[v][j]] < dist[son[u][$]]) mn = min(mn, f[u][_i][$]);
                    }
                    for (int i = 0; i <= min(s, sz); i++) {
                        chk(_f[i + _i][j], f[v][i][j] + mn);
                    }
                    mn = n + 1;
                    for (int $ = 0; $ < son[u].size(); $++) {
                        if (dist[son[v][j]] + dist[son[u][$]] - 2 * dist[v] <= X) mn = min(mn, g[u][_i][$]);
                    }
                    for (int i = 0; i <= min(s, sz); i++) {
                        chk(_f[i + _i][j], f[v][i][j] + mn);
                    }
                    mn = n + 1;
                    for (int $ = 0; $ < son[u].size(); $++) {
                        if (dist[son[v][j]] > dist[son[u][$]]) mn = min(mn, g[u][_i][$]);
                    }
                    for (int i = 0; i <= min(s, sz); i++) {
                        chk(_g[i + _i][j], g[v][i][j] + mn);
                    }
                    mn = n + 1;
                    for (int $ = 0; $ < son[u].size(); $++) {
                        if (dist[son[v][j]] + dist[son[u][$]] - 2 * dist[v] > X) mn = min(mn, f[u][_i][$]);
                    }
                    for (int i = 0; i <= min(s, sz); i++) {
                        chk(_g[i + _i][j], g[v][i][j] + mn);
                    }
                }
            }
            for (int $ = 0; $ < son[u].size(); $++) {
                int _j = tmp[son[u][$]];
                for (int i = 0; i <= min(s, sz); i++) {
                    short mn = n + 1;
                    for (int j = 0; j < sz; j++) {
                        if (dist[son[v][j]] >= dist[son[u][$]]) mn = min(mn, f[v][i][j]);
                    }
                    for (int _i = 0; _i <= min(s, (int)son[u].size()); _i++) {
                        chk(_f[i + _i][_j], mn + f[u][_i][$]);
                    }
                    mn = n + 1;
                    for (int j = 0; j < sz; j++) {
                        if (dist[son[v][j]] + dist[son[u][$]] - 2 * dist[v] > X) mn = min(mn, f[v][i][j]);
                    }
                    for (int _i = 0; _i <= min(s, (int)son[u].size()); _i++) {
                        chk(_g[i + _i][_j], mn + g[u][_i][$]);
                    }
                    mn = n + 1;
                    for (int j = 0; j < sz; j++) {
                        if (dist[son[v][j]] <= dist[son[u][$]]) mn = min(mn, g[v][i][j]);
                    }
                    for (int _i = 0; _i <= min(s, (int)son[u].size()); _i++) {
                        chk(_g[i + _i][_j], mn + g[u][_i][$]);
                    }
                    mn = n + 1;
                    for (int j = 0; j < sz; j++) {
                        if (dist[son[v][j]] + dist[son[u][$]] - 2 * dist[v] <= X) mn = min(mn, g[v][i][j]);
                    }
                    for (int _i = 0; _i <= min(s, (int)son[u].size()); _i++) {
                        chk(_f[i + _i][_j], mn + f[u][_i][$]);
                    }
                }
            }
            sz += son[u].size();
            for (int i = 0; i <= sz; i++) {
                for (int j = 0; j < sz; j++) f[v][i][j] = _f[i][j], g[v][i][j] = _g[i][j];
            }
        }
    };
    dfs(1, 0);
    int ans = n + 1;
    for (int i = 0; i < n; i++) {
        ans = min(ans, (int)f[1][s][i]);
    }
    printf("%d\n", ans > n ? -1 : ans);
    return 0;
}