#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, q, a[maxn];
ll pw[20];
struct node { ll tag, cov, mn; } t[maxn << 2];

#define mid (l + r >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
inline ll get(ll x) {
    return *lower_bound(pw, pw + 11, x) - x;
}

void build(int k, int l, int r) {
    if (l == r) { t[k].mn = get(t[k].cov = a[l]); return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

void pushdown(int k) {
    if (t[k].cov) {
        t[ls].cov = t[rs].cov = t[k].cov;
        t[ls].tag = t[rs].tag = 0;
        t[ls].mn = t[rs].mn = t[k].mn;
    } else if (t[k].tag) {
        if (t[ls].cov) t[ls].cov += t[k].tag;
        else t[ls].tag += t[k].tag;
        if (t[rs].cov) t[rs].cov += t[k].tag;
        else t[rs].tag += t[k].tag;   
        t[ls].mn -= t[k].tag, t[rs].mn -= t[k].tag;
    }
    t[k].cov = t[k].tag = 0;
}

void cover(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr) { t[k].mn = get(t[k].cov = v), t[k].tag = 0; return; }
    pushdown(k);
    if (mid >= ql) cover(ls, l, mid, ql, qr, v);
    if (mid < qr) cover(rs, mid + 1, r, ql, qr, v);
    t[k].mn = min(t[ls].mn, t[rs].mn);
}

ll add(int k, int l, int r, int ql, int qr, int v) {
    if (l >= ql && r <= qr && (t[k].mn >= v || t[k].cov)) {
        if (t[k].cov) t[k].mn = get(t[k].cov += v);
        else t[k].tag += v, t[k].mn -= v;
        return t[k].mn;
    }
    pushdown(k);
    if (mid >= ql) add(ls, l, mid, ql, qr, v);
    if (mid < qr) add(rs, mid + 1, r, ql, qr, v);
    return t[k].mn = min(t[ls].mn, t[rs].mn);
}

ll query(int k, int l, int r, int p) {
    if (l == r) return t[k].cov;
    pushdown(k);
    if (mid >= p) return query(ls, l, mid, p);
    return query(rs, mid + 1, r, p);
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = pw[0] = 1; i <= 10; i++) {
        pw[i] = 42 * pw[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    while (q--) {
        int op, x, y, z;
        scanf("%d %d", &op, &x);
        if (op == 1) {
            printf("%lld\n", query(1, 1, n, x));
        } else if (op == 2) {
            scanf("%d %d", &y, &z);
            cover(1, 1, n, x, y, z);
        } else {
            scanf("%d %d", &y, &z);
            while (!add(1, 1, n, x, y, z));
        }
    }
    return 0;
}