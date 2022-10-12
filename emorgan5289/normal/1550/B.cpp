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
        ll n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        ll c = n;
        for (int i = 0; i < n-1; i++)
            if (s[i] == s[i+1]) c--;
        cout << n*a+(b >= 0 ? b*n : b*(c/2+1)) << "\n";
    }
}