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
        string s; cin >> s;
        vector<int> p(n), v(n);
        for (int i = 0; i < n; i++)
            cin >> p[i], p[i]--;
        vector<string> c;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                c.pb("");
                for (int j = i; !v[j]; j = p[j])
                    v[j] = 1, c.back() += s[j];
            }
        }
        debug(c);
        ll ans = 1;
        for (int i = 0; i < c.size(); i++) {
            for (int j = 1; j <= c[i].size(); j++) {
                if (c[i].size()%j != 0) continue;
                bool ok = 1;
                for (int k = j; k < c[i].size(); k++)
                    if (c[i][k] != c[i][k-j]) ok = 0;
                if (ok) {
                    debug(j);
                    ans = (ans*j) / gcd(ans, j);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}