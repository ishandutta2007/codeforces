#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn], b[maxn], f[maxn][maxn * maxn];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
        }
        memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                chk(f[i][j + a[i]], f[i - 1][j] + a[i] * j + b[i] * (sum - j));
                chk(f[i][j + b[i]], f[i - 1][j] + b[i] * j + a[i] * (sum - j));
            }
            sum += a[i] + b[i];
        }
        int ans = 2 * *min_element(f[n], f[n] + sum + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += a[i] * a[i] + a[j] * a[j];
                ans += b[i] * b[i] + b[j] * b[j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}