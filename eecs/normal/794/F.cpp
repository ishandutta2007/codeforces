#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, q, a[maxn][10], b[maxn];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
struct node {
    int tr[10];
    long long all, sum[10];
    node() { iota(tr, tr + 10, 0), memset(sum, 0, sizeof(sum)); }
} tmp, t[maxn << 2];

void maintain(int k) {
    t[k].all = t[ls].all + t[rs].all;
    for (int i = 0; i < 10; i++) t[k].sum[i] = t[ls].sum[i] + t[rs].sum[i];
}

void apply(node &t1, node &t2) {  // apply tr1; apply tr2
    t1.all = 0;
    for (int i = 0; i < 10; i++) {
        t1.all += t2.tr[i] * t1.sum[i];
    }
    static long long old[10];
    memcpy(old, t1.sum, sizeof(old));
    memset(t1.sum, 0, sizeof(t1.sum));
    for (int i = 0; i < 10; i++) {
        t1.tr[i] = t2.tr[t1.tr[i]];
        t1.sum[t2.tr[i]] += old[i];
    }
}

void pushdown(int k) {
    apply(t[ls], t[k]), apply(t[rs], t[k]);
    assert(t[k].all == t[ls].all + t[rs].all);
    iota(t[k].tr, t[k].tr + 10, 0);
}

void build(int k, int l, int r) {
    if (l == r) { copy(a[l], a[l] + 10, t[k].sum), t[k].all = b[l]; return; }
    build(ls, l, mid), build(rs, mid + 1, r), maintain(k);
}

void upd(int k, int l, int r, int ql, int qr, node &v) {
    if (l >= ql && r <= qr) { apply(t[k], v); return; }
    pushdown(k);
    if (mid >= ql) upd(ls, l, mid, ql, qr, v);
    if (mid < qr) upd(rs, mid + 1, r, ql, qr, v);
    maintain(k);
}

long long query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k].all;
    pushdown(k);
    long long s = 0;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s += query(rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), b[i] = x;
        for (int pw = 1; x; x /= 10, pw *= 10) {
            a[i][x % 10] += pw;
        }
    }
    build(1, 1, n);
    while (q--) {
        int op, l, r, x, y;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1) {
            scanf("%d %d", &x, &y);
            iota(tmp.tr, tmp.tr + 10, 0), tmp.tr[x] = y;
            upd(1, 1, n, l, r, tmp);
        } else {
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}