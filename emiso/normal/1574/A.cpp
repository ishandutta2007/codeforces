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

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) printf("(");
        for(int j = 0; j < i; j++) printf(")");
        for(int j = 2*i; j < 2*n; j += 2) printf("()");
        puts("");
    }

    if(--t) goto st;
    return 0;
}