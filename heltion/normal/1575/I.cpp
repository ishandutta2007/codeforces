#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
int a[maxn];
vector<int> G[maxn];
int sz[maxn], hs[maxn], par[maxn];
int dfn[maxn], top[maxn], timer;
void dfs1(int u) {
    sz[u] = 1;
    for (int v : G[u]) if (v != par[u]) {
        par[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[hs[u]]) hs[u] = v;
    }
}
void dfs2(int u) {
    dfn[u] = timer += 1;
    if (hs[u]) {
        top[hs[u]] = top[u];
        dfs2(hs[u]);
    }
    for (int v : G[u])
        if (v != par[u] and v != hs[u])
            dfs2(top[v] = v);
}
LL BIT[maxn];
void add(int x, int v) {
    for ( ; x < maxn; x += x & -x) BIT[x] += v;
}
LL sum(int x) {
    LL res = 0;
    for (; x; x -= x & - x) res += BIT[x];
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for (int i = 1; i < n; i += 1) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1);
    dfs2(top[1] = 1);
    for (int i = 1; i <= n; i += 1) add(dfn[i], a[i]);
    for (int i = 1; i <= q; i += 1) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            add(dfn[u], -a[u]);
            a[u] = abs(v);
            add(dfn[u], a[u]);
        }
        else {
            LL ans = -a[u] - a[v];
            while (top[u] != top[v]) {
                if (dfn[u] > dfn[v]) swap(u, v);
                ans += 2 * (sum(dfn[v]) - sum(dfn[top[v]] - 1));
                v = par[top[v]];
            }
            if (dfn[u] > dfn[v]) swap(u, v);
            ans += 2 * (sum(dfn[v]) - sum(dfn[u] - 1));
            cout << ans << "\n";
        }
    }
    return 0;
}