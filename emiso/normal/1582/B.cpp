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

    int z = 0, o = 0;
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        z += (a[i] == 0);
        o += (a[i] == 1);
    }

    printf("%lld\n", (1LL << z) * o);
    if(--t) goto st;
    return 0;
}