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

ll t, n, ans, a[MN];
char s[MN]; string str, srt;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s); str = s;
    srt = str;
    sort(srt.begin(), srt.end());

    for(int i = 0; i < n; i++) {
        ans += (str[i] != srt[i]);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}