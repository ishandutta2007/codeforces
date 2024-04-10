#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = (ll)1e18;
const int N = (int)1e6;
const int M = (int) 1e6;
int q;
struct node {
    int cnt;
    ll sum;
    ll add;
    ll value;
    node(): cnt(0), sum(0), add(0), value(-INF) {

    }
    node(int ncnt, ll nsum, ll nadd, ll nvalue): cnt(ncnt), sum(nsum), add(nadd), value(nvalue) {

    }
};
node tr[N * 5];
int t[N], d[N];
node unite(node a, node b) {
    node c = node(a.cnt + b.cnt, a.sum + b.sum, 0, max(a.value, b.value));
    return c;
}
void build(int v, int l, int r) {
    if (l == r) {
        tr[v] = node(0, 0, 0, -INF);
        return;
    }
    int mid = (r + l) / 2;
    build(v * 2, l, mid);
    build(v * 2 + 1, mid + 1, r);
    tr[v] = unite(tr[v * 2], tr[v * 2 + 1]);
}
void push(int v, ll add) {
    for (int j = 0; j < 2; j++) {
        tr[v * 2 + j].value += add;
        tr[v * 2 + j].add += add;
    }
}
void check(int v, int l, int r) {
    if (tr[v].add != 0) {
        if (l == r) {
            tr[v].add = 0;
        } else {
            push(v, tr[v].add);
            tr[v].add = 0;
        }
    }
}
void upd(int v, int l, int r, int t, int c, ll x, ll d) {
    check(v, l, r);
    if (l == r) {
        tr[v].cnt = c;
        tr[v].sum = d;
        tr[v].value = x;
        return;
    }
    int mid = (r + l) / 2;
    if (t <= mid) upd(v * 2, l, mid, t, c, x, d);
    if (t > mid) upd(v * 2 + 1, mid + 1, r, t, c, x, d);
    tr[v] = unite(tr[v * 2], tr[v * 2 + 1]);
}
void add(int v, int l, int r, int ll, int rr, int d) {
    if (ll > rr) {
        return;
    }
    check(v, l, r);
    if (ll <= l && r <= rr) {
        tr[v].add += d;
        tr[v].value += d;
        return;
    }
    int mid = (r + l) / 2;
    if (ll <= mid) add(v * 2, l, mid, ll, rr, d);
    if (rr > mid) add(v * 2 + 1, mid + 1, r, ll, rr, d);
    tr[v] = unite(tr[v * 2], tr[v * 2 + 1]);
}
node get(int v, int l, int r, int ll, int rr) {
    check(v, l, r);
    if (ll <= l && r <= rr) {
        return tr[v];
    }
    node q = node(0, 0, 0, -INF);
    int mid = (r + l) / 2;
    if (ll <= mid) q = unite(q, get(v * 2, l, mid, ll, rr));
    if (rr > mid) q = unite(q, get(v * 2 + 1, mid + 1, r, ll, rr));
    tr[v] = unite(tr[v * 2], tr[v * 2 + 1]);
    return q;
}
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    build(1, 1, M);
    for (int it = 1; it <= q; it++) {
        char c;
        cin >> c;
        if (c == '?') {
            int t;
            cin >> t;
            node q = get(1, 1, M, 1, t);
            ll r = q.value + q.sum;
            cout << max(0ll, r - t) << "\n";
        }
        else if (c == '+') {
            cin >> t[it] >> d[it];
            node q = get(1, 1, M, 1, t[it]);
            upd(1, 1, M, t[it], 1, t[it] - q.sum, d[it]);
            add(1, 1, M, t[it] + 1, M, -d[it]);

        }
        else if (c == '-') {
            int i;
            cin >> i;
            upd(1, 1, M, t[i], 0, -INF, 0);
            add(1, 1, M, t[i] + 1, M, d[i]);
        }
    }
    return 0;
}