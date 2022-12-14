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

int n, lgn;

struct SegTree {
    vt<ll> a;
    int rev = 0;

    SegTree(vt<int> &v) : a(n << 1) {
        copy(all(v), a.begin() + n);
        for (int i = n - 1; i; i--) {
            a[i] = a[i << 1] + a[i << 1 | 1];
        }
    }

    int get_idx(int i) {
        int lay = lgn - __lg(i);
        for (int k = lay + 1; k <= lgn; k++) {
            if (rev & 1 << k) i ^= (1 << (k - lay)) - 1;
        }
        return i;
    }

    ll query(int l, int r) {
        ll ret = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret += a[get_idx(l++)];
            if (r & 1) ret += a[get_idx(--r)];
        }
        return ret;
    }

    void update(int i, ll v) {
        i = get_idx(i + n);
        for (a[i] = v; i >>= 1;) {
            a[i] = a[i << 1] + a[i << 1 | 1];
        }
    }
};

void solve() {
    int q;
    cin >> lgn >> q;
    n = 1 << lgn;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    SegTree st(a);
    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i, v;
            cin >> i >> v;
            st.update(--i, v);
        } else if (t <= 3) {
            int k;
            cin >> k;
            st.rev ^= 1 << k;
            if (t == 3) st.rev ^= 2 << k;
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.query(--l, r) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}