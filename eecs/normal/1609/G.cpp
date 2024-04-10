#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, q;
ll a[maxn], b[maxn], da[maxn], db[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
namespace SEG1 {
ll val[maxn << 2], tag[maxn << 2];

void apply(int k, ll v) {
    val[k] += v, tag[k] += v;
}

void pushdown(int k) {
    if (tag[k]) apply(ls, tag[k]), apply(rs, tag[k]), tag[k] = 0;
}

void build(int k, int l, int r) {
    val[k] = db[r];
    if (l < r) build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, ll v) {
    if (l >= ql && r <= qr) { apply(k, v); return; }
    pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    val[k] = val[rs];
}

int find(int k, int l, int r, ll v) {
    if (l == r) return l;
    pushdown(k);
    return val[ls] > v ? find(ls, l, mid, v) : find(rs, mid + 1, r, v);
}
}  // namespace SEG1

namespace SEG2 {
ll tk[maxn << 2], tb[maxn << 2];

void apply(int k, int l, int r, ll vk, ll vb) {
    tk[k] += vk, tb[k] += vb;
}

void pushdown(int k, int l, int r) {
    apply(ls, l, mid, tk[k], tb[k]);
    apply(rs, mid + 1, r, tk[k] + (mid - l + 1) * tb[k], tb[k]);
    tk[k] = tb[k] = 0;
}

void build(int k, int l, int r) {
    if (l == r) tk[k] = b[l];
    else build(ls, l, mid), build(rs, mid + 1, r);
}

void add(int k, int l, int r, int ql, int qr, ll vk, ll vb) {
    if (l >= ql && r <= qr) { apply(k, l, r, vk + vb * (l - ql), vb); return; }
    if (tk[k] || tb[k]) pushdown(k, l, r);
    if (mid >= ql) add(ls, l, mid, ql, qr, vk, vb);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, vk, vb);
}

ll query(int k, int l, int r, int p) {
    if (l == r) return tk[k];
    if (tk[k] || tb[k]) pushdown(k, l, r);
    return mid >= p ? query(ls, l, mid, p) : query(rs, mid + 1, r, p);
}
}  // namespace SEG2

int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    a[n + 1] = b[m + 1] = 1e18;
    for (int i = 1; i <= n; i++) {
        da[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &b[i]);
    }
    for (int i = 1; i <= m; i++) {
        db[i] = b[i + 1] - b[i];
    }
    SEG1::build(1, 1, m), SEG2::build(1, 1, m);
    ll sumb = accumulate(b + 1, b + m + 1, 0LL);
    while (q--) {
        int type, k, d;
        scanf("%d %d %d", &type, &k, &d);
        if (type == 1) {
            for (int i = n - k + 1; i <= n; i++) {
                a[i] += d * (i - (n - k)), da[i - 1] += d;
            }
        } else {
            SEG1::add(1, 1, m, max(1, m - k), m - 1, d);
            SEG2::add(1, 1, m, m - k + 1, m, d, d);
            sumb += 1LL * k * (k + 1) / 2 * d;
        }
        ll ans = a[1] + sumb;
        for (int i = 1, j = 1; i <= n; i++) {
            int k = SEG1::find(1, 1, m, da[i]);
            if (j < k) ans += a[i] * (k - j), j = k;
            if (i < n) ans += a[i + 1] + SEG2::query(1, 1, m, j);
        }
        printf("%lld\n", ans);
    }
    return 0;
}