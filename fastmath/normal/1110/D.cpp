#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 2007;
const int C = 9;
const int INF = 1e9 + 7;
int a[N], cnt[N];
int dp[C][C], ndp[C][C];
signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #else 
        ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }   
    int add = 0;
    for (int i = 0; i < N; ++i) {
        while (cnt[i] - 3 >= 6) {
            cnt[i] -= 3;
            ++add;
        }   
    }   
        for (int a = 0; a < C; ++a) {
            for (int b = 0; b < C; ++b) {
                dp[a][b] = ndp[a][b] = -INF;
            }
        }   
    dp[0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int a = 0; a < C; ++a) {
            for (int b = 0; b < C; ++b) {
                int c = cnt[i + 1];
                int mn = min(min(a, b), c);
                for (int x = 0; x <= mn; ++x) {
                    ndp[b - x][c - x] = max(ndp[b - x][c - x], dp[a][b] + x);
                    if (c - x >= 3) {
                        ndp[b - x][c - x - 3] = max(ndp[b - x][c - x - 3], dp[a][b] + x + 1);
                    }   
                    if (c - x >= 6) {
                        ndp[b - x][c - x - 6] = max(ndp[b - x][c - x - 6], dp[a][b] + x + 2);
                    }   
                }
            }   
        }   
        for (int a = 0; a < C; ++a) {
            for (int b = 0; b < C; ++b) {
                dp[a][b] = ndp[a][b];
                ndp[a][b] = -INF;
            }   
        }   
    }   
    cout << dp[0][0] + add << '\n';
}