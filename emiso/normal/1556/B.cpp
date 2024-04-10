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

ll t = 1, n, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    int f[] = {0, 0};
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        a[i] %= 2;
        f[a[i]]++;
    }

    if(min(f[0], f[1]) + 1 < max(f[0], f[1])) puts("-1");
    else {
        ans = LLONG_MAX;
        for(int z = 0; z < 2; z++) {
            if(f[0] < f[1]) {
                swap(f[0], f[1]);
                for(int i = 0; i < n; i++) a[i] ^= 1;
            }
            ll tmp = 0;
            for(int i = 0, j = 0; i < n; i++) {
                if(a[i] == 0) {
                    tmp += abs(i - j);
                    j += 2;
                }
            }
            ans = min(ans, tmp);
            if(f[0] != f[1]) break;
            for(int i = 0; i < n; i++) a[i] ^= 1;
        }
        printf("%lld\n", ans);
    }
    if(--t) goto st;
    return 0;
}