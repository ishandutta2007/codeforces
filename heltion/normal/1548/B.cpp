#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> v(n);
        for (LL& x : v) cin >> x;
        vector<LL> d(n);
        for (int i = 1; i < n; i += 1) d[i] = abs(v[i] - v[i - 1]);
        int ans = 0;
        vector<pair<LL, int>> p;
        for (int i = 1; i < n; i += 1) {
            p.push_back({0, i});
            vector<pair<LL, int>> q;
            for (auto [x, y] : p) {
                x = gcd(x, d[i]);
                if (not q.empty() and q.back().first == x) continue;
                q.push_back({x, y});
            }
            p.swap(q);
            if (p[0].first != 1) ans = max(ans, i - p[0].second + 1);
            else if (p.size() > 1) ans = max(ans, i - p[1].second + 1);
        }
        cout << ans + 1 << "\n"; 
    }
    return 0;
}