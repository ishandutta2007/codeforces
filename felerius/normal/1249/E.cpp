#include <bits/stdc++.h>

// Contest: Codeforces Round #595 (Div. 3) (https://codeforces.com/contest/1249)
// Problem: E: By Elevator or Stairs? (https://codeforces.com/contest/1249/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c; cin >> n >> c;
    vector<int> a(n - 1), b(n - 1);
    for (auto& ai : a) cin >> ai;
    for (auto& bi : b) cin >> bi;

    vector<ll> dp(n);
    dp[0] = 0;
    set<ll> ele;
    ele.emplace(0);
    ll bsum = 0;
    for (int i = 1; i < n; ++i) {
        bsum += b[i - 1];
        dp[i] = min(dp[i - 1] + a[i - 1], *begin(ele) + c + bsum);
        ele.emplace(-bsum + dp[i]);
    }

    for (auto i : dp)
        cout << i << ' ';
    cout << '\n';

    return 0;
}