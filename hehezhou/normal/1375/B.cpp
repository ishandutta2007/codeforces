#include <bits/stdc++.h>
using namespace std;
int a[310][310], b[310][310];
int t, n, m;
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[i][j] = 0;
            }
        }
        int tag = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
                if (a[i][j]) {
                    int d = 0;
                    b[i][j] = 1;
                    if (i != 1) b[i - 1][j] = 1, d++;
                    if (j != 1) b[i][j - 1] = 1, d++;
                    if (i != n) b[i + 1][j] = 1, d++;
                    if (j != m) b[i][j + 1] = 1, d++;
                    if (d < a[i][j]) {
                        if (!tag) puts("NO");
                        tag = 1;
                    }
                }
            }
        }
        if (!tag) {
            puts("YES");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    int now = 0;
                    if (b[i][j]) {
                        if (i != 1 && b[i - 1][j]) now++;
                        if (j != 1 && b[i][j - 1]) now++;
                        if (i != n && b[i + 1][j]) now++;
                        if (j != m && b[i][j + 1]) now++;
                    }
                    printf("%d%c", now, " \n"[j == m]);
                }
            }
        }
    }
}