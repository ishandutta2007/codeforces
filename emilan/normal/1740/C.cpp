#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    sort(ALL(a));

    int ans = 0;
    for (int i = 2; i < n; i++) {
        ans = max(ans, (a[i] - a[i - 1]) + (a[i] - a[0]));
    }
    for (int i = 0; i < n - 2; i++) {
        ans = max(ans, (a[n - 1] - a[i]) + (a[i + 1] - a[i]));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}