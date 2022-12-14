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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) return void(cout << "NO");

    cout << "YES\n";
    vt<pair<int, string>> ops;

    auto insert = [&](int i, string s) {
        if (i <= 0) return;

        if (k >= i * sz(s)) {
            ops.emplace_back(i, s);
            k -= i * sz(s);
        } else {
            if (k >= sz(s))
                ops.emplace_back(k / sz(s), s);
            if (k % sz(s))
                ops.emplace_back(1, s.substr(0, k % sz(s)));
            k = 0;
        }
    };

    auto run = [&]() {
        insert(m - 1, "R");
        for (int i = 1; i < n; i++) {
            insert(1, "D");
            if (i & 1) insert(m - 1, "LUD");
            else insert(m - 1, "RUD");
        }
        for (int i = n - 1; ~i; i--) {
            if (i & 1) insert(m - 1, "R");
            else insert(m - 1, "L");
            if (i) insert(1, "U");
        }
    };
    run();

    cout << sz(ops) << '\n';
    for (auto &op : ops) {
        cout << op.fi << ' ' << op.se << '\n';
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