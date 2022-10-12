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

vector<array<ll, 3>> a, b;
set<ll> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, h, m, k; cin >> n >> h >> m >> k;
    for (int i = 0; i < n; i++) {
        ll x, y; cin >> x >> y; y %= m/2;
        a.pb({y, min(m/2+1, y+k), i});
        if (y+k > m/2) a.pb({-1, y+k-m/2, i});
    }
    for (auto& [u, v, i] : a)
        b.pb({u, 1, i}), b.pb({v, 0, i});
    sort(all(b));
    ll ans = inf;
    vector<int> out;
    int j = 0, r = 0, st = 0;
    for (auto& [u, t, i] : b) {
        if (t) {
            if (u >= 0 && u <= m/2 && (ll)s.size() < ans)
                ans = s.size(), r = j, st = u;
            s.insert(i);
        }
        else {
            s.erase(i);
            if (u >= 0 && u <= m/2 && (ll)s.size() < ans)
                ans = s.size(), r = j, st = u;
        }
        j++;
    }
    j = 0;
    for (auto& [u, t, i] : b) {
        if (t) {
            if (j == r)
                for (auto& x : s) out.pb(x);
            s.insert(i);
        }
        else {
            s.erase(i);
            if (j == r)
                for (auto& x : s) out.pb(x);
        }
        j++;
    }
    cout << ans << " " << st << "\n";
    for (auto& x : out) cout << x+1 << " ";
    cout << "\n";
}