//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int m = s[0].size();
    vector<ll> conflict(1 << m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            int mask = 0;
            for (int z = 0; z < m; ++z) {
                if (s[i][z] == s[j][z]) {
                    mask |= 1 << z;
                }
            }
            conflict[mask] |= (1LL << i) | (1LL << j);
        }
    }
    for (int mask = 1 << m; mask--; ) {
        for (int i = 0; i < m; ++i) {
            if (mask & (1 << i)) {
                conflict[mask ^ (1 << i)] |= conflict[mask];
            }
        }
    }

    vector<ld> dp(1 << m);
    for (int mask = 1 << m; mask--; ) {
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((conflict[mask] & (1LL << i))) { // still need to distinguish those
                ++cnt;
            }
        }
        ld cur = (ld)cnt / n;

        ld tmp = 0.0;
        cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (!(mask & (1 << i))) {
                ++cnt;
                tmp += dp[mask | (1 << i)];
            }
        }
        if (cnt != 0) {
            cur += tmp / cnt;
        }
        dp[mask] = cur;
    }
    cout << setprecision(17) << fixed << dp[0] << endl;
}