#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

void solve(bool __attribute__((unused)) read) {
    int n, U;
    cin >> n >> U;
    
    vector<int> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    
    ld mx = -1;
    
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && e[r] - e[l] <= U) ++r;
        
        int R = r - 1;
        if (R == l || R == l + 1) continue;
        
        ld can = (e[R] - e[l + 1]) / (ld)(e[R] - e[l]);
        mx = max(mx, can);
    }
    
    if (mx < 0)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(12) << mx << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}