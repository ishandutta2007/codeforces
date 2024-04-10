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

template<int N>
struct fenwick_multiset {

    int s = 0, tree[N+1] = {};
    int size() const { return s; }
    
    // insert x into the set with multiplicity k
    void insert(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] += k;
        s += k;
    }

    // remove x from the set with multiplicity k
    void remove(int x, const int k = 1) {
        for (x++; x <= N; x += x & -x)
            tree[x] -= k;
        s -= k;
    }

    // returns the number of elements in
    // the set which are strictly lower than x
    int index(int x) const {
        int i = 0;
        for (; x > 0; x -= x & -x)
            i += tree[x];
        return i;
    }

    // returns the number of elements in the set
    // which are exactly equal to x, O(1) amortized
    int count(int x) const {
        int y = x+1, i = tree[x+1];
        for (y -= y & -y; x != y; x -= x & -x)
            i -= tree[x];
        return i;
    }

    // returns the x'th element of the set,
    // 0-based indexing
    int get(int x) const {
        int i = 0;
        for (int m = 1<<(31-__builtin_clz(N)); m > 0; m >>= 1)
            if (i+m <= N && tree[i+m] <= x)
                x -= tree[i += m];
        return i;
    }
};

struct segtree {

    struct node {
        int x, i;
    };

    node combine(node x, node y) {
        if (x.x == y.x) return x.i > y.i ? x : y;
        return x.x > y.x ? x : y;
    }

    constexpr static node identity = {-inf, -1};

    vector<int> a, b;
    vector<node> tree;
    vector<int> u;
    int n;

    segtree(vector<int> v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);
        u.assign(2*n, 0);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n], i-n};
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
        tree[i].x += u[i];
        if (i < n) {
            u[2*i] += u[i];
            u[2*i+1] += u[i];
        }
        u[i] = 0;
    }

    void update(int l, int r, int x, int i = 1) {
        if (l <= a[i] && r >= b[i]) {
            u[i] += x;
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

const int N = 3e5+5;
vector<array<int, 2>> qry[N];
int a[N], r[N];
fenwick_multiset<N> f;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] -= i+1;
    for (int i = 0; i < q; i++) {
        int x, y; cin >> x >> y; y = n-y;
        qry[x].pb({y, i});
    }
    vector<int> vec(n, -inf);
    segtree s(vec);
    for (int i = n-1; i >= 0; i--) {
        s.update(i, i, inf+a[i]);
        while (1) {
            auto [v, j] = s.query(i, n-1);
            debug(v, j);
            if (v < 0) break;
            s.update(j, j, -inf-v);
            if (v == 0) {
                s.update(j+1, n-1, 1);
                f.insert(j);
                debug(j);
            }
        }
        for (auto& [y, j] : qry[i]) {
            r[j] = f.index(y);
            debug(y, j, r[j]);
        }
    }
    for (int i = 0; i < q; i++)
        cout << r[i] << "\n";
}