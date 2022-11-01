#include <bits/stdc++.h>

using namespace std;

long long ans;
int n, occ[2][100010], x, l, r;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i++) {
        scanf("%d", &x);
        if(occ[0][x] == 0) occ[0][x] = i;
        else {
            occ[1][x] = i;
            if(occ[1][x] < occ[0][x]) swap(occ[0][x], occ[1][x]);
        }
    }
    l = r = 1;

    for(int i = 1; i <= n; i++) {
        ans += abs(occ[0][i] - l);
        ans += abs(occ[1][i] - r);
        l = occ[0][i];
        r = occ[1][i];
    }

    printf("%lld\n", ans);
    return 0;
}