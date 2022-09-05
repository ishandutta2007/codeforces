#include <bits/stdc++.h>
using namespace std;

const int maxn = 120;
int n, m;
char s[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) if (s[i][j] == 'B') {
            int p1 = j, p2 = j, p3 = i, p4 = i;
            while (s[i][p1 - 1] == 'B') p1--;
            while (s[i][p2 + 1] == 'B') p2++;
            while (s[p3 - 1][j] == 'B') p3--;
            while (s[p4 + 1][j] == 'B') p4++;
            if (j - p1 == p2 - j && p2 - j == i - p3 && i - p3 == p4 - i) {
                printf("%d %d\n", i, j), exit(0);
            }
        }
    }
    return 0;
}