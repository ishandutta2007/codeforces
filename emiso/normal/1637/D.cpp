#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1010

ll t = 1, n, ans, a[MN], b[MN], dp[101][10100], tot[101];

ll solve(int i, ll suml) {
    if (i == n) return 0;
    ll &x = dp[i][suml];
    if (x != -1) return x;
    int sumr = (i == 0) ? 0 : tot[i-1] - suml;

    x = min(2*suml*a[i] + 2*sumr*b[i] + solve(i+1, suml + a[i]),
            2*suml*b[i] + 2*sumr*a[i] + solve(i+1, suml + b[i]));

    return x;
}

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        ans += a[i] * a[i] * (n - 1);
    }
    for(int i = 0; i < n; i++) {
        scanf("%lld", &b[i]);
        ans += b[i] * b[i] * (n - 1);
    }

    tot[0] = a[0] + b[0];
    for (int i = 1; i < n; i++)
        tot[i] = tot[i-1] + a[i] + b[i];

    memset(dp, -1, sizeof dp);
    printf("%lld\n", ans + solve(0, 0));
    if(--t) goto st;
    return 0;
}