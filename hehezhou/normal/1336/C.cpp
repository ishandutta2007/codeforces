#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int dp[3010][3010];
char s[3010], t[3010];
int n, m;
inline int cmp(int a, int b) {
    return b >= m || s[a] == t[b];
}
int main() {
    scanf("%s%s", s, t);
    n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; i++) if (cmp(0, i)) dp[i][i] = 2;
    for (int i = n; i --> 0; ) {
        for (int j = i; j < n; j++) {
            if (i > 0) dp[i - 1][j] = (dp[i - 1][j] + dp[i][j] * cmp(j - i + 1, i - 1)) % mod;
            if (j < n - 1) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j] * cmp(j - i + 1, j + 1)) % mod;
        }
    }
    int ans = 0;
    for (int i = m - 1; i < n; i++) ans = (ans + dp[0][i]) % mod;
    return cout << ans << endl, 0;
}