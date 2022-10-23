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
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& ai : a) cin >> ai;
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i += 1)
            vp.emplace_back(a[i] - i, i);
        ranges::sort(vp);
        set<int> s = {n};
        LL ans = 0;
        for (int i = n - 1, j = 0; i >= 0; i -= 1) {
            while (j < n and vp[j].first <= -i)
                s.insert(vp[j ++].second);
            ans += *s.lower_bound(i) - i;
        }
        cout << ans << "\n";
    }
}