#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int n, m, ans, a[maxn][maxn], b[maxn][maxn], c[maxn][maxn], mark[maxn * maxn];
short lst[maxn][maxn * maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) b[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        memset(c, 0, sizeof(c));
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                c[min(j, k)][max(j, k)] = max(c[min(j, k)][max(j, k)], (int)lst[k][a[i][j]]);
            }
        }
        for (int len = 1; len <= m; len++) {
            for (int j = 1, k = len; k <= m; j++, k++) {
                c[j][k] = max({c[j][k], c[j][k - 1], c[j + 1][k]});
            }
        }
        for (int j = 1; j <= m; j++) {
            for (int k = j; k <= m; k++) {
                if (mark[a[i][k]]) {
                    for (; k <= m; k++) b[j][k] = i + 1;
                    break;
                }
                b[j][k] = max(b[j][k], c[j][k] + 1);
                mark[a[i][k]] = 1;
            }
            for (int k = j; k <= m; k++) {
                mark[a[i][k]] = 0;
                ans = max(ans, (k - j + 1) * (i - b[j][k] + 1));
            }
        }
        for (int j = 1; j <= m; j++) {
            lst[j][a[i][j]] = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}