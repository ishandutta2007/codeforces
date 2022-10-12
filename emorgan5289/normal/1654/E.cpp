#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
struct splitmix64 {
    size_t operator()(size_t x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        x += 0x9e3779b97f4a7c15 + fixed;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
};
 
const int N = 1e5+5, S = 70;
int n, a[N];
 
// for small d case: b[i] = number of elements in bucket i
int b[N*S];
 
// for large d case: dp[i][j] = maximum length of a path ending
// at index i, such that all edges in the path have label j
gp_hash_table<int, int, splitmix64> dp[N];
 
// solve under the assumption that d >= 0
int solve() {
 
    int ans = 0;
 
    // d < S
    for (int d = 0; d < S; d++) {
        for (int i = 0; i < n; i++)
            ans = max(ans, ++b[a[i]+(n-i)*d]);
        for (int i = 0; i < n; i++)
            b[a[i]+(n-i)*d] = 0;
    }
 
    // S <= d < N
    for (int i = 0; i < n; i++) {
        for (int j = max(0, i-N/S); j < i; j++) {
            int d = (a[i]-a[j])/(i-j);
            int r = (a[i]-a[j])%(i-j);
            if (r == 0 && d >= S) {
                dp[i][d] = max(dp[i][d], dp[j][d]+1);
                ans = max(ans, dp[i][d]+1);
            }
        }
    }
 
    for (int i = 0; i < n; i++)
        dp[i].clear();
 
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = solve();
    reverse(a, a+n);
    ans = max(ans, solve());
    cout << n-ans << "\n";
}