#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; cin >> n;
    vector<tuple<ll, ll, ll>> a(2*n);
    for (int i = 0; i < n; i++) {
        ll x, y, t; cin >> x >> y >> t;
        a[2*i] = {x+t, t, 0}; a[2*i+1] = {y, t, x};
    }
    sort(all(a));
    multiset<ll> s;
    ll px = -inf_ll, out = 0;
    for (auto& [x, t, b] : a) {
        debug(s, px, x);
        if (!s.empty()) {
            ll m = (x-px)/(*s.begin());
            out += m; px += m*(*s.begin());
        }
        debug(out);
        if (b) {
            s.erase(s.find(t));
        } else {
            px = max(px, x-t);
            s.insert(t);
        }
    }
    cout << out << "\n";
}