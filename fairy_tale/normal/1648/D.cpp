#include<bits/stdc++.h>
#define fi first
#define se second
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int maxn = 5e5 + 5;
const int mod = 1e9 + 7;

LL a[maxn], b[maxn], c[maxn];
int n;

struct line {
    LL l, r, v;
} g[maxn];

struct node {
    LL A, B, C;
} f[maxn << 2];

void treeUp(node &m, node l, node r)
{
    m.A = max(l.A, r.A);
    m.B = max(l.B, r.B);
    m.C = max(max(l.C, r.C), l.A + r.B);
}

void build(int t, int l, int r)
{
    if (l == r) {
        f[t].A = a[l] - b[l - 1];
        f[t].B = c[n] - c[r - 1] + b[r];
        f[t].C = f[t].A + f[t].B;
        return;
    }

    int mid = (l + r) >> 1;
    build(t << 1, l, mid);
    build(t << 1 | 1, mid + 1, r);
    treeUp(f[t], f[t << 1], f[t << 1 | 1]);
}

void update(int t, int l, int r, int x, LL v)
{
    if (l == r) {
        f[t].A = max(f[t].A, v);
        f[t].C = f[t].A + f[t].B;
        return;
    }

    int mid = (l + r) >> 1;
    if (x <= mid) update(t << 1, l, mid, x, v);
    else update(t << 1 | 1, mid + 1, r, x, v);
    treeUp(f[t], f[t << 1], f[t << 1 | 1]);
}

node query(int t, int l, int r, int ll, int rr)
{
    if (ll <= l && r <= rr) return f[t];
    int mid = (l + r) >> 1;
    if (rr <= mid) return query(t << 1, l, mid, ll, rr);
    else if (ll > mid) return query(t << 1 | 1, mid + 1, r, ll, rr);
    else {
        node w;
        treeUp(w, query(t << 1, l, mid, ll, rr), query(t << 1 | 1, mid + 1, r, ll, rr));
        return w;
    }
}

int main() {
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];

    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]);
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];

    for (int i = 0; i < q; i++) scanf("%lld%lld%lld", &g[i].l, &g[i].r, &g[i].v);
    sort(g, g + q, [&](line u, line v){return u.r < v.r;});

    build(1, 1, n);
    LL ans = -1e18;
    for (int i = 0; i < q; i++) {
        node w = query(1, 1, n, g[i].l, g[i].r);
        ans = max(ans, w.C - g[i].v);

        if (g[i].r != n) {
            update(1, 1, n, g[i].r + 1, w.A - g[i].v);
        }
    }

    printf("%lld\n", ans);

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}