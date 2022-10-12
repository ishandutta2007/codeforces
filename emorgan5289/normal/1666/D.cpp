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
        set<char> bad;
        string a, b; cin >> a >> b;
        reverse(all(a)), reverse(all(b));
        bool ok = 1;
        int i = 0;
        for (auto& x : a) {
            if (i < b.size() && b[i] == x) {
                i++;
                if (bad.count(x)) ok = 0;
            } else bad.insert(x);
        }
        cout << (ok && i == b.size() ? "YES" : "NO") << "\n";
    }
}