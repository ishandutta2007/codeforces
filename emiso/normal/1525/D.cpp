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

ll t, n, ans, a[MN], b[5050], c[5050], occ, unoc, dp[5050][5050];

ll solve(int i, int j) {
    if(j > unoc) return INT_MAX/2;
    if(i == occ) return 0;
    ll &x = dp[i][j];
    if(x != -1) return x;

    x = solve(i, j + 1);
    x = min(x, solve(i + 1, j + 1) + abs(b[i] - c[j]));

    return x;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] == 1) {
            b[occ++] = i;
        } else {
            c[unoc++] = i;
        }
    }

    ans = INT_MAX;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < unoc; i++)
        ans = min(ans, solve(0, i));
    printf("%lld\n", ans);
    return 0;
}