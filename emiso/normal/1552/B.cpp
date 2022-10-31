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

ll t, n, ans, a[MN][6];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++)
            scanf("%lld", &a[i][j]);
    }

    ll cur = 0;
    for(int i = 1; i < n; i++) {
        int cnt = 0;
        for(int j = 0; j < 5; j++) {
            cnt += (a[i][j] < a[cur][j]);
        }
        if(cnt >= 3) cur = i;
    }

    for(int i = 0; cur != -2 && i < n; i++) {
        if(i == cur) continue;
        int cnt = 0;
        for(int j = 0; j < 5; j++) {
            cnt += (a[i][j] < a[cur][j]);
        }
        if(cnt >= 3) cur = -2;
    }

    printf("%lld\n", cur + 1);
    if(--t) goto st;
    return 0;
}