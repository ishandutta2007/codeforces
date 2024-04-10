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
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> f(100000);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                f[i+j] ^= x;
            }
        cout << (*max_element(all(f)) == 0 ? "Jeel" : "Ashish") << "\n";
    }
}