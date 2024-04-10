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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

map<ll, ll> m;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, p, k; cin >> n >> p >> k;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        m[((((x*x)%p)*((x*x)%p))%p-(k*x)%p+p)%p]++;
    }
    ll ans = 0;
    for (auto& [_, x] : m) ans += x*(x-1)/2;
    cout << ans << "\n";
}