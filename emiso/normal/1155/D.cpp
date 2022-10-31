#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, x, a[300030], dp[300030][4];

ll solve(int pos, int seg) {
    if(pos == n || seg == 3) return 0;

    ll &v = dp[pos][seg];
    if(v != -1) return v;
    v = solve(pos, seg + 1);

    if(seg == 1) v = max(v, a[pos] * x + solve(pos + 1, seg));
    else v = max(v, a[pos] + solve(pos + 1, seg));

    return v;
}

int main() {
    scanf("%lld %lld", &n, &x);
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < n; i++)
        scanf("%lld", &a[i]);

    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, solve(i, 0));

    printf("%lld\n", ans);
    return 0;
}