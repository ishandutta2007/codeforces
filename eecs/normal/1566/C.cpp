#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;
char s[2][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s %s", s[0] + 1, s[1] + 1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (s[0][i] != s[1][i]) ans += 2;
        }
        for (int i = 1; i <= n; i++) if (s[0][i] == s[1][i]) {
            int cnt0 = 0, cnt1 = 0;
            int j = i;
            for (; j <= n && s[0][j] == s[1][j]; j++) {
                if (s[0][j] == '0') cnt0++;
                else cnt1++;
                if (cnt0 && cnt1) {
                    ans += 2 + max(0, cnt0 - 1), cnt0 = cnt1 = 0;
                }
            }
            i = j, ans += cnt0;
        }
        printf("%d\n", ans);
    }
    return 0;
}