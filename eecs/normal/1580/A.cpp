#include <bits/stdc++.h>
using namespace std;

const int maxn = 410;
int T, n, m, s[maxn], pre[maxn][maxn], a[maxn], b[maxn];
char str[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", str[i] + 1);
            for (int j = 1; j <= m; j++) {
                pre[i][j] = pre[i][j - 1] + (str[i][j] == '1');
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= m; i++) {
            for (int j = i + 3; j <= m; j++) {
                for (int k = 1; k <= n; k++) {
                    s[k] = s[k - 1] + pre[k][j - 1] - pre[k][i];
                    if (str[k][i] == '0') s[k]++;
                    if (str[k][j] == '0') s[k]++;
                }
                for (int k = 1; k <= n; k++) {
                    a[k] = j - i - 1 - (pre[k][j - 1] - pre[k][i]) - s[k];
                    b[k] = j - i - 1 - (pre[k][j - 1] - pre[k][i]) + s[k - 1];
                }
                int mn = 1e9;
                for (int k = 5; k <= n; k++) {
                    mn = min(mn, a[k - 4]);
                    ans = min(ans, mn + b[k]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}