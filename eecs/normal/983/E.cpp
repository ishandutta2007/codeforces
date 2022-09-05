#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, q, ver[maxn], dep[maxn], ctz[maxn], mn[maxn], bel[maxn];
int tot, tim, sz[maxn], tid[maxn], rt[maxn], fa[maxn][20], up[maxn][20];
vector<int> G[maxn];
struct node { int l, r; bool s; } t[maxn * 70];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

#define mid (l + r >> 1)
void ins(int &k, int l, int r, int p) {
    if (!k) k = ++tot; t[k].s = 1;
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

bool query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].s;
    if (mid >= ql && query(t[k].l, l, mid, ql, qr)) return true;
    if (mid < qr && query(t[k].r, mid + 1, r, ql, qr)) return true;
    return false;
}

int merge(int l, int r, int k1, int k2) {
    if (!k1 && !k2) return 0;
    if (!k1 || !k2 || l == r) return k1 ? k1 : k2;
    int k = ++tot;
    t[k].s = t[k1].s | t[k2].s;
    t[k].l = merge(l, mid, t[k1].l, t[k2].l);
    t[k].r = merge(mid + 1, r, t[k1].r, t[k2].r);
    return k;
}

int main() {
    scanf("%d", &n);
    for (int i = dep[1] = 1; i <= n; i++) {
        ctz[i] = __builtin_ctz(i);
    }
    for (int i = 2; i <= n; i++) {
        scanf("%d", &fa[i][0]);
        G[fa[i][0]].push_back(i);
        dep[i] = dep[fa[i][0]] + 1;
        for (int j = 1; j < 20; j++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
    auto jump = [&](int v, int d) {
        while (d) {
            int i = ctz[d];
            v = fa[v][i], d ^= 1 << i;
        }
        return v;
    };
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        u = jump(u, dep[u] - dep[v]);
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (fa[u][i] ^ fa[v][i]) u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    };
    function<void(int)> init = [&](int v) {
        tid[v] = ++tim, sz[v] = 1;
        for (int u : G[v]) init(u), sz[v] += sz[u];
    };
    scanf("%d", &m), init(1);
    memset(mn, 0x3f, sizeof(mn));
    iota(bel + 1, bel + n + 1, 1);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        int l = lca(u, v);
        mn[u] = min(mn[u], dep[l]), mn[v] = min(mn[v], dep[l]);
        ins(rt[u], 1, n, tid[v]), ins(rt[v], 1, n, tid[u]);
        for (u = find(u); dep[u] > dep[l]; u = find(u)) bel[u] = fa[u][0];
        for (v = find(v); dep[v] > dep[l]; v = find(v)) bel[v] = fa[v][0];
    }
    function<void(int)> dfs = [&](int v) {
        ver[dep[v]] = v;
        for (int u : G[v]) {
            dfs(u), mn[v] = min(mn[v], mn[u]);
            rt[v] = merge(1, n, rt[v], rt[u]);
        }
        if (mn[v] < dep[v]) up[v][0] = ver[mn[v]];
    };
    dfs(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 20; j++) {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    auto solve = [&](int u, int v) {
        int ans = 0;
        for (int i = 19; ~i; i--) {
            if (dep[up[u][i]] > dep[v]) u = up[u][i], ans |= 1 << i;
        }
        return make_pair(ans, u);
    };
    scanf("%d", &q);
    while (q--) {
        int u, v; scanf("%d %d", &u, &v);
        if (find(u) ^ find(v)) { puts("-1"); continue; }
        int l = lca(u, v);
        if (u == l) swap(u, v);
        auto p = solve(u, l);
        int ans = p.first; u = p.second;
        int t = u; u = v;
        for (int i = 19; ~i; i--) {
            int nu = fa[u][i];
            if (dep[nu] > dep[l] && !query(rt[t], 1, n, tid[nu], tid[nu] + sz[nu] - 1)) u = nu;
        }
        if (u ^ l && !query(rt[t], 1, n, tid[u], tid[u] + sz[u] - 1)) u = fa[u][0];
        printf("%d\n", ans + solve(v, u).first + 1 + (u != v));
    }
    return 0;
}