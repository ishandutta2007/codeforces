#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 20, M = 1e5+5;
int dp[2][(1<<N)+5][N+2], f[M];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char x; cin >> x;
            f[j] = 2*f[j]+(x-'0');
        }
    for (int i = 0; i < m; i++)
        dp[0][f[i]][0]++;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1<<n); j++)
            for (int k = 0; k <= n; k++)
                dp[1][j][k] = dp[0][j][k] + dp[0][j^(1<<i)][k-1];
        for (int j = 0; j < (1<<n); j++)
            for (int k = 0; k <= n; k++)
                dp[0][j][k] = dp[1][j][k];
    }
    int ans = inf;
    for (int i = 0; i < (1<<n); i++) {
        int r = 0;
        for (int k = 0; k <= n; k++)
            r += min(k, n-k)*dp[0][i][k];
        cmin(ans, r);
    }
    cout << ans << "\n";
}