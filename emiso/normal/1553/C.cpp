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
char s[MN]; string str, tmp;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%s", &s); str = s; n = str.size();
    tmp = str;

    ans = 10;
    for(int mask = 0; mask < (1 << 10); mask++) {
        for(int i = 0; i < n; i++) {
            tmp[i] = (str[i] == '?') ? (mask & (1 << i)) ? '1' : '0' : str[i];
        }
        ll stop = 10;
        for(int i = 0, c1 = 0, c2 = 0; i < n; i++) {
            if(i % 2 == 0) {
                if(tmp[i] == '1') c1++;
                int rem = 4 - i/2;
                if(c1 + rem < c2 || c2 + rem + 1 < c1) {
                    stop = i + 1;
                    break;
                }
            } else {
                if(tmp[i] == '1') c2++;
                int rem = 4 - i/2;
                if(c1 + rem < c2 || c2 + rem < c1) {
                    stop = i + 1;
                    break;
                }
            }
        }
        ans = min(ans, stop);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}