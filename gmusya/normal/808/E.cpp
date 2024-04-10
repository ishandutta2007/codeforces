#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<ll> a1, a2, a3;
    for (int i = 0; i < n; ++i) {
        int t;
        ll w;
        cin >> t >> w;
        if (t == 1) {
            a1.push_back(w);
        } else if (t == 2) {
            a2.push_back(w);
        } else {
            a3.push_back(w);
        }
    }
    sort(a1.rbegin(), a1.rend());
    sort(a2.rbegin(), a2.rend());
    sort(a3.rbegin(), a3.rend());
    vector<ll> dp(m + 1, -INF);
    vector<ll> left(m + 1);
    vector<ll> right(m + 1);
    dp[0] = 0, left[0] = -1, right[0] = -1;
    for (int i = 0; i < m; ++i) {
        if (dp[i] > dp[i + 1]) {
            dp[i + 1] = dp[i];
            left[i + 1] = left[i];
            right[i + 1] = right[i];
        }
        if (i + 1 <= m && left[i] + 1 < a1.size() && dp[i] + a1[left[i] + 1] > dp[i + 1]) {
            dp[i + 1] = dp[i] + a1[left[i] + 1];
            left[i + 1] = left[i] + 1;
            right[i + 1] =  right[i];
        }
        if (i + 2 <= m && right[i] + 1 < a2.size() && dp[i] + a2[right[i] + 1] > dp[i + 2]) {
            dp[i + 2] = dp[i] + a2[right[i] + 1];
            left[i + 2] = left[i];
            right[i + 2] = right[i] + 1;
        }
    }
    ll ans = dp[m];
    ll sum = 0;
    for (int i = 0; i < (int) a3.size() && (i + 1) * 3 <= m; ++i) {
        sum += a3[i];
        ans = max(ans, sum + dp[m - (i + 1) * 3]);
    }
    cout << ans;
    return 0;
}