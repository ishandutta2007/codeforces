#include <bits/stdc++.h>
using namespace std;

const int maxn = 65;
int T, r, c;
char s[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &r, &c);
        int cnt = 0;
        for (int i = 1; i <= r; i++) {
            scanf("%s", s[i] + 1);
            for (int j = 1; j <= c; j++) {
                if (s[i][j] == 'A') cnt++;
            }
        }
        if (!cnt) { puts("MORTAL"); continue; }
        if (cnt == r * c) { puts("0"); continue; }
        int ans = 4;
        for (int i = 1; i <= r; i++) {
            bool flag = 1;
            for (int j = 1; j <= c; j++) {
                flag &= s[i][j] == 'A';
                if (s[i][j] == 'A' && (i == 1 || i == r || j == 1 || j == c)) {
                    ans = min(ans, 3);
                    if ((i == 1 || i == r) && (j == 1 || j == c)) ans = min(ans, 2);
                }
            }
            if (flag) {
                if (i == 1 || i == r) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        for (int i = 1; i <= c; i++) {
            bool flag = 1;
            for (int j = 1; j <= r; j++) {
                flag &= s[j][i] == 'A';
            }
            if (flag) {
                if (i == 1 || i == c) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}