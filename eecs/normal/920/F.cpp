#include <bits/stdc++.h>
#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, m, a[maxn], d[1000010];
struct node { int mx; ll s; } t[maxn << 2];

void build(int k, int l, int r) {
    if (l == r) { t[k].mx = t[k].s = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].mx = max(t[ls].mx, t[rs].mx), t[k].s = t[ls].s + t[rs].s;
}

void modify(int k, int l, int r, int ql, int qr) {
    if (t[k].mx <= 2) return;
    if (l == r) { t[k].mx = t[k].s = d[t[k].s]; return; }
    if (mid >= ql) modify(ls, l, mid, ql, qr);
    if (mid < qr) modify(rs, mid + 1, r, ql, qr);
    t[k].mx = max(t[ls].mx, t[rs].mx), t[k].s = t[ls].s + t[rs].s;
}

ll query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].s;
    ll s = 0;
    if (mid >= ql) s += query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            d[j]++;
        }
    }
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1, k, l, r; i <= m; i++) {
        scanf("%d %d %d", &k, &l, &r);
        if (k == 1) modify(1, 1, n, l, r);
        else printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}