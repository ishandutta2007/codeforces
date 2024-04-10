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

ll t = 1, n, ans, x, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    scanf("%lld", &x);

    bool last = false;
    ll sum = 0;

    for(int i = 0; i < n; i++) {
        if (last == false) {
            last = true;
            sum = a[i] - x;
        } else {
            sum += a[i] - x;
            if (sum < 0) {
                ans++;
                last = false;
            } else {
                sum = min(sum, a[i] - x);
            }
        }
    }

    printf("%lld\n", n - ans);
    if(--t) goto st;
    return 0;
}