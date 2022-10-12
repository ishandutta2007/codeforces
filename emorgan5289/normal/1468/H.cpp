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
        int n, k, m; cin >> n >> k >> m;
        vector<int> a(n, 1), b(m);
        for (auto& x : b) cin >> x, a[x-1]--;
        bool f = (n-m)%(k-1) == 0;
        debug(n, m, k);
        if (n-m == k-1) {
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (a[i]) j++;
                if (j == k/2) {
                    if (a[i+1]) f = 0;
                    break;
                }
            }
        } else {
            bool v = 0;
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (a[i]) j++;
                if (j >= k/2 && n-m-j >= k/2) {
                    if (!a[i]) v = 1;
                }
            }
            if (!v) f = 0;
        }
        cout << (f ? "YES" : "NO") << "\n";
    }
}