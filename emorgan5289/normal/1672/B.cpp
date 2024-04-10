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
        ll n = s.size();
        bool ok = s.back() == 'B' && s[0] == 'A';
        ll c = 0;
        for (auto& x : s) {
            if (x == 'A') c++;
            if (x == 'B') c--;
            if (c < 0) ok = 0;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}