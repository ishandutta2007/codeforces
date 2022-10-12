#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    using node = array<ll, 4>;

    node combine(node x, node y) {
        pair<ll, ll> v[4] = {{x[0], x[2]}, {x[1], x[3]}, {y[0], y[2]}, {y[1], y[3]}};
        sort(v, v+4, greater<>());
        return {v[0].first, v[1].first, v[0].second, v[1].second};
    }

    constexpr static node identity = {-inf_ll, -inf_ll, -1, -1};

    vector<ll> a, b;
    vector<node> tree;
    ll n;

    segtree(vector<ll>& v) {

        n = 1<<ll(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (ll i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n], -inf_ll, i-n, -1};
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

    node query(ll l, ll r, ll i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

const ll N = 2e5+5;
ll p[N], d[N], h[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < n; i++)
        cin >> d[i], d[i+n] = d[i];
    for (ll i = 0; i < n; i++)
        cin >> h[i], h[i+n] = h[i];
    for (ll i = 1; i < 2*n; i++)
        p[i] = p[i-1]+d[i-1];
    vector<ll> v1(2*n), v2(2*n);
    for (ll i = 0; i < 2*n; i++)
        v1[i] = 2*h[i]+p[i], v2[i] = 2*h[i]-p[i];
    segtree s1(v1), s2(v2);
    while (m--) {
        ll a, b; cin >> b >> a; b -= 2;
        if (b < a) b += n;
        auto [x1, x2, i1, i2] = s1.query(a, b);
        auto [y1, y2, j1, j2] = s2.query(a, b);
        ll ans = i1 == j1 ? max(x1+y2, x2+y1) : x1+y1;
        cout << ans << "\n";
    }
}