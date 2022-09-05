#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int n, a[maxn], f[2][maxn / 2][2][2];

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int cur = 0, nxt = 1;
    memset(f, 0x3f, sizeof(f));
    f[0][0][0][1] = 0;
    for (int i = 1; i <= n; i++, swap(cur, nxt)) {
        memset(f[nxt], 0x3f, sizeof(f[nxt]));
        for (int j = 0; j <= min(i - 1, (n + 1) / 2); j++) {
            for (int k : {0, 1}) for (int l : {0, 1}) {
                if (k) {
                    chk(f[nxt][j][0][0], f[cur][j][k][l] + max(0, a[i] - a[i - 1] + 1));
                    chk(f[nxt][j][0][1], f[cur][j][k][l] + max({0, a[i] - a[i - 1] + 1, a[i] - a[i + 1] + 1}));
                } else {
                    chk(f[nxt][j][0][0], f[cur][j][k][l]);
                    chk(f[nxt][j][0][1], f[cur][j][k][l] + max(0, a[i] - a[i + 1] + 1));
                    if (l) chk(f[nxt][j + 1][1][0], f[cur][j][k][l]);
                }
            }
        }
    }
    for (int i = 1; i <= (n + 1) / 2; i++) {
        printf("%d ", min(f[cur][i][0][0], f[cur][i][1][0]));
    }
    return 0;
}