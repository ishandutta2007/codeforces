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

ll t = 1, n, ans, a, b, c;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", (a + c) % 2);
    if(--t) goto st;
    return 0;
}