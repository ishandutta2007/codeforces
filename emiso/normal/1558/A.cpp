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

ll t = 1, a, b, ans, can[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &a, &b);
    fill(can, can + a + b + 1, 0);

    for(int z = 0; z < 2; z++) {
        ll ta = a, tb = b, ca = 0, cb = 0, maxi = 0;
        for(ll i = 0; i <= a + b; i++) {
            if(i % 2 == 0) {
                if(ta) {
                    ta--;
                    ca++;
                    maxi++;
                } else tb--;
            } else {
                if(tb) {
                    tb--;
                    cb++;
                    maxi++;
                } else ta--;
            }
        }
        for(ll i = maxi, j = 0; j <= min(ca, cb); j++, i -= 2) {
            if(!can[i]) ans++;
            can[i] = 1;
        }
        swap(a, b);
    }

    printf("%lld\n", ans);
    for(int i = 0; i <= a + b; i++) if(can[i]) printf("%d ", i);
    puts("");

    if(--t) goto st;
    return 0;
}