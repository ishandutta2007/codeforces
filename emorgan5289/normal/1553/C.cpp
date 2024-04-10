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
        string s; cin >> s;
        ll x = 0, y = 0;
        bool ok = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] == '1') {
                if (i%2) y++, x--;
                else x++, y--;
            }
            if (s[i] == '?') {
                if (i%2) y++;
                else x++;
            }
            if (x-(10-i)/2 > 0) {
                cout << i+1 << "\n";
                ok = 1;
                break;
            }
            if (y-(9-i)/2 > 0) {
                cout << i+1 << "\n";
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "10\n";
        }
    }
}