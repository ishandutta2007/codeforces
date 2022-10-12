#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9;
const ll inf_ll = 1e18;
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
        int a = 0, b = 0, ans = 0;
        string s; cin >> s;
        debug(s);
        for (auto& x : s) {
            if (x == '(') a++;
            if (x == '[') b++;
            if (x == ')' && a > 0) a--, ans++;
            if (x == ']' && b > 0) b--, ans++;
        }
        cout << ans << "\n";
    }
}