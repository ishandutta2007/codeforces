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
        int n; cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<array<int, 3>> ans;
        for (int i = 0; i < n; i += 2) {
            int j = i+1;
            ans.pb({1, i, j});
            ans.pb({2, i, j});
            ans.pb({1, i, j});
            ans.pb({1, i, j});
            ans.pb({2, i, j});
            ans.pb({1, i, j});
        }
        cout << ans.size() << "\n";
        for (auto& [x, y, z] : ans)
            cout << x << " " << y+1 << " " << z+1 << "\n";
    }
}