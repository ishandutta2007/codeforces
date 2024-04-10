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

struct segtree {

    struct node {
        ll l, r, v1, v2, v3;
    };

    node combine(node x, node y) {
        ll v1, v2 = -inf_ll, v3 = inf_ll;
        if (x.r >= 0 && y.l <= 0) v1 = inf_ll;
        if (x.r < 0 && y.l > 0) {
            v1 = -inf_ll;
            v2 = x.r, v3 = y.l;
        }
        if (x.r >= 0 && y.l > 0) v1 = -y.l;
        if (x.r < 0 && y.l <= 0) v1 = x.r;
        if (x.v2 != -inf_ll) v2 = x.v2, v3 = x.v3;
        if (y.v2 != -inf_ll) v2 = y.v2, v3 = y.v3;
        return {x.l, y.r, max(max(x.v1, y.v1), v1), v2, v3};
    }

    constexpr static node identity = {inf_ll, -inf_ll, -inf_ll, -inf_ll, inf_ll};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<ll>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n], v[i-n], -inf_ll, -inf_ll, inf_ll};
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

    void update(int i, int x) {
        tree[i+n].l += x;
        tree[i+n].r += x;
        for (i = (i+n)/2; i > 0; i /= 2)
            tree[i] = combine(tree[2*i], tree[2*i+1]);
    }

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

ll f = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n), d(n+1);
    for (auto& x : a) cin >> x;
    for (int i = 1; i < n; i++) {
        d[i] = a[i]-a[i-1];
        f += abs(d[i]);
    }
    segtree s(d);
    int q; cin >> q;
    while (q--) {
        ll t, l, r, x; cin >> t >> l >> r >> x;
        if (t == 1) {
            ll g = -inf_ll;
            if (l == 1) g = max(g, abs(-x+d[1])-abs(d[1]));
            if (r == n) g = max(g, abs(x+d[n-1])-abs(d[n-1]));
            auto node = s.query(l-1, r);
            // debug(g);
            if (node.v1 != -inf_ll) g = max(g, node.v1 == inf_ll ? 2*x : x+abs(x+node.v1)-abs(node.v1));
            // debug(node.v1, node.v2, node.v3);
            // debug(g);
            if (node.v1 != inf_ll)
                g = max(g, abs(x+node.v2)-abs(node.v2)+abs(-x+node.v3)-abs(node.v3));
            // debug(g);
            // for (int i = 1; i < 2*s.n; i++)
            //     debug(s.tree[i].l, s.tree[i].r, s.tree[i].v1);
            cout << g+f << "\n";
        } else {
            if (l > 1) f -= abs(d[l-1]), d[l-1] += x, f += abs(d[l-1]);
            if (r < n) f -= abs(d[r]), d[r] -= x, f += abs(d[r]);
            if (l > 1) s.update(l-1, x);
            if (r < n) s.update(r, -x);
        }
    }
}