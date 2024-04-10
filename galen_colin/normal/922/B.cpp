#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i; j <= n; j++) {
            ll k = i ^ j;
            if (k >= j && i + j > k && k <= n) ++ans;
        }
    }
    
    cout << ans << '\n';
}