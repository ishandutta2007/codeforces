#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] <= a[i - 1]) a[i]++;
        if (a[i] != a[i - 1]) ans++;
    }
    printf("%d\n", ans);
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}