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

    int flag = 0;
    for(int i = 0; !flag && i + 1 < n; i++) {
        if(s[i] != s[i+1]) {
            printf("%d %d\n", i + 1, i + 2);
            flag = 1;
        }
    }
    if(!flag) puts("-1 -1");
    
    if(--t) goto st;
    return 0;
}