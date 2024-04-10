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

const int N = 2e5+5;
ll a[N];

int dfs(ll l, ll r, ll k, ll mask) {
    debug(l, r, k, mask, vector(a+l, a+r));
    if (r-l <= 2) return 0;
    ll m = lower_bound(a+l, a+r, mask+(1ll<<k))-a;
    ll ans = inf;
    ans = min(ans, dfs(m, r, k-1, mask+(1ll<<k))+max(0ll, m-l-1));
    ans = min(ans, dfs(l, m, k-1, mask)+max(0ll, r-m-1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    cout << dfs(0, n, 31, 0) << "\n";
}