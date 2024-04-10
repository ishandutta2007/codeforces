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

ll t = 1, n, a[MN], best[512];

int main() {
    scanf("%lld", &n);
    
    fill(best, best + 512, INT_MAX);
    best[0] = -1;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        for(int x = 0; x < 512; x++) {
            if(best[x ^ a[i]] < a[i]) {
                best[x] = min(best[x], a[i]);
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i < 512; i++)
        ans += (best[i] < INT_MAX);
    
    printf("%lld\n", ans);
    for(int i = 0; i < 512; i++)
        if(best[i] < INT_MAX)
            printf("%d ", i);

    return 0;
}