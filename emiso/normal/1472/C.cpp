#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], dp[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    ans = 0;
    for(int i = n-1; i >= 0; i--) {
        dp[i] = a[i];
        if(i + a[i] < n) dp[i] += dp[i+a[i]];

        ans = max(ans, dp[i]);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}