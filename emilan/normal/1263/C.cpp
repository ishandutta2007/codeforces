#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < n; (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      (a).begin(), (a).end()
#define RALL(a)     (a).rbegin(), (a).rend()

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    // n = d * q + r
    // if d * d <= n:
    //     n = d * (q + r/d)
    //     q + r/d >= d -> q >= d
    //     n = (d + 1) * q + r - q, r < d
    //     -> r - q < 0
    vector<int> ans;
    for (int i = 1; (i - 1) * (i - 1) <= n; i++) {
        ans.push_back(n / i);
    }
    while (ans.back() != 0) {
        ans.push_back(ans.back() - 1);
    }

    cout << SZ(ans) << '\n';
    for (int i = SZ(ans) - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    }
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