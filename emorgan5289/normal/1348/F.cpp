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

struct segtree1 {

    using node = array<int, 3>;

    node combine(node x, node y) {
        return min(x, y);
    }

    constexpr static node identity = {inf, -1, -1};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree1(vector<array<int, 3>>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n][1], v[i-n][2], i-n};
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

    void clr(int i) {
        tree[i+n] = identity;
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

struct segtree2 {

    using node = array<int, 3>;

    node combine(node x, node y) {
        return max(x, y);
    }

    constexpr static node identity = {-inf, -1, -1};

    vector<int> a, b;
    vector<node> tree;
    int n;

    segtree2(vector<array<int, 3>>& v) {

        n = 1<<int(ceil(log2(v.size())));
        tree.resize(2*n);
        a.resize(2*n); b.resize(2*n);

        for (int i = 2*n-1; i > 0; i--) {
            if (i >= n) {
                a[i] = b[i] = i-n;
                if (i-n < v.size()) {
                    tree[i] = {v[i-n][1], v[i-n][2], i-n};
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

    void clr(int i) {
        tree[i+n] = identity;
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

const int N = 2e5+5;
array<int, 3> a[N];
int p[N], r[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1], a[i][2] = i;
    sort(a, a+n);
    auto v = vector(a, a+n);
    segtree1 s(v);
    for (int i = 1; i <= n; i++) {
        auto [x, j, k] = s.query(0, upper_bound(a, a+n, array<int, 3>{i, inf, inf})-a-1);
        p[i-1] = j, s.clr(k);
    }
    for (int i = 0; i < n; i++)
        r[p[i]] = i+1;
    sort(a, a+n, [&](auto x, auto y){return r[x[2]] < r[y[2]];});
    v = vector(a, a+n);
    segtree2 q(v);
    for (int i = 0; i < n; i++) {
        debug(a[i][0]-1, i-1);
        auto [x, j, k] = q.query(a[i][0]-1, i-1);
        debug(i, x, j, k);
        if (k == -1) continue;
        if (x > i) {
            cout << "NO\n";
            for (int l = 0; l < n; l++)
                cout << r[l] << " \n"[l == n-1];
            for (int l = 0; l < n; l++) {
                if (r[l]-1 == i) cout << k+1 << " \n"[l == n-1];
                else if (r[l]-1 == k) cout << i+1 << " \n"[l == n-1];
                else cout << r[l] << " \n"[l == n-1];
            }
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << r[i] << " \n"[i == n-1];
}