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
        string a, b; cin >> a >> b;
        ll ans = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) swap(a[i], b[i]);
            if (a[i] == '0' && b[i] == '1')
                ans += 2;
            else if (a[i] == '0') ans++;
            else if (a[i] == '1') {
                if (i > 0 && !vis[i-1] && a[i-1] == '0' && b[i-1] == '0')
                    ans++, vis[i-1] = 1;
                else if (i < n-1 && !vis[i+1] && a[i+1] == '0' && b[i+1] == '0')
                    ans++, vis[i+1] = 1;
            }
        }
        cout << ans << "\n";
        // debug(a);
        // debug(b);
    }
}