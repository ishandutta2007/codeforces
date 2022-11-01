// https://codeforces.com/contest/11/problem/D
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define N 19
ll n, m, dp[1<<N][N], mat[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        mat[a][b] = mat[b][a] = 1;
    }

    for(int i = 0; i < n; i++)
        dp[1<<i][i] = 1;

    ll ans = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        int first = __builtin_ctz(mask), popcnt = __builtin_popcount(mask);
        for(int t1 = mask, last; t1; t1 -= (1<<last)) {
            last = __builtin_ctz(t1);
            for(int t2 = ((1<<n)-1)^mask, next; t2; t2 -= (1<<next)) {
                next = __builtin_ctz(t2);
                if(first > next) continue;
                dp[mask|(1<<next)][next] += dp[mask][last] * mat[last][next];
            }
            if(popcnt >= 3 && mat[last][first]) ans += dp[mask][last];
        }
    }
    ans /= 2;

    printf("%lld\n", ans);
    return 0;
}