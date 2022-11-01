#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a, n, m, l, r, x, p;
ll umb[2020], dp[2002][2002], rain[2020];

ll solve(ll pos, int pu) {
    if(pos >= a) return 0;
    if(dp[pos][pu] != -1) return dp[pos][pu];

    ll x = 2LL * INT_MAX;

    if(pu && (pu != pos)) x = min(x, solve(pos, 0));
    if(pu != pos) x = min(x, solve(pos, pos));

    if(rain[pos]) x = min(x, umb[pu] + solve(pos + 1, pu));
    else x = min(x, (pu ? umb[pu] : 0) + solve(pos + 1, pu));

    return dp[pos][pu] = x;
}

int main() {
    scanf("%d %d %d", &a, &n, &m);
    a++;
    memset(dp, -1, sizeof dp);

    for(int i = 0; i < 2020; i++)
        umb[i] = INT_MAX;

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &l, &r);

        for(int j = l + 1; j <= r; j++)
            rain[j] = 1;
    }

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &p);
        umb[x+1] = min(umb[x+1], 0LL + p);
    }

    ll ans = solve(0, 0);
    if(ans >= INT_MAX) printf("-1\n");
    else printf("%lld\n", ans);

    return 0;
}