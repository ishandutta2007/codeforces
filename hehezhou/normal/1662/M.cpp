#include <bits/stdc++.h>
using namespace std;
void rmain() {
    int n, m;
    scanf("%d%d", &n, &m);
    int maxr = 0, maxw = 0;
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        maxr = max(maxr, a);
        maxw = max(maxw, b);
    }
    if (maxr + maxw > n) return puts("IMPOSSIBLE"), void();
    for (int i = 1; i <= maxr; i++) putchar('R');
    for (int i = maxr + 1; i <= n; i++) putchar('W');
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}