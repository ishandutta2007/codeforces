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

ll t, n, x, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld %lld %s", &n, &x, s);

    map<int, int> f; int delta = 0, maxi = 0, mini = 0;
    for(int i = 0; i < n; i++) {
        f[delta]++;
        if(s[i] == '1') delta--;
        else delta++;
        maxi = max(maxi, delta);
        mini = min(mini, delta);
    }

    if(delta == 0) {
        if(!f.count(x)) puts("0");
        else puts("-1");
    } else {
        ll l = (x - maxi) / delta, r = (x - mini) / delta;
        if(l > r) swap(l, r);

        for(int i = max(l-2, 0LL); i <= r+2; i++) {
            if(f.count(x-delta*i)) ans += f[x-delta*i];
        }
        printf("%lld\n", ans);
    }

    if(--t) goto st;
    return 0;
}