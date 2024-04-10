#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 1000000007;
int n, K, f[maxn][maxn][3], suf[maxn][maxn];
char s[maxn];

int main() {
    scanf("%d %d %s", &n, &K, s + 1);
    f[n + 1][0][2] = 1;
    for (int i = n; i; i--) {
        int leq = s[i] - 'a', geq = 25 - leq;
        for (int j = 0; j <= K; j++) {
            f[i][j][0] = (1LL * f[i + 1][j][0] + f[i + 1][j][1] + f[i + 1][j][2]) * leq % P;
            if (j >= n - i + 1) {
                int _j = j - (n - i + 1);
                f[i][j][2] = (1LL * f[i + 1][_j][0] + f[i + 1][_j][1] + f[i + 1][_j][2]) * geq % P;
            }
            f[i][j][1] = suf[i + 1][j];
            int pos = n + 1;
            for (int k = i; k <= n; k++) {
                if (j < (n - k) * (k - i + 1)) { pos = k; break; }
                int _j = j - (n - k) * (k - i + 1);
                f[i][j][1] = (f[i][j][1] + f[k + 1][_j][2]) % P;
            }
            for (int k = n; k >= pos; k--) {
                if (j < (n - k) * (k - i + 1)) break;
                int _j = j - (n - k) * (k - i + 1);
                f[i][j][1] = (f[i][j][1] + f[k + 1][_j][2]) % P;
            }
            suf[i][j] = (suf[i + 1][j] + f[i][j][0]) % P;
        }
    }
    printf("%d\n", (1LL * f[1][K][0] + f[1][K][1] + f[1][K][2]) % P);
    return 0;
}