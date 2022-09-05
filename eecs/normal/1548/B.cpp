#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n;
long long a[maxn], st[20][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        if (n == 1) { puts("1"); continue; }
        for (int i = 1; i < n; i++) {
            a[i] = abs(a[i + 1] - a[i]);
            st[0][i] = a[i];
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 1; j + (1 << i) - 1 < n; j++) {
                st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
        int ans = 1;
        for (int i = 1; i < n; i++) {
            long long g = a[i];
            if (g == 1) continue;
            int cur = i + 1;
            for (int j = 19; ~j; j--) if (cur + (1 << j) - 1 < n) {
                long long v = __gcd(g, st[j][cur]);
                if (v == 1) continue;
                g = v, cur += 1 << j;
            }
            ans = max(ans, cur - i + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}