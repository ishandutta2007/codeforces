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
        if (*max_element(all(s)) == '?')
            s[0] = 'R';
        for (int i = 1; i < n; i++)
            if (s[i] == '?' && s[i-1] != '?') s[i] = s[i-1]^'R'^'B';
        for (int i = n-2; i >= 0; i--)
            if (s[i] == '?' && s[i+1] != '?') s[i] = s[i+1]^'R'^'B';
        cout << s << "\n";
    }
}