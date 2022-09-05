#include <bits/stdc++.h>
using namespace std;

const int maxn = 500010;
int n, q, a[maxn], t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void build(int k, int l, int r) {
    if (l == r) { t[k] = a[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = __gcd(t[ls], t[rs]);
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) { t[k] = v; return; }
    mid >= p ? modify(ls, l, mid, p, v) : modify(rs, mid + 1, r, p, v);
    t[k] = __gcd(t[ls], t[rs]);
}

bool chk(int k, int l, int r, int ql, int qr, int x) {
    if (l >= ql && r <= qr) return t[k] % x == 0;
    if (mid >= ql && !chk(ls, l, mid, ql, qr, x)) return 0;
    if (mid < qr && !chk(rs, mid + 1, r, ql, qr, x)) return 0;
    return 1;
}

int query(int k, int l, int r, int ql, int qr, int x) {
    ql = max(l, ql), qr = min(r, qr);
    if (l == r) return t[k] % x == 0 ? r + 1 : r;
    if (!(t[k] % x)) return qr + 1;
    if (mid >= ql) {
        int t = query(ls, l, mid, ql, qr, x);
        if (t <= mid) return t;
    }
    if (mid < qr) return query(rs, mid + 1, r, ql, qr, x);
    return qr + 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int op, x, y, z;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            scanf("%d", &z);
            int p = query(1, 1, n, x, y, z) + 1;
            if (p > y) { puts("YES"); continue; }
            puts(chk(1, 1, n, p, y, z) ? "YES" : "NO");
        } else {
            modify(1, 1, n, x, y);
        }
    }
    return 0;
}