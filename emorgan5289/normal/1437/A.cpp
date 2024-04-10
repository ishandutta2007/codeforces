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
        ll l, r; cin >> l >> r;
        int x = r+1;
        debug(l, r, x);
        cout << (r/x == l/x && (l%x >= (x+1)/2) ? "YES" : "NO") << "\n";
    }
}