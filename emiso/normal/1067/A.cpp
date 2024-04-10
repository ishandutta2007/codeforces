#include <bits/stdc++.h>

#define MN 100100
#define MOD 998244353

using namespace std;
typedef long long ll;

int dp[MN][202][2][2], n, a[MN], co;

int solve(int pos, int last, int maxi, int up) {
    if(last <= 0 && pos > 0) return 0;
    if(pos > 0 && a[pos-1] != -1 && a[pos-1] != last) return 0;
    if(pos == n) return (maxi | up) * ((a[n-1]==-1) ? last : 1);

    int x = dp[pos][last][maxi][up];
    if(x != -1) return x;

    if(a[pos] != -1) {
        if(last > a[pos] && up) x = solve(pos + 1, a[pos], 1, 0);
        else if(last > a[pos]) x = solve(pos + 1, a[pos], maxi, 0);
        else x = solve(pos + 1, a[pos], maxi, last < a[pos]);
        return dp[pos][last][maxi][up] = (x + solve(pos, last - 1, maxi, up)) % MOD;
    }
    x = solve(pos, last - 1, maxi, up);
    if(up) {
        x += solve(pos + 1, last - 1, 1, 0);
        if(x >= MOD) x -= MOD;

        x += solve(pos + 1, last, maxi, 0);
        if(x >= MOD) x -= MOD;

        x -= solve(pos + 1, last-1, maxi, 0);
        if(x < 0) x += MOD;

        x += solve(pos + 1, 200, maxi, 1);
        if(x >= MOD) x -= MOD;

        x -= solve(pos + 1, last, maxi, 1);
        if(x < 0) x += MOD;
    } else {
        x += solve(pos + 1, last, maxi, 0);
        if(x >= MOD) x -= MOD;

        x += solve(pos + 1, 200, maxi, 1);
        if(x >= MOD) x -= MOD;

        x -= solve(pos + 1, last, maxi, 1);
        if(x < 0) x += MOD;
    }
    return dp[pos][last][maxi][up] = x;
}

ll expo(ll a, ll b) {
    if(!b) return 1;
    a %= MOD;
    if(b & 1) return a * expo(a * a, b >> 1) % MOD;
    return expo(a * a, b >> 1);
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == -1) co++;
    }

    ll ans = (expo(200, co) - solve(0, 0, 0, 1) + MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}