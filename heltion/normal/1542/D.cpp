#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> vs(n);
    vector<LL> x(n);
    LL ans = 0;
    for (int i = 0; i < n; i += 1) {
        cin >> vs[i];
        if (vs[i] == "+") cin >> x[i];
    }
    for (int i = 0; i < n; i += 1) {
        if (vs[i] == "+") {
            vector<LL> dp(n);
            dp[0] = 1;
            for (int j = 0; j < i; j += 1) {
                if (vs[j] == "+") {
                    if (x[j] > x[i]) for (int k = 0; k < n; k += 1) (dp[k] *= 2) %= mod;
                    else for (int k = n - 1; k >= 1; k -= 1) (dp[k] += dp[k - 1]) %= mod;
                }
                else {
                    (dp[0] *= 2) %= mod;
                    for (int k = 1; k < n; k += 1) (dp[k - 1] += dp[k]) %= mod;
                }
            }
            for (int j = i + 1; j < n; j += 1) {
                if (vs[j] == "+") {
                    if (x[j] >= x[i]) for (int k = 0; k < n; k += 1) (dp[k] *= 2) %= mod;
                    else for (int k = n - 1; k >= 1; k -= 1) (dp[k] += dp[k - 1]) %= mod;
                }
                else for (int k = 1; k < n; k += 1) (dp[k - 1] += dp[k]) %= mod;
            }
            for (LL v : dp) (ans += v * x[i]) %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}