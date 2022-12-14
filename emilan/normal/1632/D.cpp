#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    int n_ori;
    int n;
    vector<int> a;

    SegTree(int p_n) : n_ori(p_n), n(1 << __lg(2 * p_n - 1)), a(2 * n) {}

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) res = gcd(res, a[l++]);
            if (r & 1) res = gcd(res, a[--r]);
        }
        return res;
    }

    void update(int i, int u) {
        for (a[i += n] = u; i /= 2;) {
            a[i] = gcd(a[2 * i], a[2 * i + 1]);
        }
    }
};

const int kP = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    SegTree sgt(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = i > 0 ? ans[i - 1] : 0;
        sgt.update(i, a[i]);
        auto f = [&](int p) {
            return sgt.query(p, i + 1) >= i - p + 1;
        };
        int l = -1, r = i + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (f(m)) r = m;
            else l = m;
        }
        if (sgt.query(r, i + 1) == i - r + 1) {
            ans[i]++;
            sgt.update(i, kP);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}