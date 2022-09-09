#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
void add(int& u, int v) {
    u += v;
    if (u >= mod) u -= mod;
}
void sub(int& u, int v) {
    u -= v;
    if (u < 0) u += mod;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> l(n), r(n);
    vector<int> np(m + 1), ans(m + 1), p;
    for (int i = 0; i < n; i += 1) cin >> l[i] >> r[i];
    for (int i = 2; i <= m; i += 1) {
        if (not np[i]) {
            p.push_back(i);
            for (int j = i * 2; j <= m; j += i) np[j] = 1;
        }
    }
    for (int i = 1; i <= m; i += 1) {
        vector<int> L(n), R(n);
        int M = m / i, ok = 1;
        for (int j = 0; j < n; j += 1) {
            L[j] = (l[j] + i - 1) / i;
            R[j] = r[j] / i;
            if (L[j] > R[j]) ok = 0;
            M -= L[j];
            R[j] -= L[j];
        }
        if (not ok or M < 0) continue;
        vector<int> dp(M + 1);
        dp[0] = 1;
        for (int j = 0; j < n; j += 1) {
            for (int i = 1; i <= M; i += 1) add(dp[i], dp[i - 1]);
            for (int i = M; i >= 0; i -= 1)
                if (i > R[j]) sub(dp[i], dp[i - R[j] - 1]);
        }
        for (int x : dp) add(ans[i], x);
    }
    for (int x : p)
        for (int i = 1; i * x <= m; i += 1)
            sub(ans[i], ans[i * x]);
    cout << ans[1];
    return 0;
}