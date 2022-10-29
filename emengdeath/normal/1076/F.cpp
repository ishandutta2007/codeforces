#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int N = 2e6 + 10;
int r[N], b[N];
int n, k;
int f[N][2];
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &r[i]);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &b[i]);
    for (int i = 1; i <= n; i ++) {
        f[i][0] = 1e9;
        f[i][1] = 1e9;
        if (1ll * (r[i] - 1) * k + 2 <= b[i]) {
            if (1ll * (r[i] + 1) * k < b[i]) {
                puts("NO");
                return 0;
            }
            int x = b[i] - 1ll * (r[i] - 1) * k;
            if (x +f[i- 1][1] - k <= k) {
                if (x + f[i-1][1] <= k) {
                    f[i][1] = min(f[i][1], 1);
                    f[i][0] = min(f[i][0], 1);
                }else f[i][1] = min(f[i][1], x + f[i - 1][1] - k);
            }
            if (f[i -1][0] <= k) {
                if (x <= k) {
                    f[i][0] = min(f[i][0], 1);
                    f[i][1] = min(f[i][1], 1);
                } else {
                    f[i][1] = min(f[i][1], x - k);
                }
            }
        }else {
            if (1ll * (b[i] - 1) * k + 2 <= r[i]) {
                if (1ll * (b[i] + 1) * k < r[i]) {
                    puts("NO");
                    return 0;
                }
                int x = r[i] - 1ll * (b[i] - 1) * k;
                if (x +f[i- 1][0] - k <= k) {
                    if (x + f[i-1][0] <= k) {
                        f[i][0] = min(f[i][0], 1);
                        f[i][1] = min(f[i][1], 1);
                    }else f[i][0] = min(f[i][0], x + f[i - 1][0] - k);
                }

                if (f[i -1][1] <= k) {
                    if (x <= k) {
                        f[i][1] = min(f[i][1], 1);
                        f[i][0] = min(f[i][0], 1);
                    } else {
                        f[i][0] = min(f[i][0], x - k);
                    }
                }
            } else {
                if (1ll * (b[i] - 1) * k + 1 == r[i] || 1ll * (r[i] - 1) * k + 1 == b[i]) {
                    if (f[i - 1][0] + 1 <= k)
                        f[i][1] =min(f[i][1], 1);
                    if (f[i - 1][1] + 1 <= k)
                        f[i][0] =min(f[i][0], 1);
                    if (f[i - 1][0] <= k)
                        f[i][0] =min(f[i][0], 1);
                    if (f[i - 1][1] <= k)
                        f[i][1] =min(f[i][1], 1);
                }else{
                    if (f[i - 1][0] <= k || f[i - 1][1] <= k)
                        f[i][0] =min(f[i][0], 1), f[i][1] = min(f[i][1], 1);
                }
            }
        }
    }
    f[n][0] <= k || f[n][1] <= k ? puts("YES"):puts("NO");
    return 0;
}