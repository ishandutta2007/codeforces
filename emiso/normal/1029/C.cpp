#include <bits/stdc++.h>

using namespace std;

int n, l[300030], r[300030], L, R, ans;

int main() {
    scanf("%d", &n);

    int minr = 0, maxl = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
        if(r[minr] > r[i]) minr = i;
        if(l[maxl] < l[i]) maxl = i;
    }

    L = 0, R = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(i == minr) continue;
        L = max(L, l[i]);
        R = min(R, r[i]);
    }
    ans = max(0, R - L);

    L = 0, R = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(i == maxl) continue;
        L = max(L, l[i]);
        R = min(R, r[i]);
    }
    ans = max(ans, R - L);

    printf("%d\n", ans);
    return 0;
}