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
        ll n, k; cin >> n >> k;
        while (k > 3) n--, k--, cout << "1 ";
        if (n%2 == 1)
            cout << "1 " << n/2 << " " << n/2 << "\n";
        else if (n%4 == 0)
            cout << n/4 << " " << n/4 << " " << n/2 << "\n";
        else
            cout << "2 " << n/2-1 << " " << n/2-1 << "\n";
    }
}