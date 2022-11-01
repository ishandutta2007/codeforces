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

#define MOD 1'000'000'007

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &k, &n);

    ll mult = 1;
    while(n) {
        ans += mult * (n % 2);
        if(ans >= MOD) ans -= MOD;
        mult = mult * k % MOD;
        n /= 2;
    }
    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}