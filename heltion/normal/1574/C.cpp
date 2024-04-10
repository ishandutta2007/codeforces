#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<LL> v;
    LL sum = 0;
    for (int i = 0; i < n; i += 1) {
        LL a;
        cin >> a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(), v.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i += 1) {
        LL x, y;
        cin >> x >> y;
        auto it = lower_bound(v.begin(), v.end(), x);
        LL ans = LLONG_MAX;
        if (it != v.end())
            ans = max(y - (sum - *it), 0LL);
        if (it != v.begin())
            ans = min(ans, x - *prev(it) + max(y - (sum - *prev(it)), 0LL));
        cout << ans << "\n";
    }
    return 0;
}