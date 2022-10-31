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

ll sol, n, k, t, a[MN], l[MN], r[MN], d[MN];
vector<pair<int, int>> ev[MN];

ll ok(int ag) {
    ll ret = 0, maxi = 0;
    for(ll i = 0; i <= n; i++) {
        maxi = max(maxi, i);
        for(auto e : ev[i]) {
            if(e.second <= ag) continue;
            else {
                if(maxi < e.first) {
                    ret += (e.first - maxi) * 2;
                    maxi = e.first;
                }
            }
        }
    }
    return ret;
}

int main() {
    scanf("%lld %lld %lld %lld", &sol, &n, &k, &t);
    t -= (n + 1);

    for(int i = 0; i < sol; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + sol, greater<ll>());

    for(int i = 0; i < k; i++) {
        scanf("%lld %lld %lld", &l[i], &r[i], &d[i]);
        ev[l[i]-1].emplace_back(r[i], d[i]);
    }

    ll l = 0, r = sol, m;
    while(l < r) {
        m = (l + r + 1) / 2;
        if(ok(a[m-1]) <= t) l = m;
        else r = m - 1;
    }
    printf("%lld\n", l);
    return 0;
}