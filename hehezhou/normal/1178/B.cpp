#include <bits/stdc++.h>
int n, pre[1000010], suc[1000010];
char s[1000010];
long long ans = 0;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + ((s[i] + s[i - 1]) == 2 * 'v');
    }
    for (int i = n - 1; i >= 1; i--) {
        suc[i] = suc[i + 1] + ((s[i] + s[i + 1]) == 2 * 'v');
    }
    for (int i = 1; i <= n; i++) if (s[i] == 'o') ans += 1ll * pre[i - 1] * suc[i + 1];
    printf("%I64d\n", ans);
    return 0;
}