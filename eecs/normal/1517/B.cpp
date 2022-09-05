#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, m, L[maxn], R[maxn], a[maxn][maxn], ans[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
            sort(a[i] + 1, a[i] + m + 1);
            L[i] = 1, R[i] = m;
        }
        for (int i = 1; i <= m; i++) {
            int mn = INT_MAX, p1, p2;
            for (int j = 1; j <= n; j++) {
                if (a[j][L[j]] < mn) mn = a[j][L[j]], p1 = j, p2 = L[j];
            }
            for (int j = 1; j <= n; j++) {
                if (j == p1) ans[j][i] = a[j][L[j]++];
                else ans[j][i] = a[j][R[j]--];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                printf("%d%c", ans[i][j], " \n"[j == m]);
            }
        }
    }
    return 0;
}