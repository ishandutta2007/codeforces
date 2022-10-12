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
        int f[30];
    };

    node combine(node x, node y) {
        node z = {{}};
        for (int i = 0; i < 30; i++)
            z.f[i] = x.f[i]+y.f[i];
        return z;
    }

    constexpr static node identity = {{}};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(vector<int>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = node{{}};
                    for (int j = 0; j < 30; j++)
                        if (v[i-n]&(1<<j)) tree[i].f[j]++;
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
        if (u[i] == 0) return;
        for (int j = 0; j < 30; j++)
            if (u[i]&(1<<j))
                tree[i].f[j] = b[i]-a[i]+1-tree[i].f[j];
        if (i < n) {
            u[2*i] ^= u[i];
            u[2*i+1] ^= u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] ^= x;
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
            return;
        update(l, r, x, 2*i);
        update(l, r, x, 2*i+1);
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    segtree s(a);
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; cin >> l >> r; l--, r--;
            auto node = s.query(l, r);
            ll x = 0;
            for (int i = 0; i < 30; i++) {
                // debug(i, node.f[i]);
                x += (1ll<<i)*(ll)node.f[i];
            }
            cout << x << "\n";
        } else {
            int l, r, x; cin >> l >> r >> x; l--, r--;
            s.update(l, r, x);
        }
    }
}