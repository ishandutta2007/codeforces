#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll x;
    cin >> x;

    for (ll a = 1; a * a * a <= x; a++) {
        double b = cbrtl(x - a * a * a);
        if (b == ll(b) && b > 0) {
            return void(cout << "YES\n");
        }
    }

    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}