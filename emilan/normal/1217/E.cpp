#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kInf = 1e9;

struct SegTree {
    using Node = array<array<int, 2>, 9>;

    Node combine(const Node &x, const Node &y) {
        Node r;
        for (int i = 0; i < SZ(r); i++) {
            array<int, 4> tmp;
            merge(ALL(x[i]), ALL(y[i]), begin(tmp));
            copy(begin(tmp), begin(tmp) + 2, begin(r[i]));
        }
        return r;
    }

    Node make_node(int x0) {
        Node r;
        for (int i = 0, x = x0; i < SZ(r); i++, x /= 10) {
            r[i] = {kInf, kInf};
            if (x % 10 > 0) r[i][0] = x0;
        }
        return r;
    }

    int n;
    vector<Node> a;

    SegTree(const vector<int> &a_) : n(SZ(a_)), a(2 * n) {
        for (int i = 0; i < n; i++) {
            a[i + n] = make_node(a_[i]);
        }
        for (int i = n - 1; i > 0; i--) {
            a[i] = combine(a[2 * i], a[2 * i + 1]);
        }
    }

    int query(int l, int r) {
        Node ans = make_node(0);
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) ans = combine(ans, a[l++]);
            if (r & 1) ans = combine(ans, a[--r]);
        }

        int min_ = INT_MAX;
        for (auto &v : ans) if (v[1] != kInf) {
            min_ = min(min_, v[0] + v[1]);
        }

        return min_ == INT_MAX ? -1 : min_;
    }

    void update(int i, int x) {
        for (a[i += n] = make_node(x); i /= 2;) {
            a[i] = combine(a[2 * i], a[2 * i + 1]);
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegTree sgt(a);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            sgt.update(i - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << sgt.query(l - 1, r) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}