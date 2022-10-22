#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 205;
const int mod = 998244353;

struct node {
    int v, id0, id1;
} f[maxn << 2];
int a[maxn];

void build(int t, int l, int r) {
    f[t].v = -1;
    f[t].id1 = mod;
    f[t].id0 = l;
    if (l == r) {
        f[t].v = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(LSON);
    build(RSON);
}

void pushDown(int t, int l, int r) {
    if (f[t].v == -1) return;
    f[t << 1].v = f[t << 1 | 1].v = f[t].v;
    int mid = (l + r) >> 1;
    if (f[t].v == 0) {
        f[t << 1].id0 = l;
        f[t << 1 | 1].id0 = mid + 1;
        f[t << 1].id1 = f[t << 1 | 1].id1 = mod;
    } else {
        f[t << 1].id1 = l;
        f[t << 1 | 1].id1 = mid + 1;
        f[t << 1].id0 = f[t << 1 | 1].id0 = mod;
    }
    f[t].v = -1;
}

int queryV(int t, int l, int r, int x) {
    if (l == r) return f[t].v;
    int mid = (l + r) >> 1;
    pushDown(t, l, r);
    if (x <= mid) return queryV(LSON, x);
    else return queryV(RSON, x);
}

int query0(int t, int l, int r, int x) {
    if (f[t].id0 == mod) return mod;
    if (l >= x && f[t].id0 != mod) return f[t].id0;
    int mid = (l + r) >> 1;
    pushDown(t, l, r);
    int res = mod;
    if (x <= mid) res = query0(LSON, x);
    if (res == mod) res = query0(RSON, x);
    return res;
}

int query1(int t, int l, int r, int x) {
    if (f[t].id1 == mod) return mod;
    if (l >= x && f[t].id1 != mod) return f[t].id1;
    int mid = (l + r) >> 1;
    pushDown(t, l, r);
    int res = mod;
    if (x <= mid) res = query1(LSON, x);
    if (res == mod) res = query1(RSON, x);
    return res;
}

int queryMax(int t, int l, int r) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    pushDown(t, l, r);
    if (f[t << 1 | 1].id1 != mod) return queryMax(RSON);
    else return queryMax(LSON);
}

void update(int t, int l, int r, int ll, int rr, int v) {
    if (ll <= l && r <= rr) {
        f[t].v = v;
        f[t].id0 = f[t].id1 = mod;
        if (v == 0) f[t].id0 = l;
        else f[t].id1 = l;
        return;
    }
    int mid = (l + r) >> 1;
    pushDown(t, l, r);
    if (ll <= mid) update(LSON, ll, rr, v);
    if (rr > mid) update(RSON, ll, rr, v);

    f[t].id0 = min(f[t << 1].id0, f[t << 1 | 1].id0);
    f[t].id1 = min(f[t << 1].id1, f[t << 1 | 1].id1);
}

void solve()
{
    int n, q, x, v, u, r, m = 2e5 + 50;
    cin >> n >> q;
    build(1, 1, m);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        u = queryV(1, 1, m, a[i]);
        if (u == 0) update(1, 1, m, a[i], a[i], 1);
        else {
            r = query0(1, 1, m, a[i] + 1);
            update(1, 1, m, a[i], r - 1, 0);
            update(1, 1, m, r, r, 1);
        }
    }

    while (q--) {
        cin >> x >> v;
        u = queryV(1, 1, m, a[x]);
        if (u == 1) update(1, 1, m, a[x], a[x], 0);
        else {
            r = query1(1, 1, m, a[x] + 1);
            update(1, 1, m, a[x], r - 1, 1);
            update(1, 1, m, r, r, 0);
        }

        a[x] = v;
        u = queryV(1, 1, m, a[x]);
        if (u == 0) update(1, 1, m, a[x], a[x], 1);
        else {
            r = query0(1, 1, m, a[x] + 1);
            update(1, 1, m, a[x], r - 1, 0);
            update(1, 1, m, r, r, 1);
        }

        cout << queryMax(1, 1, m) << endl;
    }
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}