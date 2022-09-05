#include <bits/stdc++.h>
using namespace std;

int T, n, l;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &l);
        vector<int> c(l);
        for (int i = 0, x; i < n; i++) {
            scanf("%d", &x);
            for (int j = 0; j < l; j++) {
                if (x >> j & 1) c[j]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < l; i++) {
            if (c[i] > n - c[i]) ans |= 1 << i;
        }
        printf("%d\n", ans);
    }
    return 0;
}