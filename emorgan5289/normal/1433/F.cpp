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

const ll N = 72;
int a[N][N];
int dp[N][N][N][N];
int dp2[N][N], dp3[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int k = 0; k <= m/2; k++)
            for (int r = 0; r < s; r++)
                dp[i][0][k][r] = r == 0 ? 0 : -inf;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp2[i][j] = dp3[i][j] = -inf;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= m/2; k++)
                for (int r = 0; r < s; r++) {
                    dp[i][j][k][r] = dp[i][j-1][k][r];
                    if (k > 0) dp[i][j][k][r] = max(dp[i][j][k][r], dp[i][j-1][k-1][(r-a[i][j-1]+s*10000)%s]+a[i][j-1]);
                    dp2[i][r] = max(dp2[i][r], dp[i][j][k][r]);
                }
    dp3[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < s; j++)
            for (int k = 0; k < s; k++)
                dp3[i][j] = max(dp3[i][j], dp3[i-1][(j-dp2[i-1][k]+s*10000)%s]+dp2[i-1][k]);
    cout << dp3[n][0] << "\n";
}