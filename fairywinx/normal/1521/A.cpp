#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << "NO\n";
        return;
    }
    if (b == 2) {
        cout << "YES\n";
        cout << a << ' ' << 2 * a << ' ' << 3 * a << '\n';
        return;
    }
    cout << "YES\n";
    cout << a * (b - 1) << ' ' << a << ' ' << a * b << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << 1 << '\n';
}