#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, dfn, tid[maxn], dep[maxn], fa[maxn][20], sz[maxn];
int f[maxn], g[maxn], chk[maxn];
vector<int> G[maxn], H[maxn];

int main() {
    scanf("%d", &n);
    for (int _ = 1, u, v; _ < n; _++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        tid[v] = ++dfn, dep[v] = dep[fa[v][0]] + 1, sz[v] = 1;
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
    for (int _ = 1, k; _ <= q; _++) {
        scanf("%d", &k);
        vector<int> V = {1};
        for (int $ = 1, v; $ <= k; $++) {
            scanf("%d", &v);
            chk[v] = 1, V.push_back(v);
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return tid[x] < tid[y]; });
        for (int i = 0, $ = V.size(); i < $ - 1; i++) {
            V.push_back(lca(V[i], V[i + 1]));
        }
        sort(V.begin(), V.end(), [&](int x, int y) { return tid[x] < tid[y]; });
        V.resize(unique(V.begin(), V.end()) - V.begin());
        stack<int> st; st.push(1);
        for (int i = 1; i < V.size(); i++) {
            while (tid[V[i]] >= tid[st.top()] + sz[st.top()]) st.pop();
            H[st.top()].push_back(V[i]), st.push(V[i]);
        }
        bool flag = 0;
        function<void(int)> dfs = [&](int v) {
            f[v] = g[v] = 0;
            int mn1 = 0, mn2 = 0, mn3 = 0;
            for (int u : H[v]) {
                dfs(u);
                if (chk[u] && chk[v] && v == fa[u][0]) flag = 1;
                if (chk[v]) {
                    g[v] += min(f[u], g[u] + 1);
                } else {
                    f[v] += min(f[u], g[u]), mn3 += f[u];
                    int foo = min(f[u], g[u] + (v == fa[u][0] && chk[u] ? n + 1 : 1)), bar = mn1;
                    mn1 += foo, mn2 += foo;
                    mn2 = min(mn2, bar + g[u]);
                }
            }
            if (!chk[v]) f[v] = min(f[v] + 1, mn3), g[v] = mn2;
            else f[v] = n + 1;
            f[v] = min(f[v], n + 1), g[v] = min(g[v], n + 1);
        };
        dfs(1);
        int ans = min(f[1], g[1]) > n ? -1 : min(f[1], g[1]);
        if (flag) assert(ans <= n);
        printf("%d\n", flag ? -1 : ans);
        for (int v : V) chk[v] = 0, H[v].clear();
    }
    return 0;
}