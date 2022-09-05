#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
int T, n, x, w[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &w[i]);
        }
        if (x == accumulate(w + 1, w + n + 1, 0)) {
            puts("NO"); continue;
        }
        sort(w + 1, w + n + 1);
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += w[i];
            if (cur == x) { swap(w[i], w[i + 1]); break; }
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            printf("%d ", w[i]);
        }
        putchar('\n');
    }
    return 0;
}