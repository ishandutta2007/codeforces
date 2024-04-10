#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, chk[maxn], ed[maxn], fa[maxn], bel[maxn], par[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear();
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            G[u].push_back(v), G[v].push_back(u);
        }
        vector<pair<int, int>> V;
        function<void(int)> dfs = [&](int v) {
            vector<int> H;
            for (int u : G[v]) if (u ^ fa[v]) {
                fa[u] = v, dfs(u);
                if (chk[u]) H.push_back(u);
            }
            chk[v] = H.size() <= 1;
            if (H.empty()) {
                ed[v] = v;
            } else if (H.size() == 1) {
                ed[v] = ed[H[0]];
            } else {
                for (int i = ed[H[0]]; ; i = fa[i]) {
                    bel[i] = V.size();
                    if (i == H[0]) break;
                }
                for (int i = ed[H[1]]; ; i = fa[i]) {
                    bel[i] = V.size();
                    if (i == H[1]) break;
                }
                bel[v] = V.size(), V.emplace_back(ed[H[0]], ed[H[1]]);
                for (int i = 2; i < H.size(); i++) {
                    for (int j = ed[H[i]]; ; j = fa[j]) {
                        bel[j] = V.size();
                        if (j == H[i]) break;
                    }
                    V.emplace_back(H[i], ed[H[i]]);
                }
            }
        };
        dfs(1);
        if (chk[1]) {
            for (int i = ed[1]; ; i = fa[i]) {
                bel[i] = V.size();
                if (i == 1) break;
            }
            V.emplace_back(1, ed[1]);
        }
        printf("%d\n", V.size() - 1);
        iota(par, par + V.size(), 0);
        for (int i = 2; i <= n; i++) if (bel[i] ^ bel[fa[i]]) {
            int u = find(bel[i]), v = find(bel[fa[i]]);
            printf("%d %d %d %d\n", i, fa[i], V[u].second, V[v].first);
            par[u] = v, V[v].first = V[u].first;
        }
    }
    return 0;
}