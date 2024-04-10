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

#define MOD 998244353

ll n, p[MN], x[MN], y[MN], pref[MN];

ll range(int i, int j) {
    if(i > j) return 0;
    return (pref[j] - pref[i-1] - x[i] + x[i-1] + MOD + MOD) % MOD;
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld", &x[i], &y[i], &p[i]);
    }
    x[0] = 0;

    pref[0] = 0;
    for(int i = 1; i <= n; i++) {
        int jump = lower_bound(x + 1, x + n + 1, y[i]) - x;
        pref[i] = (pref[i-1]
                    + (x[i] - x[i-1] + MOD)
                    + (x[jump] - y[i] + MOD)
                    + range(jump, i-1)
                    + (jump != i)*(x[i] - x[i-1] + MOD)) % MOD;
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        if(p[i] == 0) {
            ans = (ans + x[i] - x[i-1] + MOD) % MOD;
        } else {
            ans = (ans + x[i] - x[i-1] + MOD
                   + range(i, i)) % MOD;
        }
        assert(ans >= 0 && ans < MOD);
    }
    printf("%lld\n", ans);
    return 0;
}