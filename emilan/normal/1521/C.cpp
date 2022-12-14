#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n;
    cin >> n;
    assert(n != -1);

    auto query = [&](int t, int i, int j, int x) -> int {
        cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
        int r;
        cin >> r;
        assert(r != -1);
        return r;
    };

    int k;
    vector<int> ans(n); {
        int l = 0, r = n;
        int i = 0, j = 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;

            int p = query(1, i, j, m);
            int q = query(2, i, j, m);

            if (p > q) i = 1, j = 0;
            else if (q >= m + 1) l = m;
            else r = m;
        }

        k = i;
        ans[k] = r;
    }

    for (int i = 0; i < n; i++) if (i != k) {
        if (ans[k] <= n / 2) {
            int p = query(1, k, i, n - 1);

            if (p > ans[k]) {
                ans[i] = p;
            } else {
                int q = query(2, i, k, 1);

                ans[i] = q;
                k = i;
            }
        } else {
            int q = query(2, i, k, 1);

            if (q < ans[k]) {
                ans[i] = q;
            } else {
                int p = query(1, k, i, n - 1);

                ans[i] = p;
                k = i;
            }
        }
    }

    cout << '!';
    for (int i : ans) cout << ' ' << i;
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}