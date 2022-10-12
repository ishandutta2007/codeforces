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
        vector<string> a(n), b(n-1);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n-1; i++)
            cin >> b[i];
        for (int j = 0; j < m; j++) {
            map<char, ll> f;
            for (int i = 0; i < n; i++)
                f[a[i][j]]++;
            for (int i = 0; i < n-1; i++)
                f[b[i][j]]--;
            for (auto& [c, x] : f)
                if (x) cout << c;
        }
        cout << "\n";
    }
}