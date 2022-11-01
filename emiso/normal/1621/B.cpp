#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n, ans, l[MN], r[MN], c[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ans = LLONG_MAX;
    map<int, ll> cost;
    ll mini = LLONG_MAX, maxi = LLONG_MIN;
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &l[i], &r[i], &c[i]);

        if (l[i] < mini || r[i] > maxi) {
            ans = LLONG_MAX;
        }
        mini = min(mini, l[i]);
        maxi = max(maxi, r[i]);

        if (cost.count(l[i])) {
            cost[l[i]] = min(cost[l[i]], c[i]);
        } else {
            cost[l[i]] = c[i];
        }
        if (cost.count(r[i])) {
            cost[r[i]] = min(cost[r[i]], c[i]);
        } else {
            cost[r[i]] = c[i];
        }

        ll c2 = cost[mini] + cost[maxi];
        if (l[i] == mini && r[i] == maxi) {
            c2 = min(c2, c[i]);
        }

        //trace2(mini, maxi, c2);
        ans = min(ans, c2);
        printf("%lld\n", ans);
    }

    if(--t) goto st;
    return 0;
}