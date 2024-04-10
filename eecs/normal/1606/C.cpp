#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int T, n, K, a[11];
ll b[19], pw[19], pre[19];

int main() {
    scanf("%d", &T);
    for (int i = pw[0] = 1; i <= 18; i++) {
        pw[i] = 10 * pw[i - 1];
    }
    while (T--) {
        scanf("%d %d", &n, &K);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= 18; i++) { 
            for (int j = n; j; j--) {
                if (a[j] <= i) { b[i] = pw[i - a[j]]; break; }
            }
            pre[i] = (i ? pre[i - 1] : 0) + b[i];
        }
        ll ans = 0;
        for (int i = 18; ~i; i--) {
            for (int j = 0; j <= 9; j++) {
                if (j * b[i] + 9 * (i ? pre[i - 1] : 0) > K) {
                    ans += j * pw[i], K -= j * b[i]; break;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}