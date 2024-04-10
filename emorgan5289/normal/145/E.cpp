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
        int m0, m1, c0, c1;
    };

    node combine(node x, node y) {
        return {max(x.m0+y.c1, y.m0+x.c0), max(x.m1+y.c0, y.m1+x.c1), x.c0+y.c0, x.c1+y.c1};
    }

    constexpr static node identity = {0, 0, 0};

    vector<int> a, b;
    vector<node> tree;
    vector<bool> u;
    int n;

    segtree(vector<bool>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = v[i-n] ? node{1, 1, 0, 1} : node{1, 1, 1, 0};
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
        swap(tree[i].c0, tree[i].c1);
        swap(tree[i].m0, tree[i].m1);
        if (i < n) {
            u[2*i] = !u[2*i];
            u[2*i+1] = !u[2*i+1];
        }
        u[i] = 0;
    }

    void update(int l, int r, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] = !u[i];
        }
        push(i);
        if (l > b[i] || r < a[i] || l <= a[i] && r >= b[i])
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
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;
    vector<bool> a(n);
    for (int i = 0; i < n; i++) {
        char c; cin >> c; a[i] = c == '7';
    }
    segtree s(a);
    for (int i = 0; i < m; i++) {
        string c; cin >> c;
        if (c == "switch") {
            int x, y; cin >> x >> y;
            s.update(x-1, y-1);
        } else {
            cout << s.query(0, n-1).m0 << "\n";
        }
    }
}