#include <bits/stdc++.h>
using namespace std;
int t, n, l, r, k;
int a[110];
inline void rmain() {
    scanf("%d%d%d%d", &n, &l, &r, &k);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (a[i] >= l && a[i] <= r) {
        if (a[i] <= k) k -= a[i], ans++;
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}