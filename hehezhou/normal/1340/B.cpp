#include <bits/stdc++.h>
using namespace std;
int cnt[128];
char s[10][9] = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};
int n, k;
inline int calc(char *s) {
    int a = 0;
    for (int i = 0; i < 7; i++) {
        a = a << 1 | (s[i] ^ 48);
    }
    return a;
}
int d[10];
char S[10];
int a[2010];
int dp[2010][2010];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < 1 << 7; i++) cnt[i] = cnt[i >> 1] + (i & 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", S);
        a[i] = calc(S);
    }
    for (int i = 0; i < 10; i++) d[i] = calc(s[i]);
    dp[n + 1][0] = 1;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < 10; j++) {
            if ((a[i] & d[j]) != a[i]) continue;
            int c = cnt[a[i] ^ d[j]];
            for (int l = c; l <= k; l++) {
                dp[i][l] |= dp[i + 1][l - c];
            }
        }
    }
    if (!dp[1][k]) return puts("-1"), 0;
    int now = k;
    for (int i = 1; i <= n; i++) {
        for (int j = 9; j >= 0; j--) {
            if ((a[i] & d[j]) != a[i]) continue;
            int c = cnt[a[i] ^ d[j]];
            if (dp[i + 1][now - c]) {
                putchar(j + '0');
                now -= c;
                break;
            }
        }
    }
    return 0;
}