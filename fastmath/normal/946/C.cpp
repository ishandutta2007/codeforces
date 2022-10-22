#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <random>

using namespace std;

const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;

int dp[MAXN][27];

signed main() {
    ios_base::sync_with_stdio(false);
    
    string s;
    cin >> s;

    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j <= 26; ++j) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        dp[i + 1][0] = 0;
        for (int j = 1; j <= 26; ++j) {
            char want = 'a' + j - 1;
            if (s[i] <= want) {
                dp[i + 1][j] = min(dp[i][j], dp[i][j - 1] + want - s[i]);
            }
            else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    
    if (dp[n][26] == INF) {
        cout << "-1\n";
        return 0;
    }

    int curr = 'z';
    string ans = "";
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] <= curr && dp[i][curr - 'a'] + (curr - s[i]) == dp[i + 1][curr - 'a' + 1]) {
            ans += curr;
            --curr;
        }
        else {
            ans += s[i];
        }
    }

    reverse(ans.begin(), ans.end());
    
    cout << ans << '\n';
    return 0;
}