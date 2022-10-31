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

ll t, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    if(!is_sorted(a, a + n)) {
        ans += (a[0] != *min_element(a, a + n));
        ans += (a[n-1] != *max_element(a, a + n));
        ans += (a[0] == *max_element(a, a + n) && a[n-1] == *min_element(a, a + n));
        if(ans == 0) ans = 1;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}