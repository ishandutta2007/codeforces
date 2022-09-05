#include <bits/stdc++.h>
#define mid (l + r >> 1)
using namespace std;

const int maxn = 100010;
int q, cnt, tot1, tot2, rt1[maxn], rt2[maxn];
string op, s;
map<string, int> tmp;
struct node { int l, r, s; } t1[maxn << 6], t2[maxn << 6];

void add(node *t, bool f, int& k1, int k2, int l, int r, int p, int v) {
    t[k1 = !f ? ++tot1 : ++tot2] = t[k2], t[k1].s += v;
    if (l == r) return;
    if (mid >= p) add(t, f, t[k1].l, t[k2].l, l, mid, p, v);
    else add(t, f, t[k1].r, t[k2].r, mid + 1, r, p, v);
}

int query(node *t, int k, int l, int r, int ql, int qr) {
    assert(ql <= qr && (l <= qr || r >= ql));
    if (l >= ql && r <= qr) return t[k].s; int s = 0;
    if (mid >= ql && t[k].l) s += query(t, t[k].l, l, mid, ql, qr);
    if (mid < qr && t[k].r) s += query(t, t[k].r, mid + 1, r, ql, qr);
    return s;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> q;
    for (int i = 1, x; i <= q; i++) {
        cin >> op;
        if (op[0] == 's') {
            cin >> s >> x;
            if (!tmp.count(s)) tmp[s] = ++cnt;
            int num = query(t2, rt2[i - 1], 0, q, tmp[s], tmp[s]); 
            if (num) {
                add(t1, 0, rt1[i], rt1[i - 1], 0, 1e9, num, -1);
            }
            add(t1, 0, rt1[i], rt1[i] ? rt1[i] : rt1[i - 1], 0, 1e9, x, 1);
            add(t2, 1, rt2[i], rt2[i - 1], 0, q, tmp[s], x - num);
        } else if (op[0] == 'r') {
            cin >> s;
            if (!tmp.count(s)) tmp[s] = ++cnt;
            int num = query(t2, rt2[i - 1], 0, q, tmp[s], tmp[s]); 
            if (num) {
                add(t1, 0, rt1[i], rt1[i - 1], 0, 1e9, num, -1);
                add(t2, 1, rt2[i], rt2[i - 1], 0, q, tmp[s], -num);
            } else {
                rt1[i] = rt1[i - 1], rt2[i] = rt2[i - 1];
            }
        } else if (op[0] == 'q') {
            cin >> s;
            if (!tmp.count(s)) tmp[s] = ++cnt;
            rt1[i] = rt1[i - 1], rt2[i] = rt2[i - 1];
            int num = query(t2, rt2[i], 0, q, tmp[s], tmp[s]);
            if (!num) cout << -1 << endl;
            else cout << query(t1, rt1[i], 0, 1e9, 0, num - 1) << endl;
            cout << flush;
        } else {
            cin >> x;
            rt1[i] = rt1[i - x - 1], rt2[i] = rt2[i - x - 1];
        }
    }
    return 0;
}