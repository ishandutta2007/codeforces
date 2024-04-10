#include <bits/stdc++.h>
using namespace std;

const int maxn = 600010;
int n, q, fa[maxn], dep[maxn], par[maxn][20], w[maxn], tid[maxn], mp[maxn];
vector<int> G[maxn];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
const int maxV = maxn << 1;
int mn[maxV], mx[maxV], _mn[maxV], _mx[maxV], cov[maxV];

void build(int k, int l, int r) {
    if (l == r) { _mn[k] = _mx[k] = tid[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    _mn[k] = min(_mn[ls], _mn[rs]), _mx[k] = max(_mx[ls], _mx[rs]);
}

void apply(int k, int v) {
    cov[k] = v;
    if (v == 1) mn[k] = _mn[k], mx[k] = _mx[k];
    else mn[k] = INT_MAX, mx[k] = 0;
}

void pushdown(int k) {
    if (cov[k]) apply(ls, cov[k]), apply(rs, cov[k]), cov[k] = 0;
}

void upd(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) return apply(k, v);
    pushdown(k);
    if (mid >= ql) upd(ls, l, mid, ql, qr, v);
    if (mid < qr) upd(rs, mid + 1, r, ql, qr, v);
    mn[k] = min(mn[ls], mn[rs]), mx[k] = max(mx[ls], mx[rs]);
}

int main() {
    scanf("%d %d", &n, &q);
    vector<array<int, 3>> E;
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        E.push_back({w, u, v});
    }
    sort(E.begin(), E.end());
    iota(fa + 1, fa + 2 * n, 1);
    int tot = n;
    for (auto &e : E) {
        int u = find(e[1]), v = find(e[2]);
        w[fa[u] = fa[v] = ++tot] = e[0];
        G[tot].push_back(u), G[tot].push_back(v);
    }
    function<void(int)> init = [&](int u) {
        static int tim = 0;
        mp[tid[u] = ++tim] = u, dep[u] = dep[par[u][0]] + 1;
        for (int i = 1; 1 << i < dep[u]; i++) {
            par[u][i] = par[par[u][i - 1]][i - 1];
        }
        for (int v : G[u]) {
            par[v][0] = u, init(v);
        }
    };
    memset(mn, 0x3f, sizeof(mn));
    init(tot), build(1, 1, n);
    auto lca = [&](int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        for (int i = 19; ~i; i--) {
            if (dep[par[u][i]] >= dep[v]) u = par[u][i];
        }
        if (u == v) return u;
        for (int i = 19; ~i; i--) {
            if (par[u][i] ^ par[v][i]) u = par[u][i], v = par[v][i];
        }
        return par[u][0];
    };
    while (q--) {
        int op, x, y;
        scanf("%d %d", &op, &x);
        if (op <= 2) {
            scanf("%d", &y), upd(1, 1, n, x, y, op);
        } else {
            if (mn[1] > 1e9 || mn[1] == tid[x] && mx[1] == tid[x]) puts("-1");
            else printf("%d\n", max(w[lca(x, mp[mn[1]])], w[lca(x, mp[mx[1]])]));
        }
    }
    return 0;
}