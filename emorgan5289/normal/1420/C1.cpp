#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e12;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    struct node {
        ll pp, pn, np, nn;
    };

    node combine(node x, node y) {
        return {
            max(x.pp+y.np, x.pn+y.pp),
            max(x.pp+y.nn, x.pn+y.pn),
            max(x.np+y.np, x.nn+y.pp),
            max(x.np+y.nn, x.nn+y.pn),
        };
    }

    constexpr static node identity = {-inf_ll, 0, 0, -inf_ll};

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
                    tree[i] = {v[i-n], 0, 0, -v[i-n]};
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

    void set(int i, ll x) {
        tree[n+i] = {x, 0, 0, -x};
        for (i = (n+i)/2; i > 0; i /= 2)
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        segtree s(a);
        auto v = s.query(0, n-1);
        cout << max(v.pp, v.pn) << "\n";
        while (k--) {
            int l, r; cin >> l >> r; l--, r--;
            swap(a[l], a[r]);
            s.set(l, a[l]), s.set(r, a[r]);
            v = s.query(0, n-1);
            cout << max(v.pp, v.pn) << "\n";
        }
    }
}