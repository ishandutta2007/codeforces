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

ll t, n, m, ans, a[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld %lld", &n, &m);

    if(n > m) swap(n, m);
    puts((2*n >= m && (2*n-m) % 3 == 0) ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}