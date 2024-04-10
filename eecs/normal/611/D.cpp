#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 1000000007;
int n, lcp[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
char s[maxn];

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = n; i; i--) {
        for (int j = n; j; j--) {
            if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
    }
    auto comp = [&](int i, int j, int k) {
        if (lcp[i][j] >= k) return false;
        return s[i + lcp[i][j]] < s[j + lcp[i][j]];
    };
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 1; j--) {
            if (s[j] > '0') {
                f[i][j] = g[j - 1][max(1, j - (i - j))];
                if (j - (i - j) > 1 && comp(j - (i - j) - 1, j, i - j + 1)) {
                    (f[i][j] += f[j - 1][j - (i - j) - 1]) %= P;
                }
            }
            g[i][j] = (g[i][j + 1] + f[i][j]) % P;
        }
        f[i][1] = 1, g[i][1] = (g[i][2] + 1) % P;
    }
    printf("%d\n", g[n][1]);
    return 0;
}