#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll r1, r2, r3, d;
    cin >> r1 >> r2 >> r3 >> d;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n), c(n);
    for (int i = 0; i < n; ++i) {
        b[i] = min(a[i] * r1 + 2 * r1, r2 + r1);
        c[i] = min(a[i] * r1 + r3, b[i] + 2 * d);
    }
    vector<ll> suf(n);
    suf[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suf[i] = suf[i + 1] + b[i] + d;
    }
    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        if (i + 1 <= n) {
            dp[i + 1] = min(dp[i + 1], dp[i] + c[i]);
        }
        if (i + 2 <= n) {
            dp[i + 2] = min(dp[i + 2], dp[i] + b[i] + b[i + 1] + 2 * d);
        }
        ans = min(ans, dp[i] + suf[i]);
    }
    ans = min(ans, dp[n]);
    cout << ans + (n - 1) * d;
    return 0;
}