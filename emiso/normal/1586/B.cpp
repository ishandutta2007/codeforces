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

ll t = 1, n, m, ans, a[MN], f[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 0, x, y, z; i < m; i++) {
        scanf("%d %d %d", &x, &y, &z);
        a[i] = y;
        f[y] = 1;
    }

    int notg = -1;
    for(int i = 1; i <= n; i++)
        if(!f[i]) notg = i;

    for(int i = 1; i <= n; i++)
        if(i != notg)
            printf("%d %d\n", i, notg);

    for(int i = 0; i < m; i++)
        f[a[i]] = 0;

    if(--t) goto st;
    return 0;
}