#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, l, ans, a[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &l);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > l) ans++;
        if (a[i] > l && a[i - 1] > l) ans--;
    }
    while (m--) {
        int op, p, d;
        scanf("%d", &op);
        if (!op) {
            printf("%d\n", ans);
        } else {
            scanf("%d %d", &p, &d);
            if (a[p] > l) ans--;
            if (a[p] > l && a[p - 1] > l) ans++;
            if (a[p] > l && a[p + 1] > l) ans++;
            a[p] = min(l + 1, a[p] + d);
            if (a[p] > l) ans++;
            if (a[p] > l && a[p - 1] > l) ans--;
            if (a[p] > l && a[p + 1] > l) ans--;
        }
    }
    return 0;
}