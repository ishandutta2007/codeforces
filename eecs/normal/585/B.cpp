#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, K;
bool chk[maxn][maxn];
char s[3][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &K);
        int stx = -1;
        for (int i = 0; i < 3; i++) {
            scanf("%s", s[i] + 1);
            if (s[i][1] == 's') stx = i;
        }
        memset(chk, 0, sizeof(chk));
        int pos = 1;
        chk[stx][pos] = 1;
        bool flag = 1;
        while (pos < n) {
            for (int i = 0; i < 3; i++) if (chk[i][pos]) {
                if (s[i][pos + 1] != '.') continue;
                chk[i][pos + 1] = 1;
                if (i) chk[i - 1][pos + 1] = 1;
                if (i <= 1) chk[i + 1][pos + 1] = 1;
            }
            pos++;
            flag = 0;
            for (int i = 0; i < 3; i++) if (chk[i][pos]) {
                if (s[i][pos] != '.') chk[i][pos] = 0;
                chk[i][pos + 2] |= chk[i][pos];
                if (chk[i][pos]) flag = 1;
            }
            if (!flag) break;
            pos += 2;
            if (pos > n) break;
            flag = 0;
            for (int i = 0; i < 3; i++) if (chk[i][pos]) {
                if (s[i][pos] == '.') flag = 1;
                else chk[i][pos] = 0;
            }
            if (!flag) break;
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}