#include <bits/stdc++.h>
using namespace std;

int n, m, q;
bool chk[1010];
char s[1010], t[1010];

int main() {
    scanf("%d %d %d", &n, &m, &q);
    scanf("%s %s", s + 1, t + 1);
    for (int i = 1; i + m - 1 <= n; i++) {
        chk[i] = 1;
        for (int j = 1; j <= m; j++) chk[i] &= s[i + j - 1] == t[j];
    }
    while (q--) {
        int l, r, ans = 0;
        scanf("%d %d", &l, &r);
        for (int i = l; i + m - 1 <= r; i++) {
            if (chk[i]) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}