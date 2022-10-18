#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

ll a[1001001];
ll suff_kill_ret[1001001];
ll dp[1001001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    ll r1, r2, r3, d;
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[i] = x;
    }

    for (int i = n; i >= 1; --i) {
        suff_kill_ret[i] = suff_kill_ret[i + 1] + min(r2 + r1 + (i == n ? 2 * d : 0),
                                                      min(a[i] * r1 + r1 + r1 + (i == n ? 2 * d : 0), a[i] * r1 + r3));
    }
    ll ans = 1e18;
    dp[0] = -d;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[i - 1] + d + suff_kill_ret[i] + d * 2 * (n - i));
        dp[i] = dp[i - 1] + d + min(r2 + d + d + r1, min(a[i] * r1 + r1 + d + d + r1, a[i] * r1 + r3));
        if (i > 1) {
            dp[i] = min(dp[i], dp[i - 2] + d + min(r2 + r1, min(a[i - 1] * r1 + r1 + r1, a[i - 1] * r1 + r3))
                                             + min(r2 + r1, min(a[i    ] * r1 + r1 + r1, a[i    ] * r1 + r3)) + 3 * d);
        }
    }
    ans = min(ans, dp[n]);
    cout << ans << endl;
}