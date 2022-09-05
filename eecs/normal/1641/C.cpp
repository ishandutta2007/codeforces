#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, q, mn[maxn << 2], lb[maxn], rb[maxn];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p, int v) {
    if (l == r) { mn[k] = min(mn[k], v); return; }
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    mn[k] = min(mn[ls], mn[rs]);
}

int query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return mn[k];
    int s = INT_MAX;
    if (mid >= ql) s = query(ls, l, mid, ql, qr);
    if (mid < qr) s = min(s, query(rs, mid + 1, r, ql, qr));
    return s;
}

int find1(int x) {
    return x == lb[x] ? x : lb[x] = find1(lb[x]);
}

int find2(int x) {
    return x == rb[x] ? x : rb[x] = find2(rb[x]);
}

int main() {
    scanf("%d %d", &n, &q);
    memset(mn, 0x3f, sizeof(mn));
    iota(lb, lb + n + 1, 0), iota(rb, rb + n + 1, 0);
    while (q--) {
        int op, l, r, x;
        scanf("%d", &op);
        if (!op) {
            scanf("%d %d %d", &l, &r, &x), l--;
            if (!x) {
                for (int i = find1(r); i > l; i = find1(i)) {
                    lb[i] = i - 1;
                }
                for (int i = find2(l); i < r; i = find2(i)) {
                    rb[i] = i + 1;
                }
            } else {
                upd(1, 0, n, l, r);
            }
        } else {
            scanf("%d", &x);
            if (find1(x) == find1(x - 1)) {
                puts("NO");
            } else {
                int l = find1(x - 1), r = find2(x);
                if (query(1, 0, n, l, x - 1) <= r) puts("YES");
                else puts("N/A");
            }
        }
    }
    return 0;
}