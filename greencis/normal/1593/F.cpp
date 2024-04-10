#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;

char dp[41][41][40][40]; // 0 - none,   1..40 - rem_A + 1,   41..80 - rem_B + 1
char s[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, a, b;
        cin >> n >> a >> b >> s;
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0] = 1;
        for (int red = 0; red < n; ++red) {
            for (int black = 0; red + black < n; ++black) {
                for (int rem_a = 0; rem_a < a; ++rem_a) {
                    for (int rem_b = 0; rem_b < b; ++rem_b) {
                        if (!dp[red][black][rem_a][rem_b]) continue;
                        dp[red + 1][black][(rem_a * 10 + s[red + black] - '0') % a][rem_b] = rem_a + 1;
                        dp[red][black + 1][rem_a][(rem_b * 10 + s[red + black] - '0') % b] = rem_b + 41;
                    }
                }
            }
        }
        int mn = 1e9, mnr = -1, mnb = -1;
        for (int red = 1; red < n; ++red) {
            int black = n - red;
            if (dp[red][black][0][0]) {
                if (abs(red - black) < mn) {
                    mn = abs(red - black);
                    mnr = red;
                    mnb = black;
                }
            }
        }
        if (mnr == -1) {
            cout << "-1\n";
        } else {
            string s;
            int ca = 0, cb = 0;
            while (mnr || mnb) {
                if (dp[mnr][mnb][ca][cb] >= 41) {
                    s.push_back('B');
                    cb = dp[mnr][mnb][ca][cb] - 41;
                    --mnb;
                } else {
                    s.push_back('R');
                    ca = dp[mnr][mnb][ca][cb] - 1;
                    --mnr;
                }
            }
            reverse(all(s));
            cout << s << '\n';
        }
    }
}