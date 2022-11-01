#include <bits/stdc++.h>

using namespace std;

int n, m, cur, ans, x;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        cur = INT_MAX;
        for(int j = 0; j < m; j++) {
            scanf("%d", &x);
            cur = min(cur, x);
        }
        ans = max(ans, cur);
    }

    printf("%d\n", ans);
    return 0;
}