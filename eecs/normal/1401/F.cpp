#include <bits/stdc++.h>
using namespace std;

const int maxn = 300000;
int n, q, a[maxn], lg[maxn], p1[maxn << 2], p2[maxn << 2];
int rev_tim[19], swap_tim[19];
struct node { int ls, rs; bool rev; long long s; } t[maxn << 2];

#define mid (l + r >> 1)
void down(int k) {
    t[k].rev ^= 1, swap(t[k].ls, t[k].rs);
}

void pushdown(int k) {
    down(t[k].ls), down(t[k].rs), t[k].rev = 0;
}

void build(int k, int l, int r) {
    t[k].ls = k * 2, t[k].rs = k * 2 + 1, p1[k] = p2[k] = 0;
    if (l == r) { t[k].s = a[l]; return; }
    build(t[k].ls, l, mid), build(t[k].rs, mid + 1, r);
    t[k].s = t[t[k].ls].s + t[t[k].rs].s;
}

void chk(int k, int l, int r) {
    int t = lg[r - l + 1];
    int x = rev_tim[t] - p1[k];
    if (x & 1) down(k);
    x = swap_tim[t] - p2[k];
    if (x & 1) swap(::t[k].ls, ::t[k].rs);
    p1[k] = rev_tim[t], p2[k] = swap_tim[t];
}

void modify(int k, int l, int r, int p, int v) {
    chk(k, l, r);
    if (l == r) { t[k].s = v; return; }
    if (t[k].rev) pushdown(k);
    mid >= p ? modify(t[k].ls, l, mid, p, v) : modify(t[k].rs, mid + 1, r, p, v);
    t[k].s = t[t[k].ls].s + t[t[k].rs].s;
}

long long query(int k, int l, int r, int ql, int qr) {
    chk(k, l, r);
    if (l >= ql && r <= qr) return t[k].s;
    if (t[k].rev) pushdown(k);
    long long s = 0;
    if (mid >= ql) s = query(t[k].ls, l, mid, ql, qr);
    if (mid < qr) s += query(t[k].rs, mid + 1, r, ql, qr);
    return s;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= 1 << n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= 1 << n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    build(1, 1, 1 << n);
    for (int i = 1, op, x, y; i <= q; i++) {
        scanf("%d %d", &op, &x);
        if (op == 1) {
            scanf("%d", &y);
            modify(1, 1, 1 << n, x, y);
        } else if (op == 2) {
            rev_tim[x]++;
        } else if (op == 3) {
            swap_tim[x + 1]++;
        } else {
            scanf("%d", &y);
            printf("%lld\n", query(1, 1, 1 << n, x, y));
        }
    }
    return 0;
}