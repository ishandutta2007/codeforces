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
        ll n, m; cin >> n >> m;
        vector<array<ll, 3>> a(m);
        set<ll> s;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 3; j++)
                cin >> a[i][j], a[i][j]--;
            s.insert(a[i][1]);
        }
        int x;
        for (int i = 0; i < n; i++)
            if (!s.count(i)) {
                x = i; break;
            }
        for (int i = 0; i < n; i++)
            if (i != x) {
                cout << x+1 << " " << i+1 << "\n";
            }
    }
}