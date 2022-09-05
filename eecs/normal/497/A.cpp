#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int n, m, ans, cnt[maxn];
char s[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    while (1) {
        bool flag = 0;
        for (int i = 1; i < n && !flag; i++) {
            for (int j = 1; j <= m && !flag; j++) if (!cnt[j]) {
                if (s[i][j] < s[i + 1][j]) break;
                if (s[i][j] > s[i + 1][j]) cnt[j] = flag = 1;
            }
        }
        if (!flag) break;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}