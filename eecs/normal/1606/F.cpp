#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010, U = 200005;
int n, q, tot, son[maxn], rt[maxn], sz[maxn];
ll ans[maxn];
vector<int> G[maxn];
vector<array<int, 2>> Q[maxn];
struct node { int l, r, b1, b2; ll v; } t[maxn * 80];

#define mid ((l + r) >> 1)
void apply(int k, int v1, int v2) {
    t[k].b1 += v1, t[k].b2 += v2;
}

void pushdown(int k) {
    if (!t[k].l) t[k].l = ++tot;
    if (!t[k].r) t[k].r = ++tot;
    apply(t[k].l, t[k].b1, t[k].b2);
    apply(t[k].r, t[k].b1, t[k].b2), t[k].b1 = t[k].b2 = 0;
}

void clear(int &k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) { k = 0; return; }
    if (t[k].b1 || t[k].b2) pushdown(k);
    if (mid >= ql) clear(t[k].l, l, mid, ql, qr);
    if (mid < qr) clear(t[k].r, mid + 1, r, ql, qr);
}

int merge(int k1, int k2) {
    if (!k1 || !k2) return k1 | k2;
    if (!t[k2].l && !t[k2].r) {
        t[k1].b1 += t[k2].b1, t[k1].b2 += t[k2].b2;
        t[k1].v += t[k2].v; return k1;
    }
    if (!t[k1].l && !t[k1].r) {
        t[k2].b1 += t[k1].b1, t[k2].b2 += t[k1].b2;
        t[k2].v += t[k1].v; return k2;
    }
    if (t[k1].b1 || t[k1].b2) pushdown(k1);
    if (t[k2].b1 || t[k2].b2) pushdown(k2);
    t[k1].l = merge(t[k1].l, t[k2].l);
    t[k1].r = merge(t[k1].r, t[k2].r);
    return k1;
}

ll query(int k, int l, int r, int p, ll b1 = 0, ll b2 = 0) {
    b1 += t[k].b1, b2 += t[k].b2;
    if (!k || l == r) return t[k].v + b1 * p + b2;
    return mid >= p ? query(t[k].l, l, mid, p, b1, b2) : query(t[k].r, mid + 1, r, p, b1, b2);
}

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    scanf("%d", &q);
    for (int i = 1, v, k; i <= q; i++) {
        scanf("%d %d", &v, &k);
        Q[v].push_back({k, i});
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        sz[v] = 1, rt[v] = ++tot;
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), son[v]++, sz[v] += sz[u];
            rt[v] = merge(rt[v], rt[u]);
        }
        for (auto &p : Q[v]) {
            ans[p[1]] = son[v] + query(rt[v], 0, U, p[0]);
        }
        apply(rt[v], -1, son[v] - 1);
        int l = 0, r = U, pos = -1;
        while (l <= r) {
            if (query(rt[v], 0, U, mid) <= 0) r = (pos = mid) - 1;
            else l = mid + 1;
        }
        assert(~pos), clear(rt[v], 0, U, pos, U);
    };
    dfs(1, 0);
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}