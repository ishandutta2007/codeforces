#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 501;
const int C = 26;
int dp[N][N][C];
int del[N][N];
int get(int l, int r, int c) {
    if (r < l) return 0;
    else return dp[l][r][c];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            for (int c = 0; c < C; ++c) {
                dp[i][j][c] = N;
            }   
        }   
    }   
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            for (int i = l; i <= r; ++i) {
                int c = s[i] - 'a';
                dp[l][r][c] = min(dp[l][r][c], get(l, i - 1, c) + get(i + 1, r, c));
            }   
            del[l][r] = N;
            for (int c = 0; c < C; ++c) {
                del[l][r] = min(del[l][r], dp[l][r][c] + 1);
            }   
            for (int c = 0; c < C; ++c) {
                dp[l][r][c] = min(dp[l][r][c], del[l][r]);
            }   
        }   
    }       
    cout << del[0][n - 1] << '\n';
}