#include <cstdio>
#include <cstring>

const int N = 2000;
const int MOD = (int)1e9 + 7;

int ways[2][N + 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(ways, 0, sizeof(ways));
    ways[0][1] = 1;
    for (int i = 0; i < m; ++ i) {
        memset(ways[i + 1 & 1], 0, sizeof(ways[i + 1 & 1]));
        for (int j = 1; j <= n; ++ j) {
            for (int k = j; k <= n; k += j) {
                ways[i + 1 & 1][k] += ways[i & 1][j];
                if (ways[i + 1 & 1][k] >= MOD) {
                    ways[i + 1 & 1][k] -= MOD;
                }
            }
        }
    }
    int result = 0;
    for (int j = 1; j <= n; ++ j) {
        result += ways[m & 1][j];
        if (result >= MOD) {
            result -= MOD;
        }
    }
    printf("%d\n", result);
    return 0;
}