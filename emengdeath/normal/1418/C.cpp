#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
int n;
int a[N];
int f[N][2];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            f[i][0] = f[i][1] = 1e9;
        }
        f[0][0] = 0;
        f[0][1] = 1e9;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < 2; j ++)
            {
                if (i + 1 <= n) {
                    f[i + 1][j ^ 1] = min(f[i + 1][j^1], f[i][j] + (!j) * a[i + 1]);
                }
                if (i + 2 <= n) {
                    f[i + 2][j ^ 1] = min(f[i + 2][j^1], f[i][j] + (!j) * (a[i + 1] + a[i + 2]));

                }
            }
        printf("%d\n", min(f[n][0], f[n][1]));
    }
    return 0;
}