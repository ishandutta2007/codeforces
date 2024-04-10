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

string rev(string s) {
    reverse(all(s));
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<string> a(n);
        map<string, int> m;
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == rev(a[i]))
                ok = 1;
            if (m[a[i]]) ok = 1;
            m[rev(a[i])] = 1;
            string s = rev(a[i]); s.erase(s.begin());
            m[s] = 1;
        }
        m.clear();
        reverse(all(a));
        for (int i = 0; i < n; i++) {
            reverse(all(a[i]));
            if (m[a[i]]) ok = 1;
            m[rev(a[i])] = 1;
            string s = rev(a[i]); s.erase(s.begin());
            m[s] = 1;
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }

        debug(a);

        cout << "NO\n";
    }
}