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
        string a, b; cin >> a >> b;
        int g = __gcd(a.size(), b.size());
        string x = a.substr(0, g);
        bool v = 1;
        for (int i = 0; i < a.size(); i += g)
            v = v && a.substr(i, g) == x;
        for (int i = 0; i < b.size(); i += g)
            v = v && b.substr(i, g) == x;
        string ans = "";
        for (int i = 0; i < a.size()*b.size()/g/g; i++)
            ans += x;
        cout << (v ? ans : "-1") << "\n";
    }
}