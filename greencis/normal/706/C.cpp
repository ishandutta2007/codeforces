#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, c[100105];
ll dp[100105][2];
string s[100105][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }

    dp[0][0] = 0;
    dp[0][1] = c[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i][1] = 9e18;
        for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < 2; ++y) {
                if (s[i-1][x] <= s[i][y])
                    dp[i][y] = min(dp[i][y], dp[i-1][x] + (y ? c[i] : 0));
            }
        }
    }

    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (ans == (ll)9e18) cout << -1;
    else cout << ans;
    cout << endl;

    return 0;
}