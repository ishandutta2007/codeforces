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
        int n; cin >> n;
        string s; cin >> s;
        string a = "", b = "";
        int c1 = 0;
        for (char c : s) if (c == '1') c1++;
        if (c1&1) {
            cout << "NO\n"; continue;
        }
        c1 /= 2;
        int da = 0, db = 0;
        bool ok = 1;
        for (char c : s) {
            if (c == '1') {
                if (c1) c1--, a += '(', b += '(', da++, db++;
                else a += ')', b += ')', da--, db--;
            } else {
                if (da > db) {
                    da--, a += '(', db++, b += ')';
                } else {
                    da++, a += ')', db--, b += '(';
                }
            }
            if (da < 0 || db < 0) ok = 0;
        }
        if (!ok) {
            cout << "NO\n"; continue;
        }
        cout << "YES\n" << a <<"\n"<< b << "\n";
    }
}