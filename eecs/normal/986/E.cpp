#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, A = 10000010, P = 1000000007;
int n, q, a[maxn], old[maxn], rt[A], tid[maxn], sz[maxn], fa[maxn][20], dep[maxn];
int tot, p[A], mn[A];
vector<int> G[maxn];
struct node { int l, r, s; } t[maxn * 200];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

#define mid (l + r >> 1)
void add(int &k, int l, int r, int ql, int qr) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { t[k].s++; return; }
    if (mid >= ql) add(t[k].l, l, mid, ql, qr);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr);
}

int query(int k, int l, int r, int p, int cur = 0) {
    if (!k) return cur;
    cur += t[k].s;
    if (l == r) return cur;
    return mid >= p ? query(t[k].l, l, mid, p, cur) : query(t[k].r, mid + 1, r, p, cur);
}

int main() {
    scanf("%d", &n);
    fill(p, p + A, 1);
    for (int i = 2; i < A; i++) {
        if (p[i]) p[++tot] = i, mn[i] = i;
        for (int j = 1; j <= tot && i * p[j] < A; j++) {
            p[i * p[j]] = 0, mn[i * p[j]] = p[j];
            if (!(i % p[j])) break;
        }
    }
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int)> dfs = [&](int v) {
        static int tim = 0;
        tid[v] = ++tim, sz[v] = 1, dep[v] = dep[fa[v][0]] + 1;
        for (int i = 1; 1 << i < dep[v]; i++) {
            fa[v][i] = fa[fa[v][i - 1]][i - 1];
        }
        for (int u : G[v]) if (u ^ fa[v][0]) {
            fa[u][0] = v, dfs(u), sz[v] += sz[u];
        }
    };
    dfs(1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), old[i] = a[i];
        while (a[i] > 1) {
            int x = mn[a[i]], y = 1;
            while (!(a[i] % x)) {
                a[i] /= x, y *= x;
                add(rt[y], 1, n, tid[i], tid[i] + sz[i] - 1);
            }
        }
    } 
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
    while (q--) {
        int u, v, x; scanf("%d %d %d", &u, &v, &x);
        int t = lca(u, v), ans = 1;
        while (x > 1) {
            int y = mn[x], z = 1, cnt = 0;
            while (!(x % y)) {
                x /= y, z *= y;
                int num = query(rt[z], 1, n, tid[u]);
                num += query(rt[z], 1, n, tid[v]);
                num -= query(rt[z], 1, n, tid[t]) * 2;
                if (!(old[t] % z)) num++;
                cnt += num;
            }
            ans = 1LL * ans * qp(y, cnt) % P;
        }
        printf("%d\n", ans);
    }
    return 0;
}