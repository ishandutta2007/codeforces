#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

struct SegTree {
    int n;
    vector<pii> a;

    int t = 0;

    SegTree(int m) : n(m), a(2 * n) {
        for (int i = 0; i < n; i++) {
            touch(i + n, n);
        }
    }

    void touch(int i, int x) {
        a[i] = {++t, x};
    }

    int query(int i) {
        pii r;
        for (i += n; i > 0; i /= 2) {
            r = max(r, a[i]);
        }
        return r.second;
    }

    void update(int l, int r, int u) {
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) touch(l++, u);
            if (r & 1) touch(--r, u);
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> a(2 * n);
    for (int &x : a) cin >> x;

    SegTree seg(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            x--, y--;
            seg.update(y, y + k, x - y);
        } else {
            int i;
            cin >> i;
            i--;
            cout << a[i + seg.query(i)] << '\n';
        }
    }
}