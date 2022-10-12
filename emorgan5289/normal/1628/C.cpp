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
        ll ans = 0;
        vector<vector<ll>> a(n, vector<ll>(n));
        vector<vector<int>> c(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        debug();
        for (auto& row : a) debug(row);
        debug();
        auto op = [&](int i, int j) {
            ans ^= a[i][j];
            if (i+1 < n) c[i+1][j] ^= 1;
            if (i-1 >= 0) c[i-1][j] ^= 1;
            if (j+1 < n) c[i][j+1] ^= 1;
            if (j-1 >= 0) c[i][j-1] ^= 1;
        };
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!c[i-1][j]) op(i, j);
        // for (int k = 1; k < n/2; k++) {
        //     for (int i = k; i < n-k; i++) {
        //         if (c[k-1][i]) op(k, i);
        //         if (c[n-k][i]) op(n-k-1, i);
        //     }
        //     for (int i = k; i < n-k; i++) {
        //         if (c[i][k-1]) op(i, k);
        //         if (c[i][n-k]) op(i, n-k-1);
        //     }
        // }
        for (auto& row : c) debug(row);
        cout << ans << "\n";
    }
}