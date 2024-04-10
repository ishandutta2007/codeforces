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
    vt<int> a(n);
    for (int &x : a) cin >> x;

    int sum = accumulate(all(a), 0, [](int x, int y) {
        return x ^ y;
    });
    if (~n & 1 && sum) return void(cout << "NO");

    vt<vt<int>> ops;
    for (int i = 1; i < n - 1; i += 2) {
        ops.emplace_back(vt<int>{1, i + 1, i + 2});
    }
    
    ops.reserve(2 * sz(ops));
    copy(all(ops), back_inserter(ops));

    cout << "YES\n";
    cout << sz(ops) << '\n';
    for (auto &v : ops) {
        for (int &x : v) cout << x << ' ';
        cout << '\n';
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