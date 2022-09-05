#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 1000000007;
int T, n, f[maxn][maxn][2], g[maxn][maxn][2];
char a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s %s", &n, a + 1, b + 1);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k : {0, 1}) f[i][j][k] = g[i][j][k] = 0;
            }
        }
        g[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (int k : {0, 1}) for (int x : {0, 1}) for (int y : {0, 1}) {
                    if (a[i] != '?' && x != a[i] - '0') continue;
                    if (b[i] != '?' && y != b[i] - '0') continue;
                    int lstf = f[i - 1][j][k], lstg = g[i - 1][j][k];
                    lstf = (lstf + 1LL * j * lstg) % P;
                    int _x = x, _j = j;
                    if (j && _x == k) _x ^= 1, _j--;
                    if (_x ^ y) _j++;
                    (f[i][_j][_x] += lstf) %= P;
                    (g[i][_j][_x] += lstg) %= P;
                }
            }
        }
        printf("%d\n", (f[n][0][0] + f[n][0][1]) % P);
    }
    return 0;
}