#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int T, n, m;
char s[maxn][maxn], t[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            copy(s[i] + 1, s[i] + m + 1, t[i] + 1);
        }
        for (int i = n % 3 ? 1 : 2; i <= n; i += 3) {
            for (int j = 1; j <= m; j++) t[i][j] = 'X';
            if (i >= n - 1) continue;
            for (int j = 1; j <= m; j++) {
                if (t[i + 1][j] == 'X') { t[i + 2][j] = 'X'; break; }
                if (t[i + 2][j] == 'X') { t[i + 1][j] = 'X'; break; }
                if (j == m) t[i + 1][j] = t[i + 2][j] = 'X';
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) putchar(t[i][j]);
            putchar('\n');
        }
    }
    return 0;
}