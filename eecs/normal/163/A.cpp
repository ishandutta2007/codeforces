#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, P = 1000000007;
int n, m, ans, f[maxn][maxn];
char s[maxn], t[maxn];

int main() {
    scanf("%s %s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            if (s[i] == t[j]) f[i][j] = (f[i + 1][j + 1] + 1) % P;
            (f[i][j] += f[i][j + 1]) %= P;
        }
        (ans += f[i][1]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}