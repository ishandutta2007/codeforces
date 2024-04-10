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

#define MN 8001000

ll t = 1, n, dp[MN], MOD, sum, acum[MN], tmp;
//char s[MN]; string str;

int main() {
    scanf("%lld %lld", &n, &MOD);

    sum = 1;
    for(ll i = 1; i <= n; i++) {
        tmp += acum[i];
        if(tmp >= MOD) tmp -= MOD;

        dp[i] = sum + tmp;
        if(dp[i] >= MOD) dp[i] -= MOD;

        for(ll j = 2; i * j <= n; j++) {
            acum[i*j] += dp[i];
            if(acum[i*j] >= MOD) acum[i*j] -= MOD;
            
            acum[i*j+j] -= dp[i];
            if(acum[i*j+j] < 0) acum[i*j+j] += MOD;
        }

        if(i > 1) sum += dp[i];
        if(sum >= MOD) sum -= MOD;
    }

    printf("%lld\n", dp[n]);
    return 0;
}