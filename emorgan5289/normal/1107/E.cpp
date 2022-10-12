#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 105;
ll a[N], dp[N][N][N][2], dp2[N][N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int len = 0; len <= n; len++) {
        for (int i = 0; i < n-len+1; i++) {
            int j = i+len;
            for (int k = 0; k <= n; k++) {
                dp[i][j][k][0] = dp2[i][j][0]+a[k];
                dp[i][j][k][1] = dp2[i][j][0]+a[k];
                if (len > 0)
                    dp[i][j][k][s[i]-'0'] = max(dp[i][j][k][s[i]-'0'], dp[i+1][j][k+1][s[i]-'0']);
                for (int x = i; x < j; x++) {
                    dp[i][j][k][0] = max(dp[i][j][k][0], dp2[i][x][0]+dp[x][j][k][0]);
                    dp[i][j][k][1] = max(dp[i][j][k][1], dp2[i][x][0]+dp[x][j][k][1]);
                }
                dp2[i][j][k] = max(dp[i][j][k][0], dp[i][j][k][1]);
            }
        }
    }
    cout << dp2[0][n][0] << "\n";
}