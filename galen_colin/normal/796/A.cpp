#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, m, k; cin >> n >> m >> k;
    
    ll best = 1e9;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        if (x != 0 && x <= k) {
            best = min(best, abs(i + 1 - m));
        }
    }
    
    cout << 10 * best << '\n';
}