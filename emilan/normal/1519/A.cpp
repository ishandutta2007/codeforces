#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void solve() {
    int x, y, d;
    cin >> x >> y >> d;
    if (x < y) swap(x, y);

    if ((x + y - 1) / y - 1 > d) cout << "NO";
    else cout << "YES";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}