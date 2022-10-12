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
    int t; cin >> t;
    while (t--) {
        ll n, m, x; cin >> n >> m >> x;
        vector<array<ll, 2>> h(n);
        vector<ll> ans(n);
        for (int i = 0; i < n; i++)
            cin >> h[i][0], h[i][1] = i;
        sort(all(h), greater<>());
        multiset<array<ll, 2>> s;
        for (int i = 0; i < m; i++)
            s.insert({0, i});
        for (auto& [y, i] : h) {
            auto [v, j] = *s.begin();
            s.erase(s.begin());
            s.insert({v+y, j});
            ans[i] = j;
        }
        ll l = (*s.begin())[0];
        ll r = (*--s.end())[0];
        if (r > l+x) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++)
                cout << ans[i]+1 << " \n"[i == n-1];
        }
    }
}