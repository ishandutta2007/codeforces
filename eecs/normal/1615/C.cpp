#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n;
char a[maxn], b[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s %s", &n, a + 1, b + 1);
        int ans = INT_MAX;
        for (int parity : {0, 1}) {
            int x = 0, c0 = 0;
            for (int i = 1; i <= n; i++) {
                if (a[i] == b[i] && parity == 1) x++, c0 += (a[i] == '0');
                if (a[i] != b[i] && parity == 0) x++, c0 += (a[i] == '0');
            }
            if (x % 2 != parity % 2) continue;
            int c1 = x - c0;
            if (c1 == c0 || c1 == c0 + 1) ans = min(ans, x);
        }
        if (ans == INT_MAX) puts("-1");
        else printf("%d\n", ans);
    }
    return 0;
}