#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, sz[maxn], chk[maxn], fa[maxn];
vector<int> G[maxn];
vector<tuple<int, int, int>> ans;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        sz[v] = 1;
        int mx = 0;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), sz[v] += sz[u];
            mx = max(mx, sz[u]);
        }
        if (max(mx, n - sz[v]) * 2 <= n) chk[v] = 1;
    };
    dfs(1, 0);
    for (int i = 1; i <= n; i++) if (chk[i]) {
        for (int j : G[i]) if (!chk[j]) {
            vector<int> V = {i};
            function<void(int)> dfs = [&](int v) {
                for (int u : G[v]) if (u ^ fa[v]) fa[u] = v, dfs(u);
                V.push_back(v);
            };
            fa[j] = i, dfs(j);
            ans.emplace_back(i, j, V[1]);
            for (int k = 1; k < V.size() - 1; k++) {
                ans.emplace_back(V[k], fa[V[k]], V[k + 1]);
            }
            for (int i = (int)V.size() - 3; ~i; i--) {
                ans.emplace_back(V[i], V[i + 1], V[V.size() - 2]);
            }
        }
    }
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d %d\n", get<0>(p), get<1>(p), get<2>(p));
    }
    return 0;
}