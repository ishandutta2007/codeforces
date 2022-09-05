#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, m, a[2][maxn], b[2][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &m);
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
                b[i][j] = b[i][j - 1] + a[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= m; i++) {
            ans = min(ans, max(b[1][i - 1], b[0][m] - b[0][i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}