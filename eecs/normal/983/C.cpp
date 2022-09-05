#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, a[maxn], b[maxn], f[10000][10], g[10000][10];
int pw[5], num[10000][5], cnt[10000], nxt[10000][10], d1[10000][10], d2[10000][10];

int get(int x, int c) {
    while (--c) x /= 10;
    return x % 10;
}

void chk(int &x, int y) {
    if (x > y) x = y;
}

int main() {
    scanf("%d", &n);
    pw[1] = 1, pw[2] = 10, pw[3] = 100, pw[4] = 1000;
    for (int i = 0; i < 10000; i++) {
        for (int j = 1; j <= 9; j++) {
            d2[i][j] = i;
        }
        for (int j = 1; j <= 4; j++) if (num[i][j] = get(i, j)) {
            cnt[i]++, d1[i][num[i][j]]++;
            d2[i][num[i][j]] -= num[i][j] * pw[j];
        }
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 4; k++) if (!num[i][k]) {
                nxt[i][j] = i + j * pw[k]; break;
            }
        }
    }
    memset(f, 0x3f, sizeof(f)), f[0][1] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        memset(g, 0x3f, sizeof(g));
        for (int j = 0; j < 10000; j++) if (cnt[j] < 4) {
            for (int k = 1; k <= 9; k++) {
                chk(g[nxt[j][b[i]]][a[i]], f[j][k] + abs(a[i] - k) + 1);
            }
        }
        for (int j = 9999; j; j--) {
            for (int k = 1; k <= 9; k++) if (g[j][k] < 1e9) {
                for (int l = 1; l <= 9; l++) {
                    chk(g[d2[j][l]][l], g[j][k] + abs(k - l) + d1[j][l]);
                }
            }
        }
        swap(f, g);
    }
    printf("%d\n", *min_element(f[0], f[0] + 10));
    return 0;
}