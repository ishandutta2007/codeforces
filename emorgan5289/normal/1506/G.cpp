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
        string s; cin >> s;
        int n = s.size();
        vector<bool> v(26, 0), u(26, 0), ok(n, 0);
        for (int i = n-1; i >= 0; i--) {
            ok[i] = v[s[i]-'a'];
            v[s[i]-'a'] = 1;
        }
        string r;
        int p = -1;
        for (int i = 0; i < n; i++) {
            if ((p == -1 || s[i] > s[p]) && !u[s[i]-'a']) p = i;
            if (!ok[i] && !u[s[i]-'a']) {
                u[s[p]-'a'] = 1;
                r += s[p];
                i = p, p = -1;
            }
        }
        cout << r << "\n";
    }
}