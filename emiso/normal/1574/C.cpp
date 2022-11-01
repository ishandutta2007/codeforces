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

ll t = 1, n, m, ans, a[MN];
//char s[MN]; string str;

int main() {
    //scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    ll sum = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);

    scanf("%lld", &m);

    for(ll i = 0, x, y; i < m; i++) {
        scanf("%lld %lld", &x, &y);
        ans = LLONG_MAX;
        int tt = lower_bound(a, a + n, x) - a;
        if(tt < n) ans = min(ans, max(0LL, y - sum + a[tt]) + max(0LL, x - a[tt]));
        if(tt--) ans = min(ans, max(0LL, y - sum + a[tt]) + max(0LL, x - a[tt]));
        printf("%lld\n", ans);
    }

    if(--t) goto st;
    return 0;
}