#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, a[maxn], f[maxn][3];

int main() {
    scanf("%d", &n);
    memset(f, 0x3f, sizeof(f));
    f[0][2] = 0;
    for (int i = 1, a; i <= n; i++) {
        scanf("%d", &a);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (!j && !k) continue;
                if (j == 1 && k == 1) continue;
                if (k == 2 || (a >> k & 1)) {
                    f[i][k] = min(f[i][k], f[i - 1][j] + (k == 2));
                }
            }
        }
    }
    printf("%d\n", min({f[n][0], f[n][1], f[n][2]}));
    return 0;
}