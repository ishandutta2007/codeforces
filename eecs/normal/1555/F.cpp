#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, q, t[maxn << 2], tag[maxn << 2];
int tim, son[maxn], top[maxn], tid[maxn];
int dep[maxn], bel[maxn], d[maxn], mark[500010], vis[maxn], fa[maxn], sz[maxn];
struct edge { int u, v, x; } e[500010];
set<pair<int, int>> S;
vector<tuple<int, int, int>> E[maxn];
vector<pair<int, int>> G[maxn];

int find(int x) {
    return x == bel[x] ? x : bel[x] = find(bel[x]);
}

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void add(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { t[k] = tag[k] = 1; return; }
    if (tag[k]) t[ls] = tag[ls] = t[rs] = tag[rs] = 1, tag[k] = 0;
    if (mid >= ql) add(ls, l, mid, ql, qr);
    if (mid < qr) add(rs, mid + 1, r, ql, qr);
    t[k] = t[ls] | t[rs];
}

bool test(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (tag[k]) t[ls] = tag[ls] = t[rs] = tag[rs] = 1, tag[k] = 0;
    bool s = 0;
    if (mid >= ql) s = test(ls, l, mid, ql, qr);
    if (mid < qr) s |= test(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    iota(bel + 1, bel + n + 1, 1);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].x);
        int bu = find(e[i].u), bv = find(e[i].v);
        if (bu != bv) {
            G[e[i].u].emplace_back(e[i].v, e[i].x);
            G[e[i].v].emplace_back(e[i].u, e[i].x);
            mark[i] = 1, bel[bu] = bv;
        }
    }
    function<void(int)> dfs1 = [&](int v) {
        dep[v] = dep[fa[v]] + 1, sz[v] = vis[v] = 1;
        for (auto e : G[v]) if (e.first ^ fa[v]) {
            fa[e.first] = v, d[e.first] = d[v] ^ e.second;
            dfs1(e.first), sz[v] += sz[e.first];
            if (sz[e.first] > sz[son[v]]) son[v] = e.first;
        }
    };
    function<void(int, int)> dfs2 = [&](int v, int rt) {
        top[v] = rt, tid[v] = ++tim;
        if (son[v]) dfs2(son[v], rt);
        for (auto e : G[v]) if (e.first ^ fa[v] && e.first ^ son[v]) {
            dfs2(e.first, e.first);
        }
    };
    auto ins = [&](int u, int v) {
        while (top[u] ^ top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            add(1, 1, n, tid[top[u]], tid[u]), u = fa[top[u]];
        }
        if (tid[u] > tid[v]) swap(u, v);
        if (u ^ v) add(1, 1, n, tid[u] + 1, tid[v]);
    };
    auto chk = [&](int u, int v) {
        while (top[u] ^ top[v]) {
            if (dep[top[u]] < dep[top[v]]) swap(u, v);
            if (test(1, 1, n, tid[top[u]], tid[u])) return 0;
            u = fa[top[u]];
        }
        if (tid[u] > tid[v]) swap(u, v);
        if (u ^ v && test(1, 1, n, tid[u] + 1, tid[v])) return 0;
        return 1;
    };
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs1(i), dfs2(i, i);
    }
    for (int i = 1; i <= q; i++) {
        if (mark[i]) {
            puts("YES");
        } else {
            int u = e[i].u, v = e[i].v;
            if (!(d[u] ^ d[v] ^ e[i].x)) { puts("NO"); continue; }
            if (!chk(u, v)) puts("NO");
            else puts("YES"), ins(u, v);
        }
    }
    return 0;
}