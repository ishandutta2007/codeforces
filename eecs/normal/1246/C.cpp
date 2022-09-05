#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010, P = 1000000007;
int n, m, f[maxn][maxn][2], s1[maxn][maxn], s2[maxn][maxn];
int pre[maxn][maxn], suf[maxn][maxn], cur[maxn];
char s[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= m; j++) {
            cur[j] = 1, pre[i][j] = pre[i][j - 1], suf[i][j] = suf[i - 1][j];
            if (s[i][j] == 'R') pre[i][j]++, suf[i][j]++;
        }
    }
    if (n == 1 && m == 1) puts("1"), exit(0);
    s1[1][1] = s2[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, k = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;
            while (k + 1 <= j && pre[i][m] - pre[i][k] > m - j) k++;
            while (cur[j] + 1 <= i && suf[n][j] - suf[cur[j]][j] > n - i) cur[j]++;
            f[i][j][1] = (s1[i][j - 1] - s1[i][k - 1] + P) % P;
            f[i][j][0] = (s2[i - 1][j] - s2[cur[j] - 1][j] + P) % P;
            s1[i][j] = (s1[i][j - 1] + f[i][j][0]) % P;
            s2[i][j] = (s2[i - 1][j] + f[i][j][1]) % P;
        }
    }
    printf("%d\n", (f[n][m][0] + f[n][m][1]) % P);
    return 0;
}