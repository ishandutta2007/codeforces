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

ll t = 1, n, ans, a[MN], dp[10][2][2];
char s[MN]; string str;

ll solve(int i, int c1, int c2) {
    if(i < 0) return (c1 == 0 && c2 == 0);
    ll &x = dp[i][c1][c2];
    if(x != -1) return x;
    x = 0;

    int tgt = str[i] - '0';
    for(int d1 = 0; d1 <= 9; d1++)
        for(int d2 = 0; d2 <= 9; d2++)
            if((d1 + d2 + c1) % 10 == tgt)
                x += solve(i - 1, c2, (d1 + d2 + c1) > 9);
    return x;
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%s", s); str = s;

    memset(dp, -1, sizeof dp);
    printf("%lld\n", solve((int)str.size()-1, 0, 0) - 2);
    if(--t) goto st;
    return 0;
}