#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

ll t, n, ans, a[MN], lg, dp[18][MN];

ll solve(int i, int buys) {
    if(buys == lg) return (i == n);
    if(i >= n) return LLONG_MAX/2;
    ll &x = dp[buys][i];
    if(x != -1) return x;
    x = solve(i + 1, buys);
    x = min(x, solve(max((4<<buys)-1, i + 1), buys + 1) + a[i]);
    trace2(i, buys, a[i], x);
    return x;
}

int main() {
    scanf("%lld", &n);
    lg = __builtin_ctzll(n);

    int ja = -1;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] == -1) ja = i;
        if(ja < 0) a[i] = 0;
    }
    swap(a[0], a[ja]);

    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve(1, 0));
    return 0;
}