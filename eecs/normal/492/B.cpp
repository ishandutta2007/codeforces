#include <bits/stdc++.h>
using namespace std;

int n, L, a[1010];

int main() {
    scanf("%d %d", &n, &L);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 2 * max(a[1], L - a[n]);
    for (int i = 1; i < n; i++) {
        ans = max(ans, a[i + 1] - a[i]);
    }
    if (ans % 2) printf("%d.5\n", ans / 2);
    else printf("%d\n", ans / 2);
    return 0;
}