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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        // vector<vector<int> dp(n+1, vector<int>(n+1));
        // for (int len = 0; len <= n; len++) {

        // }
        vector<pair<int, string>> stk = {{1, "1"}};
        for (int i = 0; i < n; i++) {
            pair<int, string> s = stk.back(); stk.pop_back();
            while (s.first != a[i]) {
                s = stk.back(); stk.pop_back();
            }
            // debug(stk, s);
            cout << s.second << "\n";
            string tt = s.second+".1";
            while (!s.second.empty() && s.second.back() != '.')
                s.second.pop_back();
            stk.pb({a[i]+1, s.second+to_string(a[i]+1)});
            stk.pb({1, tt});
        }
    }
}