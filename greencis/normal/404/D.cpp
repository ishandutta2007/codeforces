#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1'000'000'007;
inline void add(int& x, int y) {
    x += y;
    if (x >= mod)
        x -= mod;
}

int dp[2][4][4]; /// 012*

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    if (s[0] == '0') {
        dp[0][0][0] = 1;
    } else if (s[0] == '1') {
        dp[0][0][1] = 1;
    } else if (s[0] == '2') {
        cout << "0\n";
        return 0;
    } else if (s[0] == '*') {
        dp[0][1][3] = 1;
    } else {
        dp[0][0][0] = dp[0][0][1] = dp[0][1][3] = 1;
    }

    int cur = 0;
    for (int i = 1; i < n; ++i) {
        cur ^= 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        int L = 0, R = 3;
        if (s[i] == '0') L = R = 0;
        if (s[i] == '1') L = R = 1;
        if (s[i] == '2') L = R = 2;
        if (s[i] == '*') L = R = 3;
        for (int x = 0; x <= 3; ++x) {
            for (int y = 0; y <= 3; ++y) {
                for (int z = L; z <= R; ++z) {
                    if (y <= 2 && (x == 3) + (z == 3) != y)
                        continue;
                    if (y == 3 && (x == 0 || z == 0))
                        continue;
                    add(dp[cur][y][z], dp[cur ^ 1][x][y]);
                }
            }
        }
        dp[cur][0][2] = 0;
        dp[cur][0][3] = 0;
        dp[cur][1][2] = 0;
        dp[cur][2][0] = 0;
        dp[cur][2][1] = 0;
        dp[cur][2][2] = 0;
        dp[cur][3][0] = 0;
    }

    int ans = 0;
    add(ans, dp[cur][0][0]);
    add(ans, dp[cur][1][0]);
    add(ans, dp[cur][1][3]);
    add(ans, dp[cur][2][3]);
    add(ans, dp[cur][3][1]);
    add(ans, dp[cur][3][3]);
    cout << ans << endl;
}