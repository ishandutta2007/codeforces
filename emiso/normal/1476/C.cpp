#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], b[MN], c[MN], dp[MN];
//char s[MN]; string str;

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &c[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
    }

    dp[0] = INT_MIN;
    ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] == b[i]) {
            dp[i] = 1;
        } else {
            dp[i] = max(abs(a[i] - b[i]) + 1, min(a[i], b[i]) + c[i-1] - max(a[i], b[i]) + 1 + dp[i-1]);
        }
        ans = max(ans, dp[i] + c[i]);
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}