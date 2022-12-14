#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<array<ll, 2>> dp(n);
    for (int i = 0; i < n - 1; i++) {
        bool good = i > 0 && ((a[i - 1] <= a[i] && a[i] <= a[i + 1])
                || (a[i - 1] >= a[i] && a[i] >= a[i + 1]));
        int d = abs(a[i + 1] - a[i]);
        if (good) dp[i + 1][1] = max(dp[i][0], dp[i][1]) + d;
        else dp[i + 1][1] = dp[i][0] + d;
        dp[i + 1][0] = max(dp[i][0], dp[i][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}