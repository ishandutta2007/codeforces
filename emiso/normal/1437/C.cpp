#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], dp[202][404];

ll solve(int i, int t) {
    if(i == n) return 0;
    if(t > 400) return INT_MAX;
    ll &x = dp[i][t];
    if(x != -1) return x;

    x = min(solve(i, t+1), solve(i+1, t+1) + abs(a[i] - t));
    return x;
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    memset(dp, -1, sizeof dp);

    printf("%lld\n", solve(0, 1));

    if(--t) goto st;
    return 0;
}