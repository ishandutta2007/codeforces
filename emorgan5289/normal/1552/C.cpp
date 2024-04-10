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

int inter(array<int, 2> a, array<int, 2> b) {
    if (a[0] < b[0] && a[1] > b[1]) return 0;
    if (a[0] > b[0] && a[1] < b[1]) return 0;
    if (a[1] < b[0]) return 0;
    if (a[0] > b[1]) return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<array<int, 2>> a(k);
        vector<int> f(2*n);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 2; j++)
                cin >> a[i][j], a[i][j]--, f[a[i][j]]++;
            sort(all(a[i]));
        }
        debug(a);
        int d = 0;
        vector<int> b;
        for (int i = 0; i < 2*n; i++)
            if (!f[i]) b.pb(i);
        debug(b);
        debug(a);
        debug(d);
        for (int i = 0; i < n-k; i++)
            a.pb({b[i], b[i+n-k]});
        debug(a);
        debug(d);
        for (int i = 0; i < a.size(); i++)
            for (int j = i+1; j < a.size(); j++) {
                if (inter(a[i], a[j])) {
                    debug(i, j);
                    d++;
                }
            }
        cout << d << "\n";
    }
}