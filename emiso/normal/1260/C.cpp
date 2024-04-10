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

ll t, r, b, k, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld %lld %lld", &r, &b, &k);
    if(r > b) swap(r, b);

    trace(r, b, (b - __gcd(b, r) + r - 1) / r);
    puts(((b - __gcd(b, r) + r - 1) / r < k) ? "OBEY" : "REBEL");
    if(--t) goto st;
    return 0;
}