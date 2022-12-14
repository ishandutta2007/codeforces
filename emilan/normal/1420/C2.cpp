#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

struct SegTree {
    int n;
    vt<vt<ll>> st;

    SegTree(int _n) : n(1 << __lg(_n * 2 - 1)), st(n << 1, vt<ll>(4)) {}

    ll query_all() { return *max_element(all(st[1])); }

    void update(int i, int v) {
        i += n;
        st[i][3] = v;
        st[i][0] = -v;
        while (i >>= 1) {
            for (int j = 0; j < 4; j++) {
                st[i][j] = max(
                    st[i << 1][0 | j & 2] + st[i << 1 | 1][2 | j & 1],
                    st[i << 1][1 | j & 2] + st[i << 1 | 1][0 | j & 1]
                );
            }
        }
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    SegTree st(n);
    for (int i = 0; i < n; i++) {
        st.update(i, a[i]);
    }

    cout << st.query_all() << '\n';

    while (q--) {
        int x, y;
        cin >> x >> y;

        swap(a[--x], a[--y]);
        st.update(x, a[x]);
        st.update(y, a[y]);
        cout << st.query_all() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}