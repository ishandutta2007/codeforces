#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
const int N = 50;
char a[N][N];
int sum[N][N];
int dp[N][N][N][N];
void upd(int &a, int b) { a = min(a, b); }
int getsum(int x1, int y1, int x2, int y2) {
    return sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1] - sum[x2 + 1][y1] + sum[x1][y1];
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { cin >> a[i][j]; sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (a[i][j] == '#'); }
    for (int lx = 1; lx <= n; ++lx) {
        for (int ly = 1; ly <= n; ++ly) {
            for (int x1 = 0; x1 + lx - 1 < n; ++x1) {
                for (int y1 = 0; y1 + ly - 1 < n; ++y1) {
                    int x2 = x1 + lx - 1, y2 = y1 + ly - 1;
                    int &res = dp[x1][y1][x2][y2];

                    if (getsum(x1, y1, x2, y2) == 0) {
                        res = 0;
                        continue;
                    }   

                    res = max(x2 - x1 + 1, y2 - y1 + 1);
                    for (int i = x1; i < x2; ++i) {
                        upd(res, dp[x1][y1][i][y2] + dp[i + 1][y1][x2][y2]);
                    }   
                    for (int i = y1; i < y2; ++i) {
                        upd(res, dp[x1][y1][x2][i] + dp[x1][i + 1][x2][y2]);
                    }   
                }   
            }   
        }   
    }   
    cout << dp[0][0][n - 1][n - 1] << '\n';
}