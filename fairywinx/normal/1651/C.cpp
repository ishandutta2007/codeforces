#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

long long cost(int val, vector<int> &a) {
    int res = 1e9 + 228;
    auto it = lower_bound(all(a), val);
    if (it != a.end()) {
        res = min(res, abs(*it - val));
    }
    if (it != a.begin()) {
        res = min(res, abs(*prev(it) - val));
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    pair<int, int> tmp2 = {b[0], b.back()};
    pair<int, int> tmp1 = {a[0], a.back()};
    sort(all(b));
    sort(all(a));
    long long ans = 1e18 + 228;
    {
        ans = min(ans, 1ll * abs(tmp1.first - tmp2.first) + abs(tmp1.second - tmp2.second));
        ans = min(ans, 1ll * abs(tmp1.first - tmp2.first) + cost(tmp1.second, b) + cost(tmp2.second, a));
        ans = min(ans, 1ll * abs(tmp1.second - tmp2.second) + cost(tmp1.first, b) + cost(tmp2.first, a));
        ans = min(ans, cost(tmp1.first, b) + cost(tmp2.first, a) + cost(tmp1.second, b) + cost(tmp2.second, a));
    }
    swap(tmp1.first, tmp1.second);
    {
        ans = min(ans, 1ll * abs(tmp1.first - tmp2.first) + abs(tmp1.second - tmp2.second));
        ans = min(ans, 1ll * abs(tmp1.first - tmp2.first) + cost(tmp1.second, b) + cost(tmp2.second, a));
        ans = min(ans, 1ll * abs(tmp1.second - tmp2.second) + cost(tmp1.first, b) + cost(tmp2.first, a));
        ans = min(ans, cost(tmp1.first, b) + cost(tmp2.first, a) + cost(tmp1.second, b) + cost(tmp2.second, a));
    }
    cout << ans << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}