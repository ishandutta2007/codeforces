#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, q, mark[maxn], dep[maxn], fa[maxn], vis[maxn];
vector<int> G[maxn], ans[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        dep[v] = dep[fa[v]] + 1, vis[v] = 1;
        for (int u : G[v]) if (!vis[u]) {
            fa[u] = v, dfs(u);
        }
    };
    dfs(1), scanf("%d", &q);
    for (int i = 1, u, v; i <= q; i++) {
        scanf("%d %d", &u, &v);
        vector<int> V;
        while (u ^ v) {
            if (dep[u] > dep[v]) {
                ans[i].push_back(u);
                mark[u] ^= 1, u = fa[u];
            } else {
                V.push_back(v);
                mark[v] ^= 1, v = fa[v];
            }
        }
        ans[i].push_back(u);
        reverse(V.begin(), V.end());
        for (int x : V) ans[i].push_back(x);
    }
    bool flag = 1;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) { flag = 0; break; }
    }
    if (flag) {
        puts("YES");
        for (int i = 1; i <= q; i++) {
            printf("%d\n", ans[i].size());
            for (int x : ans[i]) printf("%d ", x);
            putchar('\n');
        }
    } else {
        puts("NO");
        int ans = 0;
        function<bool(int)> dfs = [&](int v) {
            int cnt = 0;
            for (int u : G[v]) if (v == fa[u]) {
                cnt += dfs(u);
            }
            ans += (cnt + 1) / 2;
            if (mark[v]) {
                if (cnt % 2) ans--;
                return 1;
            } else {
                return 0;
            }
        };
        ans += dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}