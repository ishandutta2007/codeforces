#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 131072;
ll n, m, x;

struct node {
    ll cnt = 0; // number of inner intervals
    vector<ll> lv, rv, lw, rw; // values and widths of prefixes and suffixes
};

node merge(node a, node b) {
    node c;

    if (a.lw.empty()) return b;
    if (b.lw.empty()) return a;

    c.cnt = a.cnt+b.cnt;

    int j = a.rv.size()-1;
    ll pl = 0;
    // debug(a.rv, b.lv);
    // debug(a.cnt, b.cnt);
    for (int i = 0; i < b.lv.size(); i++) {
        while (j >= 0 && (a.rv[j]|b.lv[i]) >= x) pl += a.rw[j--];
        // debug(i, j);
        // debug(pl, b.lw[i]);
        c.cnt += pl*b.lw[i];
    }

    // debug(c.cnt);

    c.lv = a.lv, c.lw = a.lw;
    c.rv = b.rv, c.rw = b.rw;

    for (int i = 0; i < b.lv.size(); i++) {
        if ((b.lv[i]|c.lv.back()) == c.lv.back())
            c.lw.back() += b.lw[i];
        else
            c.lw.pb(b.lw[i]), c.lv.pb(b.lv[i]|c.lv.back());
    }

    for (int i = 0; i < a.rv.size(); i++) {
        if ((a.rv[i]|c.rv.back()) == c.rv.back())
            c.rw.back() += a.rw[i];
        else
            c.rw.pb(a.rw[i]), c.rv.pb(a.rv[i]|c.rv.back());
    }

    return c;
}

node from_one(ll v) {
    node c;
    c.cnt = v >= x ? 1 : 0;
    c.lv = c.rv = {v};
    c.lw = c.rw = {1};
    return c;
}

node tree[2*N];
int a[2*N], b[2*N];

node query(int l, int r, int i) {
    // debug(l, r, a[i], b[i], i);
    if (l <= a[i] && r >= b[i])
        return tree[i];
    if (l > b[i] || r < a[i])
        return {0, {}, {}, {}, {}};
    return merge(query(l, r, 2*i), query(l, r, 2*i+1));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        ll v; cin >> v;
        tree[N+i] = from_one(v);
    }
    for (int i = 0; i < N; i++)
        a[N+i] = b[N+i] = i;
    for (int i = N-1; i > 0; i--) {
        tree[i] = merge(tree[2*i], tree[2*i+1]);
        a[i] = a[2*i], b[i] = b[2*i+1];
    }
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            ll i, v; cin >> i >> v; i--;
            tree[N+i] = from_one(v);
            for (i = (N+i)/2; i > 0; i >>= 1)
                tree[i] = merge(tree[2*i], tree[2*i+1]);
        } else {
            ll l, r; cin >> l >> r; l--, r--;
            auto c = query(l, r, 1);
            debug(c.lv, c.lw);
            cout << c.cnt << "\n";
        }
    }
}