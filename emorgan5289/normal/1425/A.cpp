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

ll f(ll x) {
    if (x == 0) return 0;
    return x-(x%2 == 1 || x%4 == 0 && x >= 12 ? f(x-1) : f(x/2));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << f(n) << "\n";
    }
}