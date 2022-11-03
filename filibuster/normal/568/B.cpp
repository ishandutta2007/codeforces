#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 4000 + 13;

int sum(int a, int b) {
    int res = (a + b);
    if(res >= M)
        res -= M;
    return res;
}

int dp[N][N][2];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j][0] = sum(dp[i - 1][j][0] * 1ll * j % M, (j > 0 ? dp[i - 1][j - 1][0] : 0));
            dp[i][j][1] = sum(dp[i - 1][j][1] * 1ll * j % M,
                              sum((j > 0 ? dp[i - 1][j - 1][1] : 0), sum(dp[i - 1][j][0], dp[i - 1][j][1])));

//            cout << i << ' ' << j << ' ' << 0 << ' ' << dp[i][j][0] << endl;
//            cout << i << ' ' << j << ' ' << 1 << ' ' << dp[i][j][1] << endl;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = sum(ans, dp[n][i][1]);

    cout << ans;
}