#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    map<int, vector<int>> mp;
    for (int i = 1, a; i <= n; i += 1) {
        cin >> a;
        mp[a].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i += 1) {
        auto& v = mp[i];
        reverse(v.begin(), v.end());
        for (int j : v) if (j >= i) {
            int y = 0;
            for (int x = j - i + 1; x; x -= x & -x) y = max(y, dp[x]);
            for (int x = j - i + 1; x <= n; x += x & -x) dp[x] = max(dp[x], y + 1);
            ans = max(ans, y + 1);
        }
    }
    cout << ans;
    return 0;
}