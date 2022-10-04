#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

string a[2];
const int N = 107;

int dp[N][4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> a[0] >> a[1];
    int n = a[0].size();
    for (int i = 1; i < n; ++i) {
        for (int m = 0; m < 4; ++m) {
            for (int pm = 0; pm < 4; ++pm) dp[i][m] = max(dp[i][m], dp[i - 1][pm]);
            int c = 0;
            if (a[0][i - 1] == 'X') c |= 1;
            if (a[1][i - 1] == 'X') c |= 2;
            int nc = 0;
            if (a[0][i] == 'X') nc |= 1;
            if (a[1][i] == 'X') nc |= 2;
            if ((m == 1 || m == 2) && (nc == 0 || (nc != 3 && nc != m)) && c == 0) {
                dp[i][m] = max(dp[i][m], dp[i - 1][0] + 1);
            }
            if (m == 3 && nc == 0 && c != 3) {
                if (c == 1 || c == 0) {
                    dp[i][m] = max(dp[i][m], dp[i - 1][1] + 1);
                }
                if (c == 2 || c == 0) {
                    dp[i][m] = max(dp[i][m], dp[i - 1][2] + 1);
                }
            }
        }
        dp[i][1] = max(dp[i][1], dp[i][0]);
        dp[i][2] = max(dp[i][2], dp[i][0]);
        dp[i][3] = max(dp[i][3], max(dp[i][1], dp[i][2]));
    }
    int ans = 0;
    for (int m = 0; m < 4; ++m) {
        ans = max(ans, dp[n - 1][m]);
    }
    cout << ans << '\n';
}