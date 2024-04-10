#include <bits/stdc++.h>
using namespace std;

int T, n, m, x[11], coef[10010], ans[10010], p[10010];
char s[11][10010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
        }
        int mx = INT_MIN;
        for (int S = 0; S < 1 << n; S++) {
            fill(coef, coef + m, 0);
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (S >> i & 1) sum -= x[i];
                else sum += x[i];
                for (int j = 0; j < m; j++) {
                    if (s[i][j] == '1') coef[j] += (S >> i & 1) ? 1 : -1;
                }
            }
            iota(p, p + m, 0);
            sort(p, p + m, [&](int x, int y) { return coef[x] < coef[y]; });
            for (int i = 0; i < m; i++) {
                sum += (i + 1) * coef[p[i]];
            }
            if (sum > mx) {
                mx = sum;
                for (int i = 0; i < m; i++) ans[p[i]] = i;
            }
        }
        for (int i = 0; i < m; i++) printf("%d ", ans[i] + 1);
        putchar('\n');
    }
    return 0;
}