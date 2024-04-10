#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, mx = INT_MIN, ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i += 1)
            for (int j = 0, a; j < m; j += 1) {
                cin >> a;
                if (a > mx) {
                    mx = a;
                    ans = max(i + 1, n - i) * max(j + 1, m - j);
                }
            }
        cout << ans << "\n";
    }
}