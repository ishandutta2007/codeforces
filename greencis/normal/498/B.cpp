//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<ld> dp(t + 1, 0), dp2(t + 1);
    dp[0] = 1;
    ld ans = 0;
    while (n--) {
        int percent, len;
        cin >> percent >> len;
        ld p = percent / ld(100);
        ld q = 1 - p;
        if (len == 1) {
            dp.insert(dp.begin(), 0);
            dp.pop_back();
        } else {
            ld rest = pow(q, len - 1);
            ld window = 0;
            for (int i = 0; i <= t; ++i) {
                dp2[i] = window * p;
                if (i >= len)
                    dp2[i] += dp[i - len] * rest;
                window *= q;
                window += dp[i];
                if (i - len + 1 >= 0)
                    window -= dp[i - len + 1] * rest;
            }
            swap(dp, dp2);
        }
        ans += accumulate(all(dp), ld(0));
    }
    cout << setprecision(17) << fixed << ans << endl;
}