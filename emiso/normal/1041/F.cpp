#include <bits/stdc++.h>

using namespace std;
#define MN 100010

int ans = 2, n, m, y, a[MN], b[MN];

int main() {
    scanf("%d %d", &n, &y);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    scanf("%d %d", &m, &y);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);

    for(int p = 1; p <= 1000000000; p *= 2) {
        int mask = (p * 2)-1, tmp = 0;
        map<int, int> rays;

        for(int i = 0; i < n; i++) {
            rays[a[i] & mask]++;
            tmp = max(tmp, rays[a[i] & mask]);
        }

        for(int i = 0; i < m; i++) {
            rays[(b[i]+p) & mask]++;
            tmp = max(tmp, rays[(b[i]+p) & mask]);
        }

        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}