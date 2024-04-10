#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> x, y, b;
        int ans = 0, r = 1;
        for (auto& c : s) {
            if (c == '0') {
                if (y.size() == 0) ans++, x.pb(r++);
                else x.pb(y.back()), y.pop_back();
                b.pb(x.back());
            } else {
                if (x.size() == 0) ans++, y.pb(r++);
                else y.pb(x.back()), x.pop_back();
                b.pb(y.back());
            }
        }
        cout << ans << "\n";
        for (auto& c : b)
            cout << c << " ";
        cout << "\n";
    }
}