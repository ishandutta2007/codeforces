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
        ll m, d, w; cin >> m >> d >> w;
        m = min(m, d);
        w = w/__gcd(w, d-1);
        cout << (m/w)*(m/w+1)/2*(m%w)+(m/w-1)*(m/w)/2*(w-m%w) << "\n";
    }
}