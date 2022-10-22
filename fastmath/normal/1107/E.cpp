#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 103;
const int INF = 1e18 + 7;
int dp[2][N][N][N];
int del[N][N];
int a[N], c[N];
int get(int w, int l, int r, int k) {
    if (k == 0) return del[l][r];
    else return dp[w][l][r][k];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    for (int w = 0; w <= 1; ++w) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    dp[w][i][j][k] = -INF;
                }   
            }   
        }   
    }   
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i <= j) del[i][j] = -INF;
        }   
    }   

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }   
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }   
    for (int len = 1; len <= n; ++len) {
        for (int w = 0; w <= 1; ++w) {
            for (int l = 1; l <= n; ++l) {
                int r = l + len - 1;
                for (int k = 1; k <= len; ++k) {
                    for (int i = l; i <= r; ++i) {
                        if (a[i] == w) {
                            dp[w][l][r][k] = max(dp[w][l][r][k], del[l][i - 1] + get(w, i + 1, r, k - 1));
                        }   
                    }
                    del[l][r] = max(del[l][r], dp[w][l][r][k] + c[k]);   
                }   
            }   
        }
    }   

    cout << del[1][n] << '\n';
}