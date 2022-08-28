#include <bits/stdc++.h>
using namespace std;
int T, n, a[200010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 0;
    for (int d = 0; d < 30; d++) {
        int cur = 0x7fffffff;
        int cnt = 0;
        for (int i = 1; i <= n; i++) if ((a[i] >> d) & 1) cnt++;
        ans = __gcd(ans, cnt);
    }
    for (int i = 1; i <= n; i++) if (ans % i == 0) printf("%d ", i);
    puts("");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}