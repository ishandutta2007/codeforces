#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long z = a - 1 + b - 1 + c - 1;
    long long o = max({a, b, c});
    long long sum = a + b + c;
    int mn = o  - (sum - o) - 1;
    if (mn <= d && d <= z) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}