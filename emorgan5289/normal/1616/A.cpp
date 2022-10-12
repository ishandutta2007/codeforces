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
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        map<ll, ll> m;
        ll z = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) z = 1;
            else m[abs(a[i])]++;
        }
        ll ans = 0;
        for (auto& [x, y] : m)
            ans += min(2ll, y);
        cout << ans+z << "\n";
    }
}