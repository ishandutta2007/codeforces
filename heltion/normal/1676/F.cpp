#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        mp[INT_MAX] = 0;
        for (int i = 0, a; i < n; i += 1) {
            cin >> a;
            mp[a] += 1;
        }
        int ansL = -1, ansR = -2, L = -1, R = -2;
        for (auto [x, y] : mp) {
            if (y < k or x != R + 1) {
                if (R - L >= ansR - ansL) {
                    ansL = L;
                    ansR = R;
                }
                if (y >= k)
                    L = R = x;
            }
            else R = x;
        }
        if (ansL > 0) cout << ansL << " " << ansR << "\n";
        else cout << "-1\n";
    }
}