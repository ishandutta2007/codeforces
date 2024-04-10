#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, sr[maxn][maxn], sc[maxn][maxn];
char s[maxn][maxn];
bool mark[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    int sx, sy, tx, ty;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == 'S') sx = i, sy = j;
            if (s[i][j] == 'T') tx = i, ty = j;
            sr[i][j] = sr[i][j - 1] + (s[i][j] == '*');
            sc[i][j] = sc[i - 1][j] + (s[i][j] == '*');
        }
    }
    for (int i = 1; i <= n; i++) { // change x
        if (sc[min(i, sx) - 1][sy] == sc[max(i, sx)][sy]) {
            // change y
            // cur: (i, sy)
            for (int j = 1; j <= m; j++) {
                if (sr[i][min(j, sy) - 1] == sr[i][max(j, sy)]) {
                    // change x
                    // cur: (i, j)
                    if (j == ty) {
                        if (sc[min(i, tx) - 1][j] == sc[max(i, tx)][j]) {
                            puts("YES"), exit(0);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) { // change y
        if (sr[sx][min(i, sy) - 1] == sr[sx][max(i, sy)]) {
            // change x
            // cur: (sx, i)
            for (int j = 1; j <= n; j++) {
                if (sc[min(j, sx) - 1][i] == sc[max(j, sx)][i]) {
                    // change y
                    // cur: (i, j)
                    if (j == tx) {
                        if (sr[j][min(i, ty) - 1] == sr[j][max(i, ty)]) {
                            puts("YES"), exit(0);
                        }
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}