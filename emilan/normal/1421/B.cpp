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
    int n;
    cin >> n;
    vt<string> s(n);
    for (auto &x : s) cin >> x;

    vt<pii> ops;
    if (s[1][0] == s[0][1]) {
        if (s[n - 1][n - 2] == s[1][0]) ops.emplace_back(n, n - 1);
        if (s[n - 2][n - 1] == s[1][0]) ops.emplace_back(n - 1, n);
    } else if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
        if (s[1][0] == s[n - 1][n - 2]) ops.emplace_back(2, 1);
        if (s[0][1] == s[n - 1][n - 2]) ops.emplace_back(1, 2);
    } else {
        if (s[1][0] == '0') ops.emplace_back(2, 1);
        if (s[0][1] == '0') ops.emplace_back(1, 2);
        if (s[n - 1][n - 2] == '1') ops.emplace_back(n, n - 1);
        if (s[n - 2][n - 1] == '1') ops.emplace_back(n - 1, n);
    }

    cout << sz(ops) << '\n';
    for (pii op : ops) cout << op.fi << ' ' << op.se << '\n';
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