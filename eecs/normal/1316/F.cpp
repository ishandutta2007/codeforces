#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010, P = 1e9 + 7;
int n, m, q;
int i2[maxn * 2], pre[maxn], rem[maxn], p[maxn], x[maxn], ndx[maxn * 2];
array<int, 2> vals[maxn * 2];
array<int, 4> st[maxn * 8];

int inc(int a, int b) { a += b - P; return a + (a >> 31 & P); }
int mul(int a, int b) { return 1LL * a * b % P; }

array<int, 4> operator + (array<int, 4> a, array<int, 4> b) {
    return {inc(mul(a[0], i2[b[2]]), b[0]), inc(a[1], mul(b[1], i2[a[2]])),
        a[2] + b[2], inc(mul(a[0], b[1]), inc(a[3], b[3]))};
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p, array<int, 4> v) {
    if (l == r) { st[k] = v; return; }
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    st[k] = st[ls] + st[rs];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    i2[0] = 1, i2[1] = (P + 1) / 2;
    for (int i = 2; i < maxn * 2; ++i) {
        i2[i] = mul(i2[i - 1], i2[1]);
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pre[i] = i, vals[i] = {p[i], i};
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int a;
        cin >> a >> x[i];
        rem[i] = pre[--a];
        pre[a] = n + i;
        vals[n + i] = {x[i], n + i};
    }
    m = n + q;
    sort(vals, vals + m);
    for (int i = 0; i < m; ++i) {
        ndx[vals[i][1]] = i;
    }
    for (int i = 0; i < n; ++i) {
        upd(1, 0, m - 1, ndx[i], {mul(p[i], i2[1]), mul(p[i], i2[1]), 1, 0});
    }
    cout << st[1][3] << '\n';
    for (int i = 0; i < q; ++i) {
        upd(1, 0, m - 1, ndx[rem[i]], array<int, 4>{});
        upd(1, 0, m - 1, ndx[n + i], {mul(x[i], i2[1]), mul(x[i], i2[1]), 1, 0});
        cout << st[1][3] << '\n';
    }
    return 0;
}