#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    int t; cin >> t;
    for (int z = 0; z < t; ++z) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0;
        map<int, int> mp;
        for (int i = 0; i < n - 2 * k; ++i)
            ans += v[i];
        int mx = 0;
        for (int i = n - 2 * k; i < n; ++i)
            mx = max(mx, ++mp[v[i]]);
        ans += max(0, mx - k);
        cout << ans << '\n';
    }
}