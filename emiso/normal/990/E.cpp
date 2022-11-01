#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, m, k, B, b[MN], last[MN], cost[MN], al = -9999999;
ll ans;

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 0; i < m; i++) {
        scanf("%d", &B);
        b[B] = 1;
    }

    for(int i = 0; i <= n; i++) {
        if(!b[i]) al = i;
        last[i] = al;
    }

    for(int i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }

    ans = LLONG_MAX;
    for(int K = 1; K <= k; K++) {
        ll cur = 0; int found = 1;

        for(int i = 0; i < n;) {
            if(i - last[i] >= K) {
                found = 0;
                break;
            }

            cur += cost[K];
            i = last[i] + K;

            if(cur > ans) break;
        }

        if(found) ans = min(ans, cur);
    }

    if(ans == LLONG_MAX) puts("-1");
    else printf("%lld\n", ans);
    return 0;
}