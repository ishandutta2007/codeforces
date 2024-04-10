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

ll t = 1, n, x, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &x);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    sort(a, a + n);

    int ans = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) continue;
        if(i < x && (n-i-1) < x) ans = 0;
    }
    puts(ans ? "YES" : "NO");
    if(--t) goto st;
    return 0;
}