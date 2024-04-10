#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, pre[maxn];
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %s", &n, &m, s + 1);
        int all = count(s + 1, s + n + 1, '1'), g = __gcd(n, all);
        int x = all / g, y = n / g;
        if (m % y) { puts("-1"); continue; }
        int need = m / y * x;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (s[i] == '1');
        }
        bool flag = 0;
        for (int i = m; i <= n; i++) {
            if (pre[i] - pre[i - m] == need) {
                printf("1\n%d %d\n", i - m + 1, i);
                flag = 1; break;
            }
        }
        if (flag) continue;
        flag = 0;
        for (int i = 1; i < m; i++) if (pre[i] + pre[n] - pre[n - (m - i)] == need) {
            printf("2\n1 %d\n%d %d\n", i, n - (m - i) + 1, n);
            flag = 1; break;
        }
        assert(flag);
    }
    return 0;
}