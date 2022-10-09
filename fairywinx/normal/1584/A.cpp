#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << -1ll * a * a << ' ' << 1ll * b * b << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE;
}