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
    scanf("%s", s); str = s;

    int f[] = {0, 0};
    for(int i = 0; i < str.size(); i++) {
        a[i] = (str[i] == '1');
        f[a[i]]++;
    }

    if(f[0] == 0) ans = 0;
    else if(f[1] == 0) ans = 1;
    else {
        int isl = 0;
        for(int i = 0; i < str.size(); i++) {
            if(a[i] == 0 && (i == 0 || a[i-1] != 0)) isl++;
        }
        ans = 2 - (isl == 1);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}