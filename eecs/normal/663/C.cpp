#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, u[maxn], v[maxn], fa[maxn], vis[maxn], c[maxn], w[maxn], mark[maxn];
char col[100010][2];
vector<int> G[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %s", &u[i], &v[i], col[i]);
    }
    auto solve = [&](char ch) {
        vector<int> V;
        iota(fa + 1, fa + n + 1, 1);
        for (int i = 1; i <= m; i++) {
            if (col[i][0] == ch) fa[find(u[i])] = find(v[i]);
        }
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= n; i++) {
            w[find(i)]++, G[i].clear();
        }
        for (int i = 1; i <= m; i++) if (col[i][0] ^ ch) {
            int x = find(u[i]), y = find(v[i]);
            if (x == y) return vector<int>(n + 1);
            G[x].push_back(y), G[y].push_back(x);
        }
        memset(vis, 0, sizeof(vis));
        memset(mark, 0, sizeof(mark));
        for (int i = 1; i <= n; i++) if (i == find(i) && !vis[i]) {
            int all = 0, num = 0;
            vector<int> foo;
            bool flag = 1;
            function<void(int)> dfs = [&](int v) {
                foo.push_back(v), all += w[v], vis[v] = 1;
                if (c[v]) num += w[v];
                for (int u : G[v]) {
                    if (!vis[u]) c[u] = c[v] ^ 1, dfs(u);
                    else if (c[u] == c[v]) flag = 0;
                }
            };
            dfs(i);
            if (!flag) return vector<int>(n + 1);
            for (int j : foo) {
                if (num > all - num && !c[j]) mark[j] = 1;
                if (num <= all - num && c[j]) mark[j] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (mark[find(i)]) V.push_back(i);
        }
        return V;
    };
    auto V1 = solve('B'), V2 = solve('R');
    if (V1.size() > V2.size()) swap(V1, V2);
    if (V1.size() > n) puts("-1"), exit(0);
    printf("%d\n", V1.size());
    for (int x : V1) printf("%d ", x);
    return 0;
}