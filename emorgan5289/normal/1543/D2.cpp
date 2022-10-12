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
        ll n, k; cin >> n >> k;
        auto mod = [&](ll x) {
            return (x%k+k)%k;
        };
        vector<ll> q(n, 0);
        for (ll i = 1; i < n; i++)
            for (ll r = 1; r <= 2e7+5; r *= k)
                q[i] += r*(mod(i%2 == 0 ? i/r-(i-1)/r : k-i/r+(i-1)/r));
        for (int i = 0; i < n; i++) {
            cout << q[i] << endl;
            int x; cin >> x;
            if (x) break;
        }
    }
}