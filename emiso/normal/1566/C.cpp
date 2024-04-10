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

ll t = 1, n, ans, a[MN], b[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%1lld", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%1lld", &b[i]);
    }
    
    int last = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            ans += 2;
            if(last == 0) ans++;
            last = -1;
        } else if(a[i] == 0) {
            if(last == 0) {
                ans++;
            } else if(last == 1) {
                ans += 2;
                last = -1;
            } else {
                last = 0;
            }
        } else if(a[i] == 1) {
            if(last == 0) {
                ans += 2;
                last = -1;
            } else if(last == 1) {
            } else {
                last = 1;
            }
        }
    }
    if(last == 0) ans++;

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}