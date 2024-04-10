#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n; cin >> n;
    ll a[n], p[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[a[i] - 1] = i;
    }
    
    ll ans = 0;
    for (int i = 1; i < n; i++) ans += abs(p[i] - p[i - 1]);
    cout << ans << '\n';
}