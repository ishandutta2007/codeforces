#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<string> s(2);
        cin >> s[0] >> s[1];
        auto f = [&](){
            vector dp(2, vector<int>(n));
            for (int i = 0; i < n; i += 1)
                for (int j = 0; j < 2; j += 1)
                    dp[j][i] = min((s[j ^ 1][i] == '*') + (i ? dp[j][i - 1] : 0),
                        1 + (i ? dp[j ^ 1][i - 1] : 0));
            return dp;
        };
        auto pre = f();
        for (auto& si : s) ranges::reverse(si);
        auto suf = f();
        for (auto& si : suf) ranges::reverse(si);
        int ans = min({pre[0].back(), pre[1].back(), suf[0][0], suf[1][0]});
        for (int i = 0; i + 1 < n; i += 1)
            for (int j = 0; j < 2; j += 1)
                ans = min(ans, pre[j][i] + suf[j][i + 1]);
        int L = 0, R = n - 1;
        while (s[0][L] == '.' and s[1][L] == '.') L += 1;
        while (s[0][R] == '.' and s[1][R] == '.') R -= 1;
        cout << ans + R - L << "\n";
    }
}