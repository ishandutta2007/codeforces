#include <bits/stdc++.h>
using namespace std;

const int maxn = 900010;
int n, m, q, dfn, cur, bel[maxn], dep[maxn], tid[maxn], sz[maxn], fa[maxn][20];
int id[maxn], eu[maxn], ev[maxn], mp[maxn], ver[maxn];
vector<int> G[maxn];

struct BCC {
    int V, E, cnt, tim, dfn[maxn], low[maxn], bel[maxn];
    vector<pair<int, int>> G[maxn];

    void init(int _V) {
        V = _V;
        for (int i = 1; i <= V; i++) G[i].clear();
    }

    void add_edge(int u, int v) {
        G[u].emplace_back(v, ++E), G[v].emplace_back(u, E);
    }

    void tarjan(int v, int id) {
        static int tp = 0, st[maxn];
        dfn[v] = low[v] = ++tim, st[++tp] = v;
        for (auto e : G[v]) {
            if (!dfn[e.first]) {
                tarjan(e.first, e.second);
                low[v] = min(low[v], low[e.first]);
            } else if (e.second ^ id) {
                low[v] = min(low[v], dfn[e.first]);
            }
        }
        if (dfn[v] == low[v]) {
            cnt++;
            for (int x = 0; x ^ v; bel[x = st[tp--]] = cnt);
        }
    }

    void solve() {
        tim = 0, fill(dfn + 1, dfn + V + 1, 0);
        for (int i = 1; i <= V; i++) {
            if (!dfn[i]) tarjan(i, 0);
        }
    }

    bool test(vector<int> &ver) {
        for (int i = 1; i < ver.size(); i++) {
            if (bel[ver[0]] ^ bel[ver[i]]) return 0;
        }
        return 1;
    }
} G1, G2;

int main() {
    scanf("%d %d %d", &n, &m, &q), G1.init(n);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G1.add_edge(u, v);
    }
    G1.solve();
    for (int i = 1; i <= n; i++) {
        for (auto e : G1.G[i]) if (G1.bel[i] ^ G1.bel[e.first]) {
            G[G1.bel[i]].push_back(G1.bel[e.first]);
        }
    }
    function<void(int)> dfs = [&](int v) {
        tid[v] = ++dfn, bel[v] = cur;
        sz[v] = 1, dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (!tid[u]) {
            fa[u][0] = v, dfs(u), sz[v] += sz[u];
        }
    };
    for (int i = 1; i <= G1.cnt; i++) {
        if (!tid[i]) cur++, dfs(i);
    }
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    for (int $ = 1, val = 0; $ <= q; $++) {
        int V, E, tot = 0, m = 0;
        scanf("%d %d", &V, &E);
        auto nxt = [&]() { 
            int x; scanf("%d", &x);
            return G1.bel[(x + val - 1) % n + 1];
        };
        for (int i = 1; i <= V; i++) {
            id[++m] = ver[i] = nxt();
        }
        for (int i = 1; i <= E; i++) {
            id[++m] = eu[i] = nxt(), id[++m] = ev[i] = nxt();
        }
        sort(id + 1, id + m + 1, [&](int x, int y) { return tid[x] < tid[y]; });
        m = unique(id + 1, id + m + 1) - id - 1;
        for (int i = 1, $ = m; i < $; i++) {
            if (bel[id[i]] == bel[id[i + 1]]) id[++m] = lca(id[i], id[i + 1]);
        }
        sort(id + 1, id + m + 1, [&](int x, int y) { return tid[x] < tid[y]; });
        m = unique(id + 1, id + m + 1) - id - 1;    
        for (int i = 1; i <= m; i++) {
            if (!mp[id[i]]) mp[id[i]] = ++tot;
        }
        G2.init(tot);
        for (int i = 1; i <= E; i++) {
            G2.add_edge(mp[eu[i]], mp[ev[i]]);
        }
        for (int l = 1, r; l <= m; l = r) {
            for (r = l; r <= m && bel[id[l]] == bel[id[r]]; r++);
            vector<int> st = {id[l]};
            for (int i = l + 1; i < r; i++) {
                while (tid[id[i]] >= tid[st.back()] + sz[st.back()]) st.pop_back();
                G2.add_edge(mp[st.back()], mp[id[i]]), st.push_back(id[i]);
            }
        }
        G2.solve();
        vector<int> foo;
        for (int i = 1; i <= V; i++) {
            foo.push_back(mp[ver[i]]);
        }
        if (G2.test(foo)) puts("YES"), (val += $) %= n;
        else puts("NO");
        for (int i = 1; i <= m; i++) {
            mp[id[i]] = 0;
        }
    }
    return 0;
}