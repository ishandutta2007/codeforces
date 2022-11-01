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

ll t = 1, n, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    int ans = n - 1;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            int ch = 0;
            for (int i = 0; i < n; i++) {
                if ((a[r] - a[l]) * (r - i) != (a[r] - a[i]) * (r - l)) {
                    ch++;
                }
            }
            ans = min(ans, ch);
        }
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}