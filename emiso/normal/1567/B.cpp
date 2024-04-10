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

ll t = 1, n, m, ans, a[MN];
//char s[MN]; string str;

int main() {
    for(int i = 1; i < MN; i++) a[i] = a[i-1] ^ i;

    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    ans = n;
    m ^= a[n-1];
    if(m == 0);
    else if(m == n) ans += 2;
    else ans++;

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}