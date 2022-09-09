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
    vector<LL> L(n), R(n);
    for (int i = 0; i < n; i += 1)
        cin >> L[i] >> R[i];
    vector<int> ans(30);
    for (int i = 0; i < 30; i += 1) {
        vector<pair<LL, int>> mp;
        LL k = 1 << i;
        for (int j = 0; j < n; j += 1) {
            LL l = L[j] - (L[j] - 1) / k * k;
            LL r = l + R[j] - L[j];
            if (r - l + 1 >= k) mp.emplace_back(l, 1);
            else {
                mp.emplace_back(l, 1);
                mp.emplace_back(r + 1, -1);
                mp.emplace_back(l + k, 1);
                mp.emplace_back(r + k + 1, -1);
            }
        }
        ranges::sort(mp);
        int sum = 0;
        for (auto [x, y] : mp)
            ans[i] = max(ans[i], sum += y);
    }
    int q;
    cin >> q;
    for (int qi = 0, w; qi < q; qi += 1) {
        cin >> w;
        cout << ans[__builtin_ctz(w)] << "\n";
    }
}