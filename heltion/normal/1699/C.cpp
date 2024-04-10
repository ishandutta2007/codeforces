#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    int k = 100000;
    vector<LL> f(k + 1), g(k + 1);
    for (int i = 1; i <= k; i += 1)
        g[i] = i == 1 ? 1 : (mod - mod / i) * g[mod % i] % mod;
    for (int i = 0; i <= k; i += 1) {
        f[i] = i ? f[i - 1] * i % mod : 1;
        g[i] = i ? g[i - 1] * g[i] % mod : 1;
    }
    for (int _ : ranges::iota_view(0, t)) {
        int n;
        cin >> n;
        vector<int> a(n), p(n);
        for (int i : ranges::iota_view(0, n)) {
            cin >> a[i];
            p[a[i]] = i;
        }
        LL ans = 1;
        int L = n, R = 0;
        for (int i = 0, j = 0; i < n; i += 1) {
            while (L > p[i]) L -= 1;
            while (R < p[i]) R += 1;
            j = max(j, i + 1);
            while (j < n and p[j] >= L and p[j] <= R) {
                ans = ans * (R - L - j + 1) % mod;
                j += 1;
            }
        }
        cout << ans << "\n";
    }
}