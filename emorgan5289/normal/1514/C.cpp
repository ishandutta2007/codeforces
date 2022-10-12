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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll x = 1;
    vector<ll> ans;
    for (ll i = 1; i < n; i++)
        if (__gcd(i, n) == 1)
            ans.pb(i), x = (x*i)%n;
    if (x != 1) ans.erase(find(all(ans), x));
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i+1 == ans.size()];
}