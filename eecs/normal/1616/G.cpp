#include <bits/stdc++.h>
using namespace std;

const int maxn = 150010;
int T, n, m, ban[maxn];
bool vis[maxn][2];
vector<int> G[maxn], rG[maxn];
vector<pair<int, int>> V[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector<array<int, 2>> E;
        for (int i = 0; i <= n; i++) {
            G[i].clear(), rG[i].clear();
            if (i) E.push_back({0, i}), E.push_back({i, n + 1});
        }
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            E.push_back({u, v});
        }
        fill(ban, ban + n + 1, 1);
        for (auto &e : E) {
            if (e[0] == e[1] - 1) ban[e[0]] = 0;
        }
        int L = n + 1, R = 0;
        for (int i = 1; i <= n; i++) {
            if (ban[i]) L = min(L, i), R = i;
        }
        if (!R) {
            printf("%lld\n", 1LL * n * (n - 1) / 2); continue;
        }
        for (int i = 1; i <= n; i++) {
            ban[i] += ban[i - 1];
        }
        for (auto &e : E) if (e[0] < e[1] - 1 && ban[e[0]] == ban[e[1] - 2]) {
            G[e[0]].push_back({e[1] - 1}), rG[e[1] - 1].push_back(e[0]);
        }
        memset(vis, 0, sizeof(vis));
        function<void(int, int)> dfs1 = [&](int u, int o) {
            if (vis[u][o]) return;
            vis[u][o] = 1;
            for (int v : G[u]) dfs1(v, o ^ 1);
        };
        function<void(int, int)> dfs2 = [&](int u, int o) {
            if (vis[u][o]) return;
            vis[u][o] = 1;
            for (int v : rG[u]) dfs2(v, o ^ 1);
        };
        dfs1(L, 0), vis[L][0] = 0, dfs2(L, 0);
        int cnt[2][2] = {0};
        for (int i = 0; i <= L; i++) {
            cnt[vis[i][0]][vis[i][1]]++;
        }
        long long ans = 0;
        for (int i = R; i <= n; i++) {
            for (int j : {0, 1}) for (int k : {0, 1}) {
                if (j && vis[i][0] || k && vis[i][1]) ans += cnt[j][k];
            }
        }
        printf("%lld\n", ans - (L == R));
    }
    return 0;
}