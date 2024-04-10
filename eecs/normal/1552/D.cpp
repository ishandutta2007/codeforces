#include <bits/stdc++.h>
using namespace std;

int T, n, a[11];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ways = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        function<void(int, int)> dfs = [&](int p, int v) {
            if (p > n) {
                if (!v) ways++;
                return;
            }
            dfs(p + 1, v - a[p]);
            dfs(p + 1, v);
            dfs(p + 1, v + a[p]);
        };
        dfs(1, 0);
        if (ways > 1) puts("YES");
        else puts("NO");
    }
    return 0;
}