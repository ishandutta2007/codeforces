#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 1000000007;
int n, m, x;
int f[340][340];
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod : x;
}
int main() {
    scanf("%d %d %d", &n, &m, &x);
    if (n > m) {
        printf("0");
        return 0;
    }
    f[1][0] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int l = n + 1; l >= 1; l --)
            for (int r = n; r >= l - 1; r --)
                if (f[l][r]) {
                    if (i == x) {
                        if (l <= r) {
                            f[l + 1][r + 1] = add(f[l + 1][r + 1], f[l][r]);
                        }
                        f[l][r + 1] = add(f[l][r + 1], f[l][r]);
                        f[l][r] = 0;
                    } else {
                        if (l <= r) {
                            f[l + 1][r + 1] = add(f[l + 1][r + 1], f[l][r]);
                            f[l + 1][r] = add(f[l + 1][r], f[l][r]);
                        }
                        f[l][r + 1] = add(f[l][r + 1], f[l][r]);
                    }
                }
    }
    int ans = add(f[n + 1][n], f[n][n]);
    for (int i = 1; i <= n; i ++)
        ans = 1ll * ans * i % mod;
    printf("%d\n", ans);
    return 0;
}