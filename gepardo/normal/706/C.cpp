#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> e(n);
    for (int i = 0; i < n; i++) cin >> e[i];
    vector <string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector <string> r(n);
    for (int i = 0; i < n; i++)
    {
        r[i] = s[i];
        reverse(r[i].begin(), r[i].end());
    }
    vector < pair<long long, long long> > dp(n);
    dp[0].first = 0;
    dp[0].second = e[0];
    for (int i = 1; i < n; i++)
    {
        dp[i].first = 123456789012345678;
        dp[i].second = 123456789012345678;

        if (s[i-1] <= s[i]) dp[i].first = min(dp[i].first, dp[i-1].first);
        if (r[i-1] <= s[i]) dp[i].first = min(dp[i].first, dp[i-1].second);
        if (s[i-1] <= r[i]) dp[i].second = min(dp[i].second, dp[i-1].first + e[i]);
        if (r[i-1] <= r[i]) dp[i].second = min(dp[i].second, dp[i-1].second + e[i]);
   }
    long long ans = min(dp[n-1].first, dp[n-1].second);
    if (ans >= 123456789012345678) ans = -1;
    cout << ans << endl;
    return 0;
}