#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010;
int n, q, tot = 1, lst = 1, cnt, h[maxn], pos[maxn], ans[maxn], rt[maxn];
int len[maxn], sz[maxn], fa[maxn], par[20][maxn];
unordered_map<int, int> ch[maxn];
vector<int> G[maxn];
vector<array<int, 3>> Q[maxn];
struct node { int l, r, s; } t[maxn * 10];

void ins(int c) {
    int p = lst, np = lst = ++tot;
    len[np] = len[p] + 1, sz[np]++;
    for (; p && !ch[p][c]; p = fa[p]) ch[p][c] = np;
    if (!p) { fa[np] = 1; return; }
    int q = ch[p][c];
    if (len[q] == len[p] + 1) {
        fa[np] = q;
    } else {
        int nq = ++tot; len[nq] = len[p] + 1;
        fa[nq] = fa[q], ch[nq] = ch[q], fa[q] = fa[np] = nq;
        for (; ch[p][c] == q; p = fa[p]) ch[p][c] = nq;
    }
}

#define mid ((l + r) >> 1)
void ins(int &k, int l, int r, int p) {
    t[k = ++cnt].s++;
    if (l == r) return;
    mid >= p ? ins(t[k].l, l, mid, p) : ins(t[k].r, mid + 1, r, p);
}

int query(int k, int l, int r, int ql, int qr) {
    if (!k || l >= ql && r <= qr) return t[k].s;
    int s = 0;
    if (mid >= ql) s = query(t[k].l, l, mid, ql, qr);
    if (mid < qr) s += query(t[k].r, mid + 1, r, ql, qr);
    return s;
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    t[k1].l = merge(t[k1].l, t[k2].l), t[k1].r = merge(t[k1].r, t[k2].r);
    return t[k1].s += t[k2].s, k1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i < n; i++) {
        h[i] = h[i] - h[i + 1];
    }
    for (int i = 1; i < n; i++) {
        h[i + n - 1] = -h[i];
    }
    for (int i = 1; i <= 2 * (n - 1); i++) {
        ins(h[i]), pos[i] = lst;
    }
    for (int i = 1; i <= tot; i++) {
        par[0][i] = fa[i];
        if (i > 1) G[fa[i]].push_back(i);
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= tot; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }
    auto find = [&](int l, int r) {
        l = r - l + 1, r = pos[r];
        for (int i = 19; ~i; i--) {
            if (len[par[i][r]] >= l) r = par[i][r];
        }
        return r;
    };
    scanf("%d", &q);
    for (int i = 1, l, r; i <= q; i++) {
        scanf("%d %d", &l, &r);
        if (l == r) ans[i] = n - 1;
        else Q[find(l + n - 1, r + n - 2)].push_back({l - 2, r + r - l, i});
    }
    for (int i = 1; i < n; i++) {
        ins(rt[pos[i]], 1, n, i);
    }
    function<void(int)> dfs = [&](int u) {
        for (int v : G[u]) {
            dfs(v), rt[u] = merge(rt[u], rt[v]);
        }
        for (auto &p : Q[u]) {
            if (p[0] > 0) ans[p[2]] += query(rt[u], 1, n, 1, p[0]);
            if (p[1] < n) ans[p[2]] += query(rt[u], 1, n, p[1], n - 1);
        }
    };
    dfs(1);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}