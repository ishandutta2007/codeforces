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
    int n; cin >> n;
    vector<ll> a(n), p(n);
    set<pair<ll, int>, greater<>> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i]+(i == 0 ? 0 : p[i-1]);
        if (i >= 2) s.insert({a[i-2]+p[i-2], i-2});
        for (auto& [x, j] : s) {
            if (x < p[i]-2*a[i]) break;
            if ((a[i]^a[j]) == p[i-1]-p[j])
                ans++;
        }
    }
    cout << ans << "\n";
}