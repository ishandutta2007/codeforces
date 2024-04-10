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
    vector<pii> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        if (x < y) swap(x, y);
    }

    sort(ALL(a));

    ll ans = 0;
    int prev = 0;
    for (auto [x, y] : a) {
        ans += 2LL * y + 2LL * x - 2LL * prev;
        prev = x;
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