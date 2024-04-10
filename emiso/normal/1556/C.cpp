#include <bits/stdc++.h>

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

#define MN 1001000

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    //scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        ll sum = 0, mini = 0;
        if(i % 2) continue;
        for(int j = i + 1; j < n; j++) {
            if(j % 2) {
                ll L = max(1LL, -mini);
                ll R = min(a[i], a[j] - sum);
                if(L <= R) ans += (R - L + 1);
            }
            sum += a[j] * ((j % 2) ? -1 : 1);
            mini = min(mini, sum);
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}