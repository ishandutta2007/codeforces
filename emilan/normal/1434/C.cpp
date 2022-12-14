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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b * c) return void(cout << "-1\n");
    if (d >= c) return void(cout << a << '\n');

    ll n = (a + b * d - 1) / (b * d);
    cout << n * a - n * (n - 1) / 2 * b * d << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}