#include <bits/stdc++.h>
using namespace std;
int T, a[200010], n, id[200010];
int ans[200010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), id[i] = i;
    sort(id + 1, id + 1 + n, [](int a, int b) {
        return ::a[a] > ::a[b];
    });
    for (int i = 1; i <= n; i += 2) ans[id[i]] = i / 2 + 1;
    for (int i = 2; i <= n; i += 2) ans[id[i]] = -i / 2;
    long long sum = 0;
    for (int i = 1; i <= n; i++) sum += 1ll * a[i] * abs(ans[i]) * 2;
    printf("%lld\n", sum);
    for (int i = 0; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}