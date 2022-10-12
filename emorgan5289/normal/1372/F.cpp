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

vector<ll> v = {1};
ll c = 0;

map<array<ll, 2>, array<ll, 2>> memo;

// array<ll, 2> qry(ll l, ll r) {
//     debug(l, r);
//     if (memo.count({l, r}))
//         return memo[{l, r}];
//     map<ll, ll> m;
//     for (int i = l; i <= r; i++)
//         m[v[i-1]]++;
//     ll x = 0, f = 0;
//     for (auto& [p, q] : m)
//         if (q > f)
//             x = p, f = q;
//     c++;
//     return memo[{l, r}] = {x, f};
// }

const int N = 2e5+5;
ll a[N];

array<ll, 2> qry(ll l, ll r) {
    if (memo.count({l, r}))
        return memo[{l, r}];
    cout << "? " << l << " " << r << endl;
    ll x, f; cin >> x >> f;
    if (x == -1) exit(0);
    debug(x, f);
    return memo[{l, r}] = {x, f};
}

void solve(ll l, ll r, ll px, ll pf) {
    debug(l, r, px, pf);
    if (l > r) return;
    auto [x, f] = qry(l, r);
    if (f == r-l+1) {
        fill(a+l, a+r+1, x);
        return;
    }
    if (x == px) {
        if (l != 0 && a[l-1] == x) {
            fill(a+l, a+l+f, x);
            solve(l+f, r, -1, -1);
        } else {
            fill(a+r+1-f, a+r+1, x);
            solve(l, r-f, -1, -1);
        }
    } else {
        for (ll i = l; i <= r; i += f)
            solve(i, min(r, i+f-1), x, f);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    // for (int i = 0; i < 1000; i++)
    //     for (int j = 0; j < (50); j++)
    //         v.pb(i+1);
    // n = v.size();
    solve(1, n, -1, -1);
    cout << "!";
    for (int i = 1; i <= n; i++)
        cout << " " << a[i];
    cout << endl;
    // for (int i = 1; i <= n; i++)
    //     assert(a[i] == v[i-1]);
    // debug(c);
}