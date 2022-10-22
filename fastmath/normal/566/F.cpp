#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 7;

int a[MAXN];
bool have[MAXN];
int dp[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) have[a[i]] = 1;

    int ans = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (!have[i]) continue;
        if (!dp[i]) dp[i] = 1;
        for (int j = 2 * i; j < MAXN; j += i) {
            if (have[j]) dp[j] = max(dp[j], dp[i] + 1);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
    return 0;
}