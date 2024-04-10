#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, r1, r2, r3, d, n, a[MN];
ll dp[MN][3][3][3];

ll solve(int i, int pre, int now, int nxt) {
    if(i < 0) return LLONG_MAX;
    if(i == n && pre == 2) return 0;
    if((i == n - 1 && now == 2 && pre == 2)) return 0;
    if((i == n - 2 && now == 2 && nxt == 2 && pre == 2)) return 0;

    ll &x = dp[i][pre][now][nxt];
    if(x != -1) return x;
    x = LLONG_MAX;

    if(now == 2) { /// dead
        if(pre != 2 || (i == n - 1)) x = min(x, solve(i - 1, 2, pre, 2) + d);
        else x = min(x, solve(i + 1, 2, nxt, 0) + d);
    }
    if(now == 1) { /// damaged
        if(pre != 2 || (i == n - 1)) x = min(x, solve(i - 1, 2, pre, 2) + r1 + d);
        else x = min(x, solve(i + 1, 2, nxt, 0) + r1 + d);
    }
    if(now == 0) { /// full
        if(pre != 2 || (i == n - 1)) {
            x = min(x, a[i] * r1 + r1 + solve(i - 1, 2, pre, 1) + d);
            x = min(x, a[i] * r1 + r3 + solve(i - 1, 2, pre, 2) + d);
            x = min(x, r2 + solve(i - 1, 2, pre, 1) + d);
        }
        else {
            x = min(x, a[i] * r1 + r1 + solve(i + 1, 1, nxt, 0) + d);
            x = min(x, a[i] * r1 + r3 + solve(i + 1, 2, nxt, 0) + d);
            x = min(x, r2 + solve(i + 1, 1, nxt, 0) + d);
        }
    }

    return x;
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%lld %lld %lld %lld %lld", &n, &r1, &r2, &r3, &d);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    printf("%lld\n", solve(0, 2, 0, 0) - d);
    return 0;
}