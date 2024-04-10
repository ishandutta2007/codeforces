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
char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %s", &n, s); str = s;

    ans = INT_MAX;
    for(char c = 'a'; c <= 'z'; c++) {
        ll ok = 1, del = 0;
        for(int i = 0, j = n-1; ok && i < j;) {
            if(str[i] == str[j]) {
                i++; j--;
            } else if(str[i] == c) {
                i++;
                del++;
            } else if(str[j] == c) {
                j--;
                del++;
            } else ok = 0;
        }
        if(ok) ans = min(ans, del);
    }

    printf("%lld\n", ans == INT_MAX ? -1 : ans);
    if(--t) goto st;
    return 0;
}