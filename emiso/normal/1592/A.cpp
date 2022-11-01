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

ll t = 1, n, h, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &h);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n, greater<ll>());

    if(h <= a[0]) printf("1\n");
    else {
        int ts = 2 * (h / (a[0] + a[1]));
        h %= (a[0] + a[1]);
        if(h) {
            h -= a[0];
            ts++;
            if(h > 0) ts++;
        }
        printf("%d\n", ts);
    }
    if(--t) goto st;
    return 0;
}