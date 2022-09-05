#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ver, tot, all, ano;
int fa[maxn], sz[maxn], _sz[maxn], rt[maxn], ans[maxn];
vector<int> G[maxn];
struct node { int l, r, s; } t[maxn * 60];

#define mid ((l + r) >> 1)
void ins(int &k, int l, int r, int p, int v = 1) {
    if (!k) k = ++tot;
    t[k].s += v;
    if (l < r) mid >= p ? ins(t[k].l, l, mid, p, v) : ins(t[k].r, mid + 1, r, p, v);
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    int k = ++tot;
    t[k].l = merge(t[k1].l, t[k2].l), t[k].r = merge(t[k1].r, t[k2].r);
    return t[k].s = t[k1].s + t[k2].s, k;
}

int prev(int k1, int k2, int l, int r, int p) {
    if (t[k1].s == t[k2].s) return 0;
    if (l == r) return l;
    int s = 0;
    if (mid < p) s = prev(t[k1].r, t[k2].r, mid + 1, r, p);
    if (!s) s = prev(t[k1].l, t[k2].l, l, mid, p);
    return s;
}

int next(int k1, int k2, int l, int r, int p) {
    if (t[k1].s == t[k2].s) return 0;
    if (l == r) return l;
    int s = 0;
    if (mid >= p) s = next(t[k1].l, t[k2].l, l, mid, p);
    if (!s) s = next(t[k1].r, t[k2].r, mid + 1, r, p);
    return s;
}

int main() {
    scanf("%d", &n);
    if (n == 1) puts("0"), exit(0);
    for (int i = 1, u, v; i <= n; i++) {
        scanf("%d %d", &u, &v);
        if (u) G[fa[v] = u].push_back(v);
        else ver = v;
    }
    function<void(int)> init = [&](int u) {
        sz[u] = 1;
        for (int v : G[u]) init(v), sz[u] += sz[v];
        ins(rt[u], 1, n, sz[u]), ins(all, 1, n, _sz[u] = sz[u]);
        for (int v : G[u]) rt[u] = merge(rt[u], rt[v]);
    };
    function<void(int)> dfs = [&](int u) {
        vector<array<int, 2>> V;
        if (fa[u]) V.push_back({sz[fa[u]], fa[u]});
        for (int v : G[u]) V.push_back({sz[v], v});
        sort(V.begin(), V.end()), ans[u] = V.back()[0];
        if (V.size() > 1) {
            int v = V.back()[1], diff = V.back()[0] - V[0][0];
            if (v == fa[u]) {
                int x = prev(all, rt[u], 1, n, diff / 2);
                ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
                x = next(all, rt[u], 1, n, (diff + 1) / 2);
                ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
                x = prev(ano, 0, 1, n, diff / 2 + _sz[u]) - _sz[u];
                if (x >= 0) ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
                x = next(ano, 0, 1, n, (diff + 1) / 2 + _sz[u]) - _sz[u];
                if (x >= 0) ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
            } else {
                int x = prev(rt[v], 0, 1, n, diff / 2);
                ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
                x = next(rt[v], 0, 1, n, (diff + 1) / 2);
                ans[u] = min(ans[u], max({V[V.size() - 2][0], V[0][0] + x, V.back()[0] - x}));
            }
        }
        ins(all, 1, n, _sz[u], -1);
        for (int v : G[u]) {
            if (fa[u]) ins(ano, 1, n, _sz[u]);
            sz[u] -= sz[v], sz[v] += sz[u];
            dfs(v), sz[v] -= sz[u], sz[u] += sz[v];
            if (fa[u]) ins(ano, 1, n, _sz[u], -1);
        }
        ins(all, 1, n, _sz[u], 1);
    };
    init(ver), dfs(ver);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}