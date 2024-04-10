#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

const int N = 555;
const int INF = 100000;

int n, m, minCost[N][N], dp[N][N];
char str[N];

int main() {
    scanf("%s%d", str, &m);
    n = strlen(str);
    memset(minCost, 0, sizeof(minCost));
    for (int i = n - 1; i >= 0; -- i) {
        for (int j = i + 1; j < n; ++ j) {
            minCost[i][j] = minCost[i + 1][j - 1];
            if (str[i] != str[j]) {
                minCost[i][j] ++;
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        dp[0][i] = INF;
    }
    dp[0][n] = 0;
    for (int i = 1; i <= m; ++ i) {
        for (int j = n - 1; j >= 0; -- j) {
            dp[i][j] = INF;
            for (int k = j; k < n; ++ k) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k + 1] + minCost[j][k]);
            }
        }
        dp[i][n] = 0;
    }
    printf("%d\n", dp[m][0]);
    for (int i = m, j = 0; j < n; -- i) {
        int next = j;
        for (int k = j; k < n; ++ k) {
            if (dp[i][j] == dp[i - 1][k + 1] + minCost[j][k]) {
                next = k;
                break;
            }
        }
        for (int k = j; k <= next; ++ k) {
            if (str[k] != str[j + next - k]) {
                str[j + next - k] = str[k];
            }
        }
        for (int k = j; k <= next; ++ k) {
            if (str[k] != str[j + next - k]) {
                str[j + next - k] = str[k];
            }
            printf("%c", str[k]);
        }
        j = next + 1;
        printf("%c", j == n? '\n': '+');
    }
    return 0;
}