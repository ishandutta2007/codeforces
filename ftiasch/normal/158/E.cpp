#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 4444;
const int INF = 100000000;

int n, m, t[N], d[N], dp[2][N];

void update(int &x, int a) {
    x = min(x, a);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", t + i, d + i);
    }
    t[n] = 86401;
    int result = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; ++ i) {
        result = max(result, t[i] - dp[i & 1][m] - 1);
        if (i < n) {
            for (int j = 0; j <= m; ++ j) {
                dp[(i + 1) & 1][j] = INF;
            }
            for (int j = 0; j <= m; ++ j) {
                update(dp[(i + 1) & 1][j], max(dp[i & 1][j], t[i] - 1) + d[i]);
                if (j + 1 <= m) {
                    update(dp[(i + 1) & 1][j + 1], dp[i & 1][j]);
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}