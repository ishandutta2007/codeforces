#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int L, R, n, m, rt, tot, C, l[maxn], r[maxn];
int l1[maxn], r1[maxn], l2[maxn], r2[maxn], col[maxn], flip[maxn], bel[maxn];
vector<int> cand = {0}, G[maxn];
vector<array<int, 4>> M;
struct node { int l, r, mx, tag; } t[maxn * 80];

#define mid ((l + r) >> 1)
void add(int &k, int l, int r, int ql, int qr, int v) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { t[k].mx += v, t[k].tag += v; return; }
    if (mid >= ql) add(t[k].l, l, mid, ql, qr, v);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr, v);
    t[k].mx = max(t[t[k].l].mx, t[t[k].r].mx) + t[k].tag;
}

int get(int k, int l, int r, int ql, int qr, int s = 0) {
    if (s + t[k].mx < C) return 0;
    if (l == r) return l;
    s += t[k].tag;
    int ans = 0;
    if (mid >= ql) ans = get(t[k].l, l, mid, ql, qr, s);
    if (mid < qr && !ans) ans = get(t[k].r, mid + 1, r, ql, qr, s);
    return ans;
}

int main() {
    scanf("%d %d %d %d", &L, &R, &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        cand.push_back(l[i]), cand.push_back(r[i]);
    }
    sort(cand.begin(), cand.end());
    cand.resize(unique(cand.begin(), cand.end()) - cand.begin());
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; i++) if (!~col[i]) {
        r1[i] = r2[i] = 1e9;
        function<void(int)> dfs = [&](int u) {
            bel[u] = i;
            if (!col[u]) l1[i] = max(l1[i], l[u]), r1[i] = min(r1[i], r[u]);
            else l2[i] = max(l2[i], l[u]), r2[i] = min(r2[i], r[u]);
            for (int v : G[u]) {
                if (!~col[v]) col[v] = !col[u], dfs(v);
                if (col[u] == col[v]) puts("IMPOSSIBLE"), exit(0);
            }
        };
        col[i] = 0, C++, dfs(i);
        M.push_back({l1[i], l2[i], r2[i], 1});
        M.push_back({r1[i] + 1, l2[i], r2[i], -1});
        M.push_back({l2[i], l1[i], r1[i], 1});
        M.push_back({r2[i] + 1, l1[i], r1[i], -1});
        int x = max(l1[i], l2[i]), y = min(r1[i], r2[i]);
        if (x <= y) M.push_back({x, x, y, -1}), M.push_back({y + 1, x, y, 1});
    }
    sort(M.begin(), M.end());
    int num = 0, p = 0;
    for (int x : cand) if (x <= R) {
        for (; p < M.size() && M[p][0] <= x; p++) {
            add(rt, 0, 1e9, M[p][1], M[p][2], M[p][3]), num += M[p][3];
        }
        int y = get(rt, 0, 1e9, max(0, L - x), R - x);
        if (num < C || !y) continue;
        for (int i = 1; i <= n; i++) if (i == bel[i]) {
            if (l1[i] <= y && y <= r1[i] && l2[i] <= x && x <= r2[i]) flip[i] = 1;
        }
        printf("POSSIBLE\n%d %d\n", x, y);
        for (int i = 1; i <= n; i++) {
            putchar((col[i] ^ flip[bel[i]]) + '1');
        }
        exit(0);
    }
    puts("IMPOSSIBLE");
    return 0;
}