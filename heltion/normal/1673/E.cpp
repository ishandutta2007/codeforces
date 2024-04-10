#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 1'000'000'007;
void add(int& x, int y) {
    if ((x += y) >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> B(n);
    for (int& Bi : B) cin >> Bi;
    vector<int> ans(1 << 20);
    map<pair<int, int>, int> F;
    auto f = [&](int n, int k) {
        if (F.count({n, k})) return F[{n, k}];
        int &res = F[{n, k}];
        for (int i = k; i <= n; i += 1)
            res ^= (n & i) == i;
        return res;
    };
    for (int i = 0; i < n; i += 1)
        for (int j = i; j < i + 20 and j < n; j += 1) {
            LL x = 0;
            for (int k = i + 1; k <= j; k += 1)
                x += B[k];
            if (x >= 20) break;
            x = 1 << x;
            x *= B[i];
            if (x >= (1 << 20)) break;
            int s = (i != 0) + (j + 1 != n);
            if (f(n - 1 - (j - i) - s, k - s)) ans[x] ^= 1;
        }

    int one = 0;
    for (int i = (1 << 20) - 1; i >= 0; i -= 1) {
        if (ans[i]) one = 1;
        if (one) cout << ans[i];
    }
    if (not one) cout << 0;
}