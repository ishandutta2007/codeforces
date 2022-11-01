#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], dp[110][110][110][2], od, ev;

ll solve(int pos, int od, int ev, int last) {
    if(od < 0 || ev < 0) return 9999999LL;
    if(pos == n) return 0;

    ll &x = dp[pos][od][ev][last];
    if(x != -1) return x;

    if(a[pos] != 0) x = solve(pos + 1, od, ev, a[pos] % 2) + ((a[pos] % 2) != last);
    else x = min(solve(pos + 1, od - 1, ev, 1) + (last == 0), solve(pos + 1, od, ev - 1, 0) + (last == 1));

    return x;
}

int main() {
    scanf("%lld", &n);
    memset(dp, -1, sizeof dp);
    od = (n + 1) / 2;
    ev = n / 2;

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if(a[i]) {
            if(a[i] % 2) od--;
            else ev--;
        }
    }

    if(n == 1) puts("0");
    else {
        if(a[0] == 0) {
            printf("%lld\n", min(solve(1, od - 1, ev, 1), solve(1, od, ev - 1, 0)));
        } else printf("%lld\n", solve(1, od, ev, a[0] % 2));
    }
    return 0;
}