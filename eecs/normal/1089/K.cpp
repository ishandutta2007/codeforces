#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010, maxt = 1000010;
int q, x[maxn], y[maxn];
array<ll, 2> t[maxt << 2];

#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
array<ll, 2> operator + (array<ll, 2> a, array<ll, 2> b) {
    return {max(a[0] + b[1], b[0]), a[1] + b[1]};
}

void build(int k, int l, int r) {
    if (l == r) { t[k] = {l, 0}; return; }
    build(ls, l, mid), build(rs, mid + 1, r);
    t[k] = t[ls] + t[rs];
}

void modify(int k, int l, int r, int p, int v) {
    if (l == r) { t[k][0] += v, t[k][1] += v; return; }
    if (mid >= p) modify(ls, l, mid, p, v);
    else modify(rs, mid + 1, r, p, v);
    t[k] = t[ls] + t[rs];
}

array<ll, 2> query(int k, int l, int r, int ql, int qr) {
    if (l >= ql && r <= qr) return t[k];
    if (mid >= qr) return query(ls, l, mid, ql, qr);
    if (mid < ql) return query(rs, mid + 1, r, ql, qr);
    return query(ls, l, mid, ql, qr) + query(rs, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> q;
    build(1, 1, 1000000);
    for (int i = 1; i <= q; i++) {
        char op;
        cin >> op >> x[i];
        if (op == '+') {
            cin >> y[i];
            modify(1, 1, 1000000, x[i], y[i]);
        } else if (op == '-') {
            modify(1, 1, 1000000, x[x[i]], -y[x[i]]);
        } else {
            cout << query(1, 1, 1000000, 1, x[i])[0] - x[i] << "\n";
        }
    }
    return 0;
}