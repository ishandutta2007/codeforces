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
        int m, l, r;
    };

    node combine(node x, node y) {
        int k = min(x.l, y.r);
        return {x.m+y.m+k, x.l+y.l-k, x.r+y.r-k};
    }

    constexpr static node identity = {0, 0, 0};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree(string v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = (v[i-n] == '(') ? node{0, 1, 0} : node{0, 0, 1};
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
    string t; cin >> t;
    segtree s(t);
    int m; cin >> m;
    while (m--) {
        int l, r; cin >> l >> r; l--, r--;
        cout << 2*s.query(l, r).m << "\n";
    }
}