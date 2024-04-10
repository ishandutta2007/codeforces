#include <algorithm>
#include <iostream>
#include <vector>

#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
    int n, _a, _b, _c, _d;
    cin >> n >> _a >> _b >> _c >> _d;
    for (int mask = 0; mask < (1 << 4); ++mask) {
        int a = _a, b = _b, c = _c, d = _d;
        if (mask & (1 << 0))
            --a, --b;
        if (mask & (1 << 1))
            --b, --c;
        if (mask & (1 << 2))
            --c, --d;
        if (mask & (1 << 3))
            --a, --d;
        bool can = true;
        if (a < 0 || b < 0 || c < 0 || d < 0)
            can = false;
        if (a > n - 2 || b > n - 2 || c > n - 2 || d > n - 2)
            can = false;
        if (can) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}