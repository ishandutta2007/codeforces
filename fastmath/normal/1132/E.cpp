#include<bits/stdc++.h>
using namespace std;
#define int long long
const int C = 840;
const int N = 8;
const int SUM = C * N + 1;
const int INF = 1e16 + 7;
int dp[SUM];
int a[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    int w; cin >> w;
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 1; i < SUM; ++i) {
        dp[i] = -INF;
    }   
    for (int i = 0; i < N; ++i) {
        for (int j = SUM - 1; j >= 0; --j) {
            int m = C / (i + 1);
            for (int t = 1; t < m && t <= a[i] && t * (i + 1) <= j; ++t) {
                dp[j] = max(dp[j], dp[j - t * (i + 1)] + (a[i] - t) / m);
            }   
        }   
    }
    int ans = 0;
    for (int i = 0; i < SUM; ++i) {
        if (i <= w) {
            int t = min((w - i) / C, dp[i]);
            ans = max(ans, i + t * C);
        }   
    }       
    cout << ans << '\n';
}