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
        int x = 0;
        while (x < n-1 && s[x] >= s[x+1]) x++;
        debug(x);

        if (n >= 2 && s[0] == s[1])
            cout << s.substr(0, 2) << "\n";
        else {
            // while (x > 0 && s[x] == s[x-1]) x--;
            s = s.substr(0, x+1);
            cout << s;
            reverse(all(s));
            cout << s << "\n";
        }
    }
}