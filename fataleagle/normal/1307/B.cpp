#include <bits/stdc++.h>

using namespace std;

int a[100000];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int ans = 2 * x + 1;
        int maxa = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            if (a[i] == x) {
                ans = 1;
            }
            maxa = max(maxa, a[i]);
        }
        if (x <= maxa) {
            ans = min(ans, 2);
        }
        else {
            ans = min(ans, (x + maxa - 1) / maxa);
        }
        printf("%d\n", ans);
    }
    return 0;
}