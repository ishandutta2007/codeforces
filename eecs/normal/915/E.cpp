#include <bits/stdc++.h>
#define mid (l + r >> 1)
using namespace std;

int n, q, tot, x;
struct node { int l, r, s, t = -1; } t[15000010];

void pushdown(int k, int l, int r) {
    if (!t[k].l) t[k].l = ++tot;
    if (!t[k].r) t[k].r = ++tot;
    t[t[k].l].s = (mid - l + 1) * (t[t[k].l].t = t[k].t);
    t[t[k].r].s = (r - mid) * (t[t[k].r].t = t[k].t), t[k].t = -1;
}

void modify(int &k, int l, int r, int ql, int qr, int v) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { t[k].s = (r - l + 1) * (t[k].t = v); return; }
    if (~t[k].t) pushdown(k, l, r);
    if (mid >= ql) modify(t[k].l, l, mid, ql, qr, v);
    if (mid < qr) modify(t[k].r, mid + 1, r, ql, qr, v);
    t[k].s = t[t[k].l].s + t[t[k].r].s;
}

int main() {
    scanf("%d %d", &n, &q), modify(x, 1, n, 1, n, 1);
    for (int i = 1, l, r, k; i <= q; i++) {
        scanf("%d %d %d", &l, &r, &k), k--;
        modify(x, 1, n, l, r, k), printf("%d\n", t[x].s);
    }
    return 0;
}