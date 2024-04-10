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
char s[MN], let; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s); let = s[0];
    scanf("%s", s); str = s;

    int eq = 1, half = 0;
    for(int i = 0; i < n; i++) {
        if(str[i] != let) eq = 0;
        else if(i >= n / 2) half = i;
    }

    if(eq) puts("0");
    else if(half) printf("1\n%d\n", half + 1);
    else printf("2\n%lld %lld\n", n-1, n);
    if(--t) goto st;
    return 0;
}