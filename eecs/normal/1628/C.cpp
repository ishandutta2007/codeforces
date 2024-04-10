#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int T, n, a[maxn][maxn], b[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++) {
            b[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                b[i][j] = b[i - 1][j - 1] ^ b[i - 1][j + 1] ^ 1;
                if (i > 2) b[i][j] ^= b[i - 2][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (b[i][j]) ans ^= a[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}