#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 1000000007;
int n, f[30][maxn];
char s[maxn];

int main() {
    scanf("%d %s", &n, s + 1);
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a' + 1, ans = 1;
        for (int j = 1; j <= n; j++) {
            f[0][j] = (f[0][j] - f[c][j] + P) % P;
            f[c][j] = ans, (ans += f[0][j]) %= P;
            (f[0][j] += f[c][j]) %= P;
        }
    }
    printf("%d\n", f[0][n]);
    return 0;
}