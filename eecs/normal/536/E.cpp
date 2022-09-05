#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, coef[maxn], fa[maxn], ans[maxn];
int tim, tid[maxn], dep[maxn], sz[maxn], son[maxn], top[maxn];
vector<tuple<int, int, int>> E;
vector<tuple<int, int, int, int>> Q;
vector<int> G[maxn];
struct node { int l, r, s, all; } t[maxn << 2];

node merge(node A, node B) {
    node C;
    if (A.all && B.all) {
        C.l = A.l + B.l, C.r = A.r + B.r;
        C.s = coef[C.l], C.all = 1;
    } else {
        C.l = A.l, C.r = B.r;
        C.s = A.s + B.s, C.all = 0;
        if (A.all) {
            C.l += B.l, C.s += coef[C.l] - coef[A.l] - coef[B.l];
        } else if (B.all) {
            C.r += A.r, C.s += coef[C.r] - coef[A.r] - coef[B.r];
        } else {
            C.s += coef[A.r + B.l] - coef[A.r] - coef[B.l];
        }
    }
    return C;
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void modify(int k, int l, int r, int p) {
    if (l == r) { t[k].l = t[k].r = t[k].all = 1, t[k].s = coef[1]; return; }
    mid >= p ? modify(ls, l, mid, p) : modify(rs, mid + 1, r, p);
    t[k] = merge(t[ls], t[rs]);
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d", &coef[i]);
    }
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w), w = 1000000001 - w;
        E.emplace_back(w, u, v);
        G[u].push_back(v), G[v].push_back(u);
    }
    sort(E.begin(), E.end());
    function<void(int)> dfs1 = [&](int v) {
        dep[v] = dep[fa[v]] + 1, sz[v] = 1;
        for (int u : G[v]) if (u ^ fa[v]) {
            fa[u] = v, dfs1(u), sz[v] += sz[u];
            if (sz[u] > sz[son[v]]) son[v] = u;
        }
    };
    function<void(int, int)> dfs2 = [&](int v, int rt) {
        tid[v] = ++tim, top[v] = rt;
        if (son[v]) dfs2(son[v], rt);
        for (int u : G[v]) if (u ^ fa[v] && u ^ son[v]) dfs2(u, u);
    };
    dfs1(1), dfs2(1, 1);
    for (int i = 1, u, v, w; i <= q; i++) {
        scanf("%d %d %d", &u, &v, &w), w = 1000000001 - w;
        Q.emplace_back(w, u, v, i);
    }
    sort(Q.begin(), Q.end());
    for (int i = 0, j = 0; i < Q.size(); i++) {
        for (; j < E.size() && get<0>(E[j]) <= get<0>(Q[i]); j++) {
            int u = get<1>(E[j]), v = get<2>(E[j]);
            modify(1, 2, n, v == fa[u] ? tid[u] : tid[v]);
        }
        int u = get<1>(Q[i]), v = get<2>(Q[i]);
        node t; t.l = t.r = t.s = 0, t.all = 1;
        vector<node> V;
        while (top[u] ^ top[v]) {
            if (dep[top[u]] > dep[top[v]]) {
                auto p = query(1, 2, n, tid[top[u]], tid[u]);
                swap(p.l, p.r), t = merge(t, p), u = fa[top[u]];
            } else {
                V.push_back(query(1, 2, n, tid[top[v]], tid[v])), v = fa[top[v]];
            }
        }
        if (u ^ v) {
            auto p = query(1, 2, n, min(tid[u], tid[v]) + 1, max(tid[u], tid[v]));
            if (tid[u] > tid[v]) swap(p.l, p.r);
            t = merge(t, p);
        }
        reverse(V.begin(), V.end());
        for (auto p : V) t = merge(t, p);
        ans[get<3>(Q[i])] = t.s;
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}