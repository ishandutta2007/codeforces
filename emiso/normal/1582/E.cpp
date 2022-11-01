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

ll t = 1, n, ans, a[MN], acum[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    acum[0] = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        acum[i] = acum[i-1] + a[i];
    }

    ll k = 0;
    vector<int> dp(n+2, INT_MAX), tmp(n+2, -1);
    while(1) {
        int flag = 0;

        tmp[n+1] = -1;
        for(int i = n; i >= 1; i--) {
            tmp[i] = -1;
            if(i + k <= n) {
                ll sum = acum[i+k] - acum[i-1];
                if(sum < dp[i+k+1]) {
                    flag = 1;
                    tmp[i] = sum;
                }
            }
            tmp[i] = max(tmp[i], tmp[i+1]);
        }

        if(!flag) break;
        k++;
        swap(tmp, dp);
    }
    printf("%lld\n", k);
    if(--t) goto st;
    return 0;
}