#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, rt, tim, sz[maxn], tid[maxn], dep[maxn], vis[maxn], fa[maxn];
ll K, lb, rb;
vector<int> rem, G[maxn];
set<pair<int, int>> Q, lca[maxn], leaf[maxn];

int main() {
    scanf("%d %lld", &n, &K);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs1 = [&](int v, int fa) {
        int mx = 0; sz[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            dfs1(u, v), sz[v] += sz[u];
            mx = max(mx, sz[u]);
            lb += sz[u] & 1, rb += min(sz[u], n - sz[u]);
        }
        if (max(mx, n - sz[v]) << 1 <= n) rt = v;
    };
    dfs1(1, 0);
    if (K < lb || K > rb || (K & 1) ^ (lb & 1)) puts("NO"), exit(0);
    puts("YES");
    function<void(int, int)> dfs2 = [&](int v, int bel) {
        dep[v] = dep[fa[v]] + 1, tid[v] = ++tim, sz[v] = 1;
        if (G[v].size() == 1) leaf[bel].emplace(tid[v], v);
        else lca[bel].emplace(dep[v], v);
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs2(u, bel), sz[v] += sz[u];
        }
    };
    for (int v : G[rt]) {
        fa[v] = rt, dfs2(v, v), Q.emplace(sz[v], v);
    }
    while (rb > K) {
        auto sub = *Q.rbegin();
        int w = sub.second; Q.erase(sub);
        if (lca[w].empty()) continue;
        auto chk = [&](int v) {
            if (vis[v]) return;
            auto p = leaf[w].lower_bound({tid[v], 0});
            if (p == leaf[w].end() || p->first >= tid[v] + sz[v]) lca[w].erase({dep[v], v}), leaf[w].emplace(tid[v], v);
        };
        auto p = --lca[w].lower_bound({((rb - K) >> 1) + 1, 0});
        int z = p->second; rb -= p->first << 1;
        int u = (p = leaf[w].lower_bound({tid[z], 0}))->second, v;
        leaf[w].erase(p), p = leaf[w].lower_bound({tid[z] + sz[z], 0});
        if (p == leaf[w].begin() || (--p)->first < tid[z] || K == rb) v = z, lca[w].erase({dep[z], z});
        else v = p->second, leaf[w].erase(p);
        printf("%d %d\n", u, v), vis[u] = vis[v] = 1;
        chk(fa[u]), chk(fa[v]);
        sub.first -= 2, Q.emplace(sub);
    }
    function<void(int)> dfs3 = [&](int v) {
        if (!vis[v]) rem.push_back(v);
        for (int u : G[v]) if (u ^ fa[v]) dfs3(u);
    };
    dfs3(rt);
    for (int i = 0; i < rem.size() / 2; i++) {
        printf("%d %d\n", rem[i], rem[i + rem.size() / 2]);
    }
    return 0;
}