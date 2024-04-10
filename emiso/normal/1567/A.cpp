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

ll t = 1, n, ans, a[MN];
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s);

    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') printf("D");
        else if(s[i] == 'D') printf("U");
        else printf("%c", s[i]);
    }
    puts("");

    if(--t) goto st;
    return 0;
}