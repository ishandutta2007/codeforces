#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1'000'000'007;
void add(int& x, int y) {
    if ((x += y) >= mod) x -= mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m = 40000;
    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i += 1) {
        auto s = to_string(i);
        auto t = s;
        ranges::reverse(t);
        if (s == t) {
            for (int j = 0; j < i; j += 1) {
                for (int k = j + i; k <= m; k += i)
                    add(dp[k], dp[k - i]);
            }
        }
    }
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}