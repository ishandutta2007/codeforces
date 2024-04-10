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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> a(n); for (auto& x : a) cin >> x;
        ll l = *min_element(all(a));
        ll r = *max_element(all(a));
        if (k&1) {
            for (auto& x : a) cout << r-x << " ";
            cout << "\n";
        } else {
            for (auto& x : a) cout << x-l << " ";
            cout << "\n";
        }
    }
}