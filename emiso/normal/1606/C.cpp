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

ll t = 1, n, k, ans, a[MN], p10[110];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &k);

    p10[0] = 1;
    for(int i = 1; i <= 9; i++)
        p10[i] = p10[i-1] * 10;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    k++;
    for(int i = 0; i + 1 < n; i++) {
        int quant = p10[a[i+1]] / p10[a[i]];
        if (k >= quant - 1) {
            k -= (quant - 1);
            ans += (quant - 1) * p10[a[i]];
        } else {
            ans += k * p10[a[i]];
            k = 0;
        }
    }
    ans += k * p10[a[n-1]];

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}