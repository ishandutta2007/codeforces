#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 998244353

ll n, m, M, ans[100010], L[55], R[55], l[55], r[55], dp[55][100010];

ll solve2(int i, int rem) {
    if(rem < 0) return 0;
    if(i == n) return 1;
    ll &x = dp[i][rem];
    if(x != -1) return x;
    x = solve2(i, rem - 1);
    x += solve2(i + 1, rem - l[i]);
    if(x >= MOD) x -= MOD;
    x -= solve2(i + 1, rem - r[i] - 1);
    if(x < 0) x += MOD;
    return x;
}

ll solve(ll k) {
    m = M / k;
    for(int i = 0; i < n; i++) {
        l[i] = (L[i] + k - 1) / k;
        r[i] = R[i] / k;
        for(int j = 0; j <= m; j++) dp[i][j] = -1;
    }
    return solve2(0, m);
}

int main() {
    scanf("%lld %lld", &n, &M);
    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &L[i], &R[i]);
    }
    for(int i = 100000; i >= 1; i--) {
        ans[i] = solve(i);
        for(int j = i + i; j <= 100000; j += i) {
            ans[i] -= ans[j];
            if(ans[i] < 0) ans[i] += MOD;
        }
    }
    printf("%lld\n", ans[1]);
    return 0; 
}