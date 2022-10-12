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

multiset<array<ll, 3>> s;

ll cost(ll a, ll k) {
    ll f = a/k;
    ll c = a-f*k;
    return (f+1)*(f+1)*c + f*f*(k-c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k; k -= n;
    vector<ll> b(n); for (auto& x : b) cin >> x;
    for (auto& a : b) {
        s.insert({cost(a, 2)-cost(a, 1), a, 1});
    }
    while (k--) {
        auto it = s.begin();
        auto [_, a, i] = *it;
        s.erase(it);
        s.insert({cost(a, i+2)-cost(a, i+1), a, i+1});
        debug(s);
    }
    ll ans = 0;
    for (auto& [_, a, i] : s)
        ans += cost(a, i);
    cout << ans << "\n";
}