#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;

const int N = 103;

int a[N], b[N];

int dp[N][N][N * N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        s += b[i];
    }

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k < N * N; k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= i * N; k++) if(dp[i][j][k] != -1) {
                dp[i + 1][j + 1][k + a[i]] = max(dp[i + 1][j + 1][k + a[i]], dp[i][j][k] + b[i]);
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
            }
        }
//        cout << dp[i + 1][1][0] << ' ' << dp[i + 1][1][1] << ' ' << dp[i + 1][1][2] << endl;
    }

    for(int k = 1; k <= n; k++) {
        int res = 0;
        for(int i = 0; i < n * N; i++) if(dp[n][k][i] != -1) {
            res = max(res, min((i - dp[n][k][i]) * 2, s - dp[n][k][i]) + dp[n][k][i] * 2);
//            if(k == 1 && i < 3)
//                cout << k << ' ' << i << ' ' << res << endl;
        }
        cout << res / 2 << (res % 2 == 0 ? "" : ".5") << ' ';
    }

//    int t = 1;
//    cin >> t;
//
//    while(t--)
//        solve();
}