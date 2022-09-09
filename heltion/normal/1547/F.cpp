#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, d = 0;
        cin >> n;
        vector<int> v(n * 2);
        for (int i = 0; i < n; i += 1) {
            cin >> v[i];
            v[i + n] = v[i];
            d = gcd(d, v[i]);
        }
        int ans = 0;
        vector<pair<int, int>> vp;
        for (int i = 2 * n - 1; i >= 0; i -= 1) {
            vector<pair<int, int>> wp;
            vp.push_back({0, i});
            for (auto [x, y] : vp) {
                x = gcd(x, v[i]);
                if (not wp.empty() and x == wp.back().first) wp.back().second = y;
                else wp.push_back({x, y});
            }
            swap(vp, wp);
            if (i < n)
                ans = max(ans, vp[0].second - i);
        }
        cout << ans << "\n";
    }
    return 0;
}