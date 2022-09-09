#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i += 1)
            vp.emplace_back(i ? a[i] - a[i - 1] - 1 : a[i] - 1, i);
        ranges::sort(vp);
        int ans = vp[0].first;
        auto f = [&](int i) {
            vector<int> v;
            for (int j = 0; j < n; j += 1) if (j != i) v.push_back(a[j]);
            vector<int> u;
            for (int j = 0; j < n - 1; j += 1) u.push_back(j ? v[j] - v[j - 1] - 1 : v[j] - 1);
            ranges::sort(u);
            int res = min(u[0], d - v.back() - 1);
            res = max(res, min(u[0], (u.back() - 1) / 2));
            return res;
        };
        ans = max(ans, f(vp[0].second));
        if (vp[0].second) ans = max(ans, f(vp[0].second - 1));
        if (vp[0].second + 1 < n) ans = max(ans, f(vp[0].second + 1));
        cout << ans << "\n";
    }
    return 0;
}