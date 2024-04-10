#include <bits/stdc++.h>
using namespace std;

int n, m, a[6], b[6], c[6][6], pw[6], f[5][15625], g[15625];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = pw[0] = 1; i <= m; i++) {
        pw[i] = pw[i - 1] * 5;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%d", &c[i][j]);
    }
    memset(g, 0x3f, sizeof(g)), g[0] = 0;
    for (int i = 0; i < n; i++) {
        memset(f, 0x3f, sizeof(f));
        memcpy(f[0], g, sizeof(f[0]));
        for (int j = 0; j < m; j++) {
            for (int k = a[i] - 1; ~k; k--) {
                for (int S = 0; S < pw[m]; S++) if (f[k][S] < 1e9) {
                    int r = b[j] - S / pw[j] % 5;
                    for (int l = 1; l <= min(r, a[i] - k); l++) {
                        chk(f[k + l][S + pw[j] * l], f[k][S] + c[i][j]);
                    }
                }
            }
        }
        memcpy(g, f[a[i]], sizeof(g));
    }
    int ans = *min_element(g, g + pw[m]);
    printf("%d\n", ans > 1e9 ? -1 : ans);
    return 0;
}