#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   

int n;
int a[MAXN];
int dp[MAXN];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        vector <int> v;
        for (int d = 1; d * d <= a[i]; ++d) {
            if (a[i] % d == 0) {
                if (d * d == a[i]) {
                    v.push_back(d);
                }
                else {
                    v.push_back(d);
                    v.push_back(a[i] / d);
                }   
            }   
        }   
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (auto e : v) {
            if (MAXN <= e) continue;
            dp[e] = mod(dp[e] + dp[e - 1]);
        }   
    }   

    int ans = 0;
    for (int i = 1; i < MAXN; ++i) ans = mod(ans + dp[i]);
    cout << ans << '\n';

    return 0;
}