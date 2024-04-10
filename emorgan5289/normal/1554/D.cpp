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
        if (n == 1)
            cout << "a\n";
        else if (n%2 == 0)
            cout << string(n/2, 'a') << 'b' << string(n/2-1, 'a') << "\n";
        else
            cout << string(n/2, 'a') << "bc" << string(n/2-1, 'a') << "\n";
    }
}