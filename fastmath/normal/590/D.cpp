#include<bits/stdc++.h>
using namespace std;
const int N = 151;
const int INF = 1e9 + 7;
int n, k, s;
int dp[N][N * N];
int a[N];
void read() {
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) cin >> a[i];
}   
void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N * N; ++j) {
            dp[i][j] = INF;
        }   
    }   
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = min(i + 1, k); j >= 1; --j) {
            int sw = i - (j - 1);
            for (int t = sw; t < N * N; ++t) {
                dp[j][t] = min(dp[j][t], dp[j - 1][t - sw] + a[i]);
            }   
        }
    }   
}
void print() {
    int ans = INF;
    for (int i = 0; i <= s && i < N * N; ++i) {
        ans = min(ans, dp[k][i]);
    }   
    cout << ans << '\n';
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    read();
    solve();
    print();
}