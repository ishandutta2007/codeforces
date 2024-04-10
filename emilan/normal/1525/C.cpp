#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> pos0, pos1;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        int x;
        if (c == 'R') x = a[i];
        else x = 2 * m - a[i];

        if (x & 1) pos1[x] = i;
        else pos0[x] = i;
    }

    vector<int> ans(n);

    auto f = [&](map<int, int> &pos) -> void {
        while (!pos.empty()) {
            if (pos.size() == 1) {
                ans[pos.begin()->second] = -1;

                break;
            }

            auto it = pos.begin();
            auto [x, i] = *it;

            auto it1 = pos.upper_bound(2 * m - x);
            if (it1 == pos.begin()) {
                it1 = --pos.end();
            } else {
                it1--;
                if (it1 == it) it1 = --pos.end();
            }
            auto [x1, i1] = *it1;

            decltype(it) it2;
            if ((x < m && x1 < m) || (x > m && x1 > m) || (x + x1 > 2 * m)) {
                it2 = it1;
            } else {
                it2 = pos.upper_bound(2 * m - x1);
            }
            it2--;
            auto [x2, i2] = *it2;

            int t = (4 * m - x1 - x2) % (2 * m) / 2;
            ans[i1] = ans[i2] = t;

            pos.erase(it1);
            pos.erase(it2);
        }
    };

    f(pos0);
    f(pos1);

    for (int i : ans) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}