#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 222;
const int ZERO = 55;
const int D[2] = {1, -1};

int len, n;
char str[N];
bool dp[N][N][N][2];

int main() {
    scanf("%s%d", str, &n);
    len = strlen(str);
    memset(dp, 0, sizeof(dp));
    dp[0][0][ZERO][0] = true;
    for (int i = 0; i < len; ++ i) {
        for (int j = 0; j <= n; ++ j) {
            for (int x = 1; x < N - 1; ++ x) {
                for (int d = 0; d < 2; ++ d) {
                    if (!dp[i][j][x][d]) {
                        continue;
                    }
                    if (str[i] == 'F') {
                        dp[i + 1][j][x + D[d]][d] = true;
                        dp[i + 1][j + 1][x][d ^ 1] = true;
                    } else {
                        dp[i + 1][j][x][d ^ 1] = true;
                        dp[i + 1][j + 1][x + D[d]][d] = true;
                    }
                }
            }
        }
    }
    int ret = 0;
    for (int j = 0; j <= n; ++ j) {
        if ((n - j) % 2 == 0) {
            for (int x = 0; x < N; ++ x) {
                for (int d = 0; d < 2; ++ d) {
                    if (!dp[len][j][x][d]) {
                        continue;
                    }
                    ret = max(ret, abs(x - ZERO));
                }
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}