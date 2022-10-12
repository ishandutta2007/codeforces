#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

using node = vector<tuple<ll, ll, ll>>;

struct segtree {

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<node>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n];
                } else {
                    tree[i] = {};
                }
            } else {
                a[i] = a[2*i];
                b[i] = b[2*i+1];
                int x = 0, y = 0, t;
                ll a1 = 0, a2 = 0, b1 = 0, b2 = 0, p;
                while (x < tree[2*i].size() || y < tree[2*i+1].size()) {
                    if (x == tree[2*i].size()) t = 1;
                    else if (y == tree[2*i+1].size()) t = 0;
                    else t = tree[2*i+1][y] < tree[2*i][x];
                    if (t) tie(p, a2, b2) = tree[2*i+1][y++];
                    else tie(p, a1, b1) = tree[2*i][x++];
                    if (tree[i].size() > 0 && get<0>(tree[i].back()) == p)
                        tree[i].pop_back();
                    tree[i].pb({p, a1+a2, b1+b2});
                }
            }
        }
    }

    ll one(int i, ll x) {
        auto [_, p, q] = *--lower_bound(all(tree[i]), tuple<ll, ll, ll>{x, -inf_ll, -inf_ll});
        return p*x + q;
    }

    ll query(int l, int r, ll x, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return one(i, x);
        if (l > b[i] || r < a[i])
            return 0;
        return query(l, r, x, 2*i) + query(l, r, x, 2*i+1);
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<node> v(n);
    for (auto& u : v) {
        ll x1, x2, y1, a, b, y2; cin >> x1 >> x2 >> y1 >> a >> b >> y2;
        u.pb({-inf_ll, 0, y1});
        u.pb({x1, a, b});
        u.pb({x2, 0, y2});
    }
    segtree s(v);
    int m; cin >> m;
    ll last = 0;
    while (m--) {
        ll l, r, x; cin >> l >> r >> x; l--, r--;
        last = s.query(l, r, (x+last)%ll(1e9));
        cout << last << "\n";
    }
}