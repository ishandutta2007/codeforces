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
        // cheapest cost to remove this stuff 
        ll a, b, c;
        ll ab, bc;
        ll abc;
    };

    node combine(node x, node y) {
        node z;
        z.a = x.a+y.a;
        z.b = x.b+y.b;
        z.c = x.c+y.c;
        z.ab = min(x.a+y.ab, x.ab+y.b);
        z.bc = min(x.b+y.bc, x.bc+y.c);
        z.abc = min(min(x.a+y.abc, x.ab+y.bc), x.abc+y.c);
        return z;
    }

    const node identity = {0, 0, 0, 0, 0, 0};

    vector<int> a, b;
    vector<node> tree;
    int n;

    node from_char(char c) {
        if (c == 'a')
            return {1, 0, 0, 0, 0, 0};
        if (c == 'b')
            return {0, 1, 0, 0, 0, 0};
        return {0, 0, 1, 0, 0, 0};
    }

    segtree(string& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = from_char(v[i-n]);
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

    void upd(int i, char c) {
        tree[n+i] = from_char(c);
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
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    segtree t(s);
    while (q--) {
        ll x; cin >> x; x--;
        char c; cin >> c;
        t.upd(x, c);
        cout << t.tree[1].abc << "\n";
    }
}