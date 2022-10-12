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

map<array<int, 2>, char> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int e = 0, se = 0;
    while (m--) {
        char t; cin >> t;
        if (t == '+') {
            int x, y; cin >> x >> y;
            char c; cin >> c;
            s[{x, y}] = c;
            if (s.count({y, x})) {
                e++;
                if (s[{y, x}] == c)
                    se++;
            }
        }
        if (t == '-') {
            int x, y; cin >> x >> y;
            if (s.count({y, x})) {
                e--;
                if (s[{y, x}] == s[{x, y}])
                    se--;
            }
            s.erase(s.find({x, y}));
        }
        if (t == '?') {
            int k; cin >> k;
            cout << ((k%2 == 0 && se > 0) || (k%2 == 1 && e > 0) ? "YES" : "NO") << "\n";
        }
    }
}