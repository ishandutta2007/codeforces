#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int T, n, m;
char s[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int t = -1;
        bool flag = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= m; j++) if (s[i][j] != '.') {
                int v;
                if (s[i][j] == 'R') v = (i + j) % 2;
                else v = 1 - (i + j) % 2;
                if (!~t) t = v;
                else if (t ^ v) flag = 0;
            }
        }
        if (!flag) { puts("NO"); continue; }
        if (!~t) t = 0;
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i + j) % 2 == t) putchar('R');
                else putchar('W');
            }
            putchar('\n');
        }
    }
    return 0;
}