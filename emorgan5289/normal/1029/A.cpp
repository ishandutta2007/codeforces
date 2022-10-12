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
    int n, k; cin >> n >> k; k--;
    string s; cin >> s;
    for (int i = n-1; i >= 0; i--)
        if (s.substr(0, i) == s.substr(n-i, i)) {
            while (k--) cout << s.substr(0, n-i);
            cout << s << "\n";
            break;
        }
}