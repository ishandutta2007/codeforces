#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r) {
    LL res = 1;
    for (; r; r >>= 1, a = a * a % mod)
        if (r & 1) res = res * a % mod;
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<LL> a(n);
    for (LL& ai : a) cin >> ai;
    partial_sum(a.begin(), a.end(), a.begin());
    if (ranges::min(a) < 0 or ranges::max(a) > a.back()) {
        cout << -1;
        return 0;
    }
    vector<pair<LL, int>> vp;
    for (int i = 0; i < n; i += 1) {
        vp.emplace_back(a[i], i);
    }
    ranges::sort(vp.begin(), vp.end());
    vector<int> bit(n);
    auto add = [&](int x) {
        for (x += 1; x <= n; x += x & -x)
            bit[x - 1] += 1;
    };
    auto sum = [&](int x) {
        int y = 0;
        for (x += 1; x; x -= x & -x)
            y += bit[x - 1];
        return y;
    };
    LL ans = 0;
    for (auto [_, i] : vp) {
        ans += i - sum(i);
        add(i);
    }
    cout << ans;
}