#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

struct segtree {

    struct node {
        int g, k;
    };

    node combine(node x, node y) {
        int g = gcd(x.g, y.g);
        return {g, (x.g == g ? x.k : 0) + (y.g == g ? y.k : 0)};
    }

    constexpr static node identity = {0, 0};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n], 1};
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

    node query(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i])
            return tree[i];
        if (l > b[i] || r < a[i])
            return identity;
        return combine(query(l, r, 2*i), query(l, r, 2*i+1));
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> v(n); for (auto& x : v) cin >> x;
    segtree s(v);
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << r-l+1-s.query(l, r).k << "\n";
    }
}