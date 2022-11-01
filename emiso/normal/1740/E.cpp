#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, p[MN], dp[MN][2];
vector<int> ch[MN];

ll solve(int u, int pomami) {
    ll &x = dp[u][pomami];
    if (x != -1) return x;

    if (!ch[u].empty()) {
        ll maxi = 0, sum = 0;
        x = 0;
        for (int v : ch[u]) {
            maxi = max(maxi, solve(v, false));
            sum += solve(v, true);
        }

        if (pomami == true) {
            x = max(maxi + 1, sum);
        } else {
            x = maxi + 1;
        }
    } else x = 1;

    return x;
}

int main() {
    scanf("%lld", &n);
    for(int i = 2; i <= n; i++) {
        scanf("%lld", &p[i]);
        ch[p[i]].push_back(i);
    }
    memset(dp, -1, sizeof dp);
    printf("%lld\n", max(solve(1, 0), solve(1, 1)));
    return 0;
}