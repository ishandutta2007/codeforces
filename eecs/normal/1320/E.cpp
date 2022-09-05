#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, id[maxn], s[maxn], qid[maxn], col[maxn], vis[maxn];
int tid[maxn], sz[maxn], dep[maxn], dist[maxn], fa[maxn][20];
vector<int> V, st, G[maxn];
vector<pair<int, int>> H[maxn];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>> Q;

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        static int tim = 0;
        tid[v] = ++tim, sz[v] = 1, dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs(u), sz[v] += sz[u];
        }
    };
    dfs(1);
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
    scanf("%d", &q);
    while (q--) {
        int k, m;
        scanf("%d %d", &k, &m), V.clear();
        for (int i = 1; i <= k; i++) {
            scanf("%d %d", &id[i], &s[i]), V.push_back(id[i]);
        }
        for (int i = 1; i <= m; i++) {
            scanf("%d", &qid[i]), V.push_back(qid[i]);
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return tid[x] < tid[y]; });
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int i = 0, $ = V.size(); i < $ - 1; i++) {
            V.push_back(lca(V[i], V[i + 1]));
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return tid[x] < tid[y]; });
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int v : V) {
            dist[v] = 1e9, H[v].clear(), vis[v] = 0;
        }
        st = {V[0]};
        for (int v : V) if (v ^ V[0]) {
            while (tid[v] >= tid[st.back()] + sz[st.back()]) st.pop_back();
            int w = dep[v] - dep[st.back()];
            H[st.back()].emplace_back(v, w), H[v].emplace_back(st.back(), w);
            st.push_back(v);
        }
        auto calc = [&](int d, int c) { return !c ? INT_MAX : (d + s[c] - 1) / s[c]; };
        for (int i = 1; i <= k; i++) {
            Q.emplace(0, col[id[i]] = i, id[i]), dist[id[i]] = 0;
        }
        while (!Q.empty()) {
            int v = get<2>(Q.top()); Q.pop();
            if (vis[v]) continue; vis[v] = 1;
            for (auto e : H[v]) {
                int u = e.first, w = e.second;
                auto p = make_tuple(calc(dist[v] + w, col[v]), col[v], u);
                if (p < make_tuple(calc(dist[u], col[u]), col[u], u)) {
                    Q.emplace(p), dist[u] = dist[v] + w, col[u] = col[v];
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            printf("%d%c", col[qid[i]], " \n"[i == m]);
        }
    }
    return 0;
}