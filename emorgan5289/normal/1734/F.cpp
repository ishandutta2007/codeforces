#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

map<array<ll, 2>, ll> memo;

ll solve_symmetric(ll m, ll w) {
    debug(m, w);
    if (m == w || m == 0)
        return 0;
    if (m <= w/2)
        return m - solve_symmetric(m, w/2);
    if (memo.count({m, w}))
        return memo[{m, w}];
    return memo[{m, w}] = 2*solve_symmetric(m-w/2, w/2) + w-m - solve_symmetric(w-m, w/2);
}

ll solve(ll n, ll m, ll w) {
    debug(n, m, w);
    if (n == 0 || m == 0 || w == 1)
        return 0;
    if (n+m <= w/2)
        return solve(n, m, w/2);
    if (n >= w/2)
        return m-solve(n-w/2, m, w/2);
    return solve_symmetric(w/2-n, w/2) + m+n-w/2 - solve(w/2-n, m+n-w/2, w);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        cout << solve(n, m, 1ll<<61) << "\n";
    }
}