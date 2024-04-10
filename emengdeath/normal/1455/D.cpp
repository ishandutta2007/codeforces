#include <algorithm>
#include <cstdio>
using namespace std;
int f[501][501][501];
int T, n, x;
int a[510];
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            for (int j = 0; j <= 500; j ++)
                for (int k = 0; k <= 500; k ++)
                    f[i][j][k] = 1e9;
        }
        f[1][x][0] = 0;
        for (int i = 1; i < n; i ++)
            for (int j = 0; j <= 500; j ++)
                for (int k = 0; k <= 500; k ++)
                {
                    if (k <= a[i]) {
                        f[i + 1][j][a[i]] = min(f[i+1][j][a[i]], f[i][j][k]);
                    }
                    if (j < a[i] && k <= j) {
                        f[i + 1][a[i]][j] = min(f[i + 1][a[i]][j], f[i][j][k] + 1);
                    }
                }
        int ans = 1e9;
        for (int j = 0; j <= 500; j ++)
            for (int k = 0; k <= 500; k ++)
                if (k <= a[n]) ans = min(ans, f[n][j][k]);
        printf("%d\n", ans == 1e9?-1:ans);
    }
    return 0;
}