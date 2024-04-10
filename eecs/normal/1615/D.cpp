#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, u[maxn], v[maxn], w[maxn], d[maxn];
bool vis[maxn];
vector<array<int, 2>> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %d %d", &u[i], &v[i], &w[i]);
            if (~w[i]) {
                G[u[i]].push_back({v[i], __builtin_parity(w[i])});
                G[v[i]].push_back({u[i], __builtin_parity(w[i])});
            }
        }
        while (m--) {
            int a, b, p;
            scanf("%d %d %d", &a, &b, &p);
            G[a].push_back({b, p});
            G[b].push_back({a, p});
        }
        fill(vis + 1, vis + n + 1, 0);
        bool flag = 1;
        function<void(int)> dfs = [&](int u) {
            vis[u] = 1;
            for (auto &e : G[u]) {
                if (!vis[e[0]]) {
                    d[e[0]] = d[u] ^ e[1], dfs(e[0]);
                } else if (d[e[0]] != (d[u] ^ e[1])) {
                    flag = 0;
                }
            }
        };
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) d[i] = 0, dfs(i);
        }
        if (!flag) {
            puts("NO");
        } else {
            puts("YES");
            for (int i = 1; i < n; i++) {
                if (!~w[i]) w[i] = d[u[i]] ^ d[v[i]];
                printf("%d %d %d\n", u[i], v[i], w[i]);
            }
        }
    }
    return 0;
}