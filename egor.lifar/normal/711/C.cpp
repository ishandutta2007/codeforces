#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


int n, m, k;
long long dp[101][101][101];
int c[101];
int p[101][101];



int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &p[i][j]);
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int g = 0; g <= k; g++) {
                dp[i][j][g] = 1000000000000000LL;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int g = 0; g <= k; g++) {
                if (dp[i][j][g] != 1000000000000000LL) {
                    if (c[i]) {
                        int ng = g + (j != c[i]);
                        if (ng <= k) {
                            dp[i + 1][c[i]][ng] = min(dp[i + 1][c[i]][ng], dp[i][j][g]);
                        }
                    } else {
                        for (int cc = 1; cc <= m; cc++) {
                            int ng = g + (j != cc);
                            if (ng <= k) {
                                dp[i + 1][cc][ng] = min(dp[i + 1][cc][ng], dp[i][j][g] + p[i][cc]);
                            }
                        }
                    }
                }
            } 
        }
    }
    long long ans = 1000000000000000LL;
    for (int j = 1; j <= m; j++) {
        ans = min(ans, dp[n][j][k]);
    }
    if (ans == 1000000000000000LL) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}