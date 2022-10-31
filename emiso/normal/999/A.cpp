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

ll t, n, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    t = 1;//scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld %lld", &n, &k);

    int fst = -1, lst = -2;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i] > k) {
            lst = i;
            if(fst == -1) fst = i;
        }
    }

    printf("%lld\n", n - (lst - fst + 1));
    if(--t) goto st;
    return 0;
}