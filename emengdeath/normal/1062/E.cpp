#include <bits/stdc++.h>
using namespace std;
struct node{
    int l, r, lca;
}f[400001], a, b, c;
int n, q;
int deep[100001], fa[100001][17];
vector<int>g[100001];
void dfs(int x) {
    for (int i = 0; fa[x][i]; i ++) fa[x][i + 1] = fa[fa[x][i]][i];
    deep[x] ++;
    for (auto u:g[x])
        deep[u] = deep[x], fa[u][0] = x, dfs(u);
}
int getlca(int x, int y) {
    int i = 16;
    if (deep[x] < deep[y]) swap(x, y);
    while (deep[x] != deep[y]) {
        while (deep[fa[x][i]] < deep[y]) i --;
        x = fa[x][i];
    }
    i = 16;
    while (x != y) {
        while (i && fa[x][i] == fa[y][i]) i --;
        x = fa[x][i], y = fa[y][i];
    }
    return x;
}
void get(node &a, node  &b, node &c) {
    c.lca = getlca(a.lca, b.lca);
    if (getlca(a.l, b.l) == c.lca) {
        c.l = a.l;
        c.r = b.l;
        return;
    }
    if (getlca(a.l, b.r) == c.lca) {
        c.l = a.l;
        c.r = b.r;
        return;
    }
    if (getlca(a.r, b.l) == c.lca) {
        c.l = a.r;
        c.r = b.l;
        return;
    }
    if (getlca(a.r, b.r) == c.lca) {
        c.l = a.r;
        c.r = b.r;
        return;
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].l = l;
        f[s].r = r;
        f[s].lca = l;
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    get(f[s + s], f[s + s + 1], f[s]);
}
void search(int l, int r, int s, int ll, int rr, node&a) {
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        if (a.lca == 0) a = f[s];
        else
            get(a, f[s], a);
        return;
    }
    search(l, (l + r) / 2, s + s, ll, rr, a);
    search((l + r) / 2 + 1, r, s + s + 1, ll, rr, a);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i ++) {
        int x;
        scanf("%d ", &x);
        g[x].push_back(i);
    }
    dfs(1);
    build(1, n, 1);
    while (q --) {
        int l, r;
        scanf("%d %d", &l, &r);
        c.lca = 0;
        search(1, n, 1, l, r, c);
        a.lca = 0;
        search(1, n, 1, l, c.l - 1, a);
        search(1, n, 1, c.l + 1, r, a);
        b.lca = 0;
        search(1, n, 1, l, c.r - 1, b);
        search(1, n, 1, c.r + 1, r, b);
        if (deep[a.lca] > deep[b.lca])
            printf("%d %d\n", c.l, deep[a.lca] - 1);
        else
            printf("%d %d\n", c.r, deep[b.lca] - 1);
    }
    return 0;
}