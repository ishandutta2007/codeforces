#include <bits/stdc++.h>

#define MN 3535

using namespace std;

int t, n, m, k, a[MN], b[MN];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &n, &m, &k);

        k = min(k, m-1);
        int d = n - m;

        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for(int i = 0; i + d < n; i++) {
            b[i] = max(a[i], a[i+d]);
        }

        int ans = 0;
        for(int l = 0; l <= k; l++) {
            int r = (n-1) - (k-l);

            int tmp = INT_MAX;
            for(int i = l; i + d <= r; i++) {
                tmp = min(tmp, b[i]);
            }
            ans = max(ans, tmp);
        }

        printf("%d\n", ans);
    }
    return 0;
}