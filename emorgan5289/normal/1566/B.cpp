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
        // vector<ll> p(n+1);
        // for (int i = 0; i < n; i++)
        //     p[i+1] = p[i]+(s[i]-'0');
        while (!s.empty() && s.back() != '0') s.pop_back();
        reverse(all(s));
        while (!s.empty() && s.back() != '0') s.pop_back();
        if (s.empty()) {
            cout << "0\n";
        } else if (*max_element(all(s)) == '0')
            cout << "1\n";
        else
            cout << "2\n";
    }
}