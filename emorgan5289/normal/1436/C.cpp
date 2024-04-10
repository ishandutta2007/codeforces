#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll mod = 1e9+7;

// using mod = modint<int(1e9+7)>;
ll n, x, p, t = 0;

ll dfs(ll l, ll r, ll k1, ll k2) {
    debug(l, r, k1, k2);
    if (l >= r) return 1;
    t++;
    ll m = (l+r)/2;
    if (p == m) {
        return dfs(m+1, r, k1+1, k2);
    } else if (p >= m) {
        return (x-1-k1)*dfs(m+1, r, k1+1, k2)%mod;
    } else {
        return (n-x-k2)*dfs(l, m, k1, k2+1)%mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> x >> p;
    ll f = dfs(0, n, 0, 0);
    debug(f);
    for (ll i = 2; i <= n-t; i++)
        f = (f*i)%mod;
    cout << f << "\n";
}