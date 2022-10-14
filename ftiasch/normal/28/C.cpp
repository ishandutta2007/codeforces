// Codeforces Beta Round #28
// Problem C -- Bath Queue
#include <cstdio>
#include <cstring>

using namespace std;

const int M = 55;

int n, m, a[M];
double pro[M], dp[M][M], cnt[M][M];

int main () {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++ i) {
        scanf("%d", a + i);
    } 
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i <= n; ++ i) {
        cnt[i][0] = 1;
        for (int j = 1; j <= i; ++ j) {
            cnt[i][j] = cnt[i - 1][j] + cnt[i - 1][j - 1];
        }       
    }
    pro[0] = 0;
    for (int max = 1; max <= n; ++ max) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= m; ++ i) {
            for (int j = 0; j <= n; ++ j) {
                for (int k = 0; k <= j and k <= a[i] * max; ++ k) {
                    dp[i][j] += dp[i - 1][j - k] * cnt[j][k];
                }
            }
        }
        pro[max] = dp[m][n];
        for (int i = 1; i <= n; ++ i) {
            pro[max] /= m;
        }
    }
    double res = 0;
    for (int i = 1; i <= n; ++ i) {
        res += (pro[i] - pro[i - 1]) * i;
    }
    printf("%.10f\n", res);
    return 0;
}