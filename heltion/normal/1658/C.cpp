#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> c(n);
        for (int& ci : c) cin >> ci;
        if (ranges::count(c, 1) != 1) cout << "NO\n";
        else {
            int i = ranges::find(c, 1) - c.begin();
            rotate(c.begin(), c.begin() + i, c.end());
            ranges::reverse(c.begin(), c.end());
            //for (int ci : c) cout << ci << " "; cout << "\n";
            int ok = 1;
            for (int i = 0; i < n; i += 1) {
                if (c[i] > n - i) ok = 0;
                if (i and c[i - 1] - c[i] > 1) ok = 0;
            }
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}