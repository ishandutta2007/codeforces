#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, k, x[MN], y[MN], can[110];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    memset(can, 0, sizeof can);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    ll ans = -1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k) can[i]++;
        }
        if(can[i] == n) ans = 1;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}