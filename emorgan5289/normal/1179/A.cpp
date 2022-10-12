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
    int n, q; cin >> n >> q;
    deque<ll> a;
    ll max_x = 0;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        cmax(max_x, x);
        a.push_back(x);
    }
    vector<array<ll, 2>> ans;
    while (a.front() != max_x) {
        ll x = a.front(); a.pop_front();
        ll y = a.front(); a.pop_front();
        ans.pb({x, y});
        if (x > y) swap(x, y);
        a.push_back(x);
        a.push_front(y);
    }
    debug(a);
    debug(ans);
    while (q--) {
        ll m; cin >> m; m--;
        if (m < ans.size())
            cout << ans[m][0] << " " << ans[m][1] << "\n";
        else {
            cout << a.front() << " " << a[1+(m-ans.size())%(n-1)] << "\n";
        }
    }
}