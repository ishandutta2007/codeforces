#include <bits/stdc++.h>

using namespace std;

#define int long long

const int LG = 60;

int dp[LG][2];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int sum, x;
    cin >> sum >> x;

    dp[0][0] = 1;
    for (int i = 0; i < LG - 1; ++i) {
        int want = (sum >> i) & 1;
        int t = (x >> i) & 1;
        for (int p = 0; p <= 1; ++p) {
            for (int pr = 0; pr <= 1; ++pr) {
                for (int a = 0; a <= 1; ++a) {
                    for (int b = 0; b <= 1; ++b) {
                        if ((a + b + pr) % 2 == want && (a ^ b) == t && (a + b + pr) / 2 == p) {
                            dp[i + 1][p] += dp[i][pr];
                        }
                    }   
                }   
            }   
        }
    }   
        
    cout << dp[LG-1][0] - ((sum == x) << 1) << '\n';
    return 0;
}