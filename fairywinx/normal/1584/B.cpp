#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    cout << (n * m + 2) / 3 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    SOLVE;
}