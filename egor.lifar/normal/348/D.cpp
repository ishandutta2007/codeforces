#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;


#define MOD 1000000007
int n, m;
char a[3010][3010];
int dp[3010][3010];


long long getDp(int sx, int sy, int gx, int gy){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = 0;
        }
    }
    if (a[sx][sy] != '#') {
        dp[sx][sy] = 1;
    }
    for (int i = sx; i < n; i++) {
        for (int j = sy; j < m; j++) {
            if (dp[i][j] > 0) {
                if (i + 1 < n && a[i + 1][j] != '#'){
                    dp[i + 1][j] += dp[i][j];
                    if (dp[i + 1][j] >= MOD) {
                        dp[i + 1][j] -= MOD;
                    }
                }
                if (j + 1 < m && a[i][j + 1] != '#'){
                    dp[i][j + 1] += dp[i][j];
                    if (dp[i][j + 1] >= MOD) {
                        dp[i][j + 1] -= MOD;
                    }
                }
            }
        }
    }
    return dp[gx][gy];
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
    }
    long long A = getDp(0, 1, n - 2, m - 1);
    long long B = getDp(0, 1, n - 1, m - 2);
    long long C = getDp(1, 0, n - 2, m - 1);
    long long D = getDp(1, 0, n - 1, m - 2);
    long long ans = ((A * D - B * C) % MOD + MOD) % MOD;
    cout << ans << endl;
    return 0;
}