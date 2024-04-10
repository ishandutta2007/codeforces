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
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ll ans = 0;
        for (int i = 0; i < n-1; i++)
            ans += abs(a[i+1]-a[i]);
        ans += max(0ll, min({2*(x-*max_element(all(a))), x-a.back(), x-a[0]}));
        ans += max(0ll, min({2*(*min_element(all(a))-1), a.back()-1, a[0]-1}));
        cout << ans << "\n";
    }
}