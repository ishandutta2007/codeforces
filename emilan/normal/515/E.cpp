#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct node {
    ll l, r, h, d;

    node operator+(const node &o) const {
        return {
            max(l + o.d, o.l),
            max(r, d + o.r),
            max({l + o.r, h, o.h}),
            d + o.d
        };
    }
};

const int N = 2e5, K = 18;
node sp[K][N];

ll query(int l, int r) {
    node m{};
    while (l < r) {
        int k = __lg(r - l);
        m = m + sp[k][l];
        l += 1 << k;
    }
    return m.h;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> d(n), h(n);
    for (int &x : d) cin >> x;
    for (int &x : h) cin >> x;

    for (int i = 0; i < 2 * n; i++) {
        sp[0][i] = {
            2ll * h[i % n] + d[i % n],
            2ll * h[i % n],
            0,
            d[i % n],
        };
    }

    for (int k = 0; k < K - 1; k++) {
        for (int i = 0; i <= 2 * n - (2 << k); i++) {
            sp[k + 1][i] = sp[k][i] + sp[k][i + (1 << k)];
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l <= r) {
            cout << query(r + 1, n + l) << '\n';
        } else {
            cout << query(r + 1, l) << '\n';
        }
    }
}