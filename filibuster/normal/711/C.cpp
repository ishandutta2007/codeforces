#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 100 + 13;


/*

*/

int g[N][N];
li dp[N][N][N];
int a[N];
//int s[N];

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int l = 0; l < N; l++)
                dp[i][j][l] = INF;

    if(a[0] == 0) {
        for(int i = 1; i <= m; i++) {
            dp[0][1][i] = g[0][i];
        }
    } else {
        dp[0][1][a[0]] = 0;
    }

    for(int i = 0; i < n - 1; i++) {
        for(int cnt = 1; cnt <= i + 1; cnt++) {
            for(int lst = 1; lst <= m; lst++)
                if(dp[i][cnt][lst] != INF) {
//                    cout << i << ' ' << cnt << ' ' << lst << ' ' << dp[i][cnt][lst] << endl;
                    if(a[i + 1] == 0) {
                        for(int j = 1; j <= m; j++) {
                            if(lst == j) {
                                dp[i + 1][cnt][lst] = min(dp[i + 1][cnt][lst],
                                                          dp[i][cnt][lst] + g[i + 1][lst]);
                            } else {
                                dp[i + 1][cnt + 1][j] = min(dp[i + 1][cnt + 1][j],
                                                               dp[i][cnt][lst] + g[i + 1][j]);
                            }
                        }
                    } else {
                        if(lst == a[i + 1])
                            dp[i + 1][cnt][lst] = min(dp[i + 1][cnt][lst], dp[i][cnt][lst]);
                        else
                            dp[i + 1][cnt + 1][a[i + 1]] = min(dp[i + 1][cnt + 1][a[i + 1]],
                                                               dp[i][cnt][lst]);
                    }
                }
        }
    }

    li ans = INF;
    for(int i = 1; i <= m; i++)
        ans = min(ans, dp[n - 1][k][i]);

    cout << (ans == INF ? -1 : ans) << endl;
}