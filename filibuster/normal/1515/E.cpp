#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
//const int M = 998244353;
const int N = 411;

mt19937 rnd(0);

int M;

int sum(int a, int b) {
    a += b;
    while(a >= M)
        a -= M;
    return a;
}

//int dp[N][N][2];

int C[N][N];
int dp[N][N];
int cnt[N];

int main() {
//    int t;
//    cin >> t;
//
//    while(t--)
//        solve();

    int n;
    cin >>n >> M;

    for(int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = sum(C[i - 1][j - 1], C[i - 1][j]);
        }
    }

    cnt[1] = 1;
    cnt[2] = 2;
    for(int k = 3; k <= n; k++) {
        for(int i = 0; i < k; i++)
            cnt[k] = sum(cnt[k], C[k - 1][i]);
//        cout << k << ' ' << cnt[k] << endl;
    }

//    dp[0][0] = 1;
//    dp[1][1] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i][i] = cnt[i];
        for(int j = 0; j < i - 1; j++) {
            int x = i - j - 1;
            for(int k = 0; k <= j; k++) {
                dp[i][k + x] = sum(dp[i][k + x], dp[j][k] * 1ll * cnt[x] % M * 1ll * C[k + x][x] % M);
            }
        }

    }

//    for(int i = 0; i <= n; i++) {
//        for(int j = 0; j <= i; j++)
//            cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//        cout << i << ' ' << dp[n][i] << endl;
//    }

    int ans = 0;
    for(int i = 0; i <= n; i++)
        ans = sum(ans, dp[n][i]);
    cout << ans << endl;
//    dp[0][0][0] = 1;
//    for(int i = 1; i <= n; i++) {
//        for(int j = 0; j < i; j++) {
//            dp[i][j][0] = sum(dp[i][j][0], dp[i - 1][j][1]);
//        }
//
//        for(int j = 1; j <= i; j++) {
//            dp[i][j][1] = sum(dp[i][j][1], dp[i - 1][j - 1][0]);
//            dp[i][j][1] = sum(dp[i][j][1], dp[i - 1][j - 1][1]);
//        }
//    }
//
//    int p = 1;
//    int ans = 0;
//    for(int i = 1; i <= n; i++) {
//        p = p * 1ll * i % M;
//        ans = sum(ans, dp[n][i][1] * 1ll * p % M);
//        cout << i << ' ' << dp[n][i][1] << ' '<< p <<endl;
//
//    }


}