#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define REP1(i, n)  for (int i = 1; (i) <= (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

const int kInf = 1 << 30;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> pre(n + 1);
    partial_sum(ALL(a), begin(pre) + 1);

    vector<int> dp(n + 2, -kInf);
    for (int len = n; len >= 0; len--) {
        dp[len] = dp[len + 1];
        for (int i = 0; i + len <= n; i++) {
            dp[len] = max(dp[len], pre[i + len] - pre[i]);
        }
    }

    int ans = 0;
    REP(len, n + 1) {
        ans = max(ans, dp[len] + k * len);
        cout << ans << " \n"[len == n];
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