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

struct segtree {

    struct node {
        ll x = 0, w = 0;
    };

    node combine(node x, node y) {
        return {x.x+y.x, x.w+y.w};
    }

    constexpr static node identity = {0, 0};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(int _n) {

        n = 1<<int(ceil(log2(_n)));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < _n) {
                    tree[i] = {0, 1};
                } else {
                    tree[i] = identity;
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                tree[i] = combine(tree[2*i], tree[2*i+1]);
            }
        }
    }

    void push(int i) {
        if (!u[i]) return;
        tree[i].x = tree[i].w-tree[i].x;
        if (i < n) {
            u[2*i] ^= 1;
            u[2*i+1] ^= 1;
        }
        u[i] = 0;
    }

    void update(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] ^= 1;
        }
        push(i);
        if (l > b[i] || r < a[i] || (l <= a[i] && r >= b[i]))
            return;
        update(l, r, 2*i);
        update(l, r, 2*i+1);
        tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        push(i);
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin >> n >> k;
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    sort(all(s));
    segtree b(n);
    vector<vector<ll>> r(n);
    vector<vector<ll>> l(n);
    b.update(0, n-1);
    for (int i = 0; i < k; i++) {
        ll x, y; cin >> x >> y;
        x = lower_bound(all(s), x)-s.begin();
        y = upper_bound(all(s), y)-s.begin()-1;
        if (y < x) continue;
        debug(x, y);
        b.update(x, n-1);
        r[y].pb(x);
        l[x].pb(y);
    }
    vector<ll> v(n);
    ll ans = n*(n-1)*(n-2)/6;
    for (int i = 0; i < n; i++) {
        v[i] += b.query(0, i-1).x;
        debug(i, v[i]);
        for (ll x : r[i])
            b.update(x, n-1);
    }
    b.update(0, n-1);
    for (int i = 0; i < n; i++)
        debug(b.query(i, i).x);
    for (int i = 0; i < n; i++)
        for (ll x : l[i])
            b.update(0, x);
    for (int i = n-1; i >= 0; i--) {
        v[i] += b.query(i+1, n-1).x;
        for (ll x : l[i])
            b.update(0, x);
    }
    for (int i = 0; i < n; i++) {
        debug(i, v[i]);
        ans -= v[i]*(v[i]-1)/2;
    }
    cout << ans << "\n";
}