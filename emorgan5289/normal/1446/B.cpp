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

const int N = 5005;
int dp[N][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    string a, b; cin >> a >> b;
    a = '$'+a, b = '#'+b;
    for (int i = 0; i < N; i++)
        fill(dp[i], dp[i]+N, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
            dp[i][j] = max(dp[i][j], dp[i-1][j]-1);
            dp[i][j] = max(dp[i][j], dp[i][j-1]-1);
            ans = max(ans, dp[i][j]);
        }
    cout << ans << "\n";
}