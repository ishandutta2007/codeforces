#include <bits/stdc++.h>

#define MN 100010

using namespace std;

int n, m, a[MN], b[MN], mini[MN], deg[MN];

int main() {
    scanf("%d %d", &n, &m);
    memset(mini, -1, sizeof mini);

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &a[i], &b[i]);

        deg[a[i]]++;
        if(mini[a[i]] == -1) mini[a[i]] = 200000000;
        if(a[i] <= b[i]) mini[a[i]] = min(mini[a[i]], b[i] - a[i]);
        else mini[a[i]] = min(mini[a[i]], b[i] - a[i] + n);
    }

    for(int i = 1; i <= n; i++) {
        int ans = 0;
        for(int j = i, it = 0; it < n; it++) {
            if(deg[j] > 0)
                ans = max(ans, it + (deg[j]-1) * n + mini[j]);

            j++;
            if(j > n) j = 1;
        }

        printf("%d ", ans);
    }
    return 0;
}