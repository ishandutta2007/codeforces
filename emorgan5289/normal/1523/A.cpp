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
        int n, m; cin >> n >> m;
        string s; cin >> s;
        int i = 0;
        for (int j = 0; j <= n; j++)
            if (j == n || s[j] == '1') {
                if (i != j) {
                    debug(i, j);
                    for (int k = 0; k < min(i == 0 || j == n ? j-i : (j-i)/2, m); k++) {
                        if (i != 0) s[i+k] = '1';
                        if (j != n) s[j-1-k] = '1';
                        // s[i+k] = s[j-1-k] = '1';
                    }
                }
                i = j+1;
            }
        cout << s << "\n";
    }
}