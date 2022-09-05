#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010, P = 998244353;
int n, m, ans, f[maxn][maxn][2];
char s[maxn], t[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            if (i <= n && j <= m) {
                red(f[i + 1][j][0] -= P - 1);
                red(f[i][j + 1][1] -= P - 1);
            }
            for (int k : {0, 1}) {
                char c = !k ? s[i - 1] : t[j - 1];
                if (s[i] ^ c) red(f[i + 1][j][0] += f[i][j][k] - P);
                if (t[j] ^ c) red(f[i][j + 1][1] += f[i][j][k] - P);
            }
        }
    }
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= m + 1; j++) {
            red(ans += f[i][j][0] - P);
            red(ans += f[i][j][1] - P);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (j > i && s[j] == s[j - 1]) break;
            red(ans -= m);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            if (j > i && t[j] == t[j - 1]) break;
            red(ans -= n);
        }
    }
    printf("%d\n", ans);
    return 0;
}