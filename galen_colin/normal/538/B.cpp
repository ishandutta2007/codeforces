#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ll n; cin >> n;
    vector<ll> vals;
    
    ll on = n;
    
    vector<ll> dig;
    while (n > 0) {
        dig.push_back(n % 10);
        n /= 10;
    }
    
    while (dig.size()) {
        ll r = 1, c = 0;
        for (ll i = 0; i < dig.size(); i++) {
            if (dig[i] > 0) {
                c += r;
                --dig[i];
            }
            r *= 10;
        }
        vals.push_back(c);
        while (dig.size() && dig.back() <= 0) dig.pop_back();
    }
    
    cout << vals.size() << '\n';
    for (ll x: vals) cout << x << " ";
}