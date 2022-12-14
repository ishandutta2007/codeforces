#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    ll a, b;
    cin >> a >> b;
    if (b == 1) cout << "nO\n";
    else {
        cout << "yEs\n";
        cout << a << ' ' << a * (b * 2 - 1) << ' ' << a * b * 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}