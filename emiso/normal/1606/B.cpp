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

ll t = 1, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    n--;
    ll cur = 1;
    while (n > 0 && cur < k) {
        ans++;
        n -= cur;
        cur = min(2*cur, k);
    }
    if(n > 0) ans += (n + cur - 1) / cur;

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}