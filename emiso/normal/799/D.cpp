#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll a, b, h, w, n, F[MN];

map<pair<int, pair<ll, ll>>, int> dp;

int solve(int i, ll x, ll y) {
    x = min(x, h); y = min(y, w);
    if (x == h && y == w) return 0;
    if (i == n) return MN;

    auto st = dp.find({i, {x, y}});
    if (st != dp.end()) return st->second;

    if (x == h) return dp[{i, {x, y}}] = solve(i + 1, x, y * F[i]) + 1;
    if (y == w) return dp[{i, {x, y}}] = solve(i + 1, x * F[i], y) + 1;
    return dp[{i, {x, y}}] = min(solve(i + 1, x * F[i], y), solve(i + 1, x, y * F[i])) + 1;
}

int main() {
    scanf("%lld %lld %lld %lld %lld", &h, &w, &a, &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &F[i]);
    }
    sort(F, F + n, greater<ll>());

    ll ans = min(solve(0, a, b), solve(0, b, a));
    printf("%lld\n", ans < MN ? ans : -1);
    return 0;
}