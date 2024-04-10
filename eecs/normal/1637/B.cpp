#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, a[maxn], f[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) {
            set<int> S;
            for (int j = i; j <= n; j++) {
                S.insert(a[j]);
                int k = 0;
                while (S.count(k)) k++;
                f[i][j] = k + 1;
            }
        }
        for (int len = 1; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                for (int k = l; k < r; k++) {
                    f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r]);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                ans += f[i][j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}