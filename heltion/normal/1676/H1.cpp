#include <bits/stdc++.h>
using namespace std;
using LL = long long;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> bit(n + 1);
        auto add = [&](int x) {
            for (; x <= n; x += x & -x)
                bit[x] += 1;
        };
        auto sum = [&](int x) {
            int y = 0;
            for (; x; x -= x & -x)
                y += bit[x];
            return y;
        };
        LL ans = 0;
        for (int i = 1, a; i <= n; i += 1) {
            cin >> a;
            ans += i - 1 - sum(a - 1);
            add(a);
        }
        cout << ans << "\n";
    }
}