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
char s[MN]; string str;

int main() {
    t = 1;//scanf("%lld", &t);
    st:
    ans = 0;
    scanf("%lld %s", &n, s); str = s;

    for(int i = 1; i <= n; i++)
        if(n % i == 0)
            reverse(str.begin(), str.begin()+i);
    printf("%s\n", str.c_str());
    if(--t) goto st;
    return 0;
}