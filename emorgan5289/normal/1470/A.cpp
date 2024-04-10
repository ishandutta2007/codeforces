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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> k(n), c(m);
        for (auto& x : k) cin >> x, x--;
        for (auto& x : c) cin >> x;
        sort(all(k));
        ll ans = 0;
        multiset<ll> s;
        for (auto& x : c) s.insert(x);
        for (auto& i : k) {
            ans += *s.begin();
            s.erase(s.begin());
            s.insert(c[i]);
        }
        cout << ans << "\n";
    }
}