#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;

void solve() {
    i64 n, m, k;
    cin >> n >> m >> k;

    if (2 * n * m % k) {
        cout << "nO\n";
        return;
    }

    vector<pair<i64, i64>> ans{{0, 0}};
    i64 a = 2 * n * m / k;
    if (n >= m) {
        i64 d = (a + m - 1) / m;
        ans.emplace_back(d, 1);
        ans.emplace_back(m * d - a, m);
    } else {
        i64 d = (a + n - 1) / n;
        ans.emplace_back(1, d);
        ans.emplace_back(n, n * d - a);
    }

    cout << "yEs\n";
    for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}