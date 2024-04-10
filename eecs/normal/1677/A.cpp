#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int T, n, p[maxn], pre[maxn][maxn], suf[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
            for (int j = p[i]; j <= n; j++) pre[i][j]++;
        }
        memset(suf[n + 1], 0, sizeof(suf[n + 1]));
        for (int i = n; i; i--) {
            memcpy(suf[i], suf[i + 1], sizeof(suf[i]));
            for (int j = p[i]; j <= n; j++) suf[i][j]++;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += pre[i - 1][p[j]] * suf[j + 1][p[i]];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}