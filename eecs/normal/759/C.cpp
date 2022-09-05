#include <bits/stdc++.h>
using namespace std;

typedef array<int, 2> node;
const int maxn = 100010;
int m, p[maxn], a[maxn];
node t[maxn << 2];

node merge(node l, node r) {
    if (!l[0] && !l[1]) return r;
    if (!r[0] && !r[1]) return l;
    // )))((( + ))((
    if (l[1] > r[0]) return node{l[0], l[1] - r[0] + r[1]};
    return node{l[0] + r[0] - l[1], r[1]};
}

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
void upd(int k, int l, int r, int p, node v) {
    if (l == r) { t[k] = v; return; }
    mid >= p ? upd(ls, l, mid, p, v) : upd(rs, mid + 1, r, p, v);
    t[k] = merge(t[ls], t[rs]);
}

node query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return merge(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

int main() {
    scanf("%d", &m);
    for (int i = 1, p, type; i <= m; i++) {
        scanf("%d %d", &p, &type);
        if (!type) {
            upd(1, 1, m, p, node{1, 0});
        } else {
            scanf("%d", &a[p]);
            upd(1, 1, m, p, node{0, 1});
        }
        int l = 1, r = m, ans = -1;
        while (l <= r) {
            auto p = query(1, 1, m, mid, m);
            if (p[1]) l = (ans = mid) + 1;
            else r = mid - 1;
        }
        printf("%d\n", ~ans ? a[ans] : -1);
    }
    return 0;
}