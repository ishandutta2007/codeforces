#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll dp[105][105][105]; /// idx/curcolor/curgroups
int c[105];
int a[105][105];
int n, m, k;

int main()
{
    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 105; ++j)
            for (int k = 0; k < 105; ++k)
                dp[i][j][k] = 9e18;

    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    }

    for (int i = (c[1] ? c[1] : 1); i <= (c[1] ? c[1] : m); ++i) {
        dp[1][i][1] = c[1] ? 0 : a[1][i];
    }

    for (int i = 2; i <= n; ++i) {
        for (int prv = 1; prv <= m; ++prv) {
            for (int group = 1; group <= n; ++group) {
                if (dp[i - 1][prv][group] == ll(9e18)) continue;
                int curl = c[i] ? c[i] : 1;
                int curr = c[i] ? c[i] : m;
                for (int cur = curl; cur <= curr; ++cur) {
                    dp[i][cur][group + (cur != prv)] = min(dp[i][cur][group + (cur != prv)],
                                                           dp[i - 1][prv][group] + (cur == c[i] ? 0 : a[i][cur]));
                }
            }
        }
    }

//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            for (int z = 1; z <= k; ++z) {
//                cerr << i << " " << j << " " << z << " " << dp[i][j][z] << endl;
//            }
//        }
//    }

    ll ans = 9e18;
    for (int cur = 1; cur <= m; ++cur)
        ans = min(ans, dp[n][cur][k]);
    if (ans == ll(9e18)) ans = -1;
    cout << ans << endl;

    return 0;
}