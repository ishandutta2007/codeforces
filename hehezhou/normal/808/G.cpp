#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N], s1[N];
int len, len1, nxt[N], f[3][N];
int main() {
    scanf("%s", s + 1);
    scanf("%s", s1 + 1);
    len = strlen(s + 1), len1 = strlen(s1 + 1);
    for (int i = 2, j = 0; i <= len1; i++) {
        for (; j && (s1[i] != s1[j + 1]); ) j = nxt[j];
        if (s1[i] == s1[j + 1]) ++j;
        nxt[i] = j;
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len1; j++) {
            if (s[i] == s1[j] || s[i] == '?')
                f[i & 1][j] = max(f[i & 1][j], f[(i + 1) & 1][j - 1]);
            if (j == len1) {
                f[i & 1][j]++;
                for (int k = nxt[len1]; k; k = nxt[k])
                    f[i & 1][k] = max(f[i & 1][k], f[i & 1][j]);
            }
        }
        for (int j = 0; j <= len1; j++)
            f[i & 1][0] = max(f[i & 1][0], max(f[i & 1][j], f[(i + 1) & 1][j]));
        for (int j = 0; j <= len1; j++)
            f[(i + 1) & 1][j] = -10000000;
    }
    printf("%d\n", f[len & 1][0]);
    return 0;
}