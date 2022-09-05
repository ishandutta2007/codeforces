#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, f[maxn][2][3];
char s[maxn];

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d %s", &n, s + 1);
    memset(f, -0x3f, sizeof(f));
    f[0][0][0] = f[0][1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : {0, 1}) for (int k : {0, 1, 2}) {
            chk(f[i][j][k], f[i - 1][j][k]);
            if (s[i] - '0' == j) {
                if (k <= 1) chk(f[i][j ^ 1][1], f[i - 1][j][k] + 1);
            } else {
                chk(f[i][j ^ 1][!k ? 0 : 2], f[i - 1][j][k] + 1);
            }
        }
    }
    int ans = 0;
    for (int i : {0, 1}) for (int j : {0, 1, 2}) {
        chk(ans, f[n][i][j]);
    }
    printf("%d\n", ans);
    return 0;
}