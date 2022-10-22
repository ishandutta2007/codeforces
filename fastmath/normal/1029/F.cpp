#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 2e7 + 7;
const int INF = 1e18 + 7;

int dp[MAXN];

double gett() {
    return (double)clock() / CLOCKS_PER_SEC;
}

int solve(int a, int b) {
    for (int i = 0; i < MAXN; ++i) dp[i] = INF;

    int curr = INF;
    int mx = 0;
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) curr = min(curr, a / i);
        dp[i] = curr;
        mx = max(mx, i);
    }
    
    int ans = INF;
    int sum = a + b;
    for (int i = 1; i * i <= sum; ++i) {
        if (sum % i == 0) {
            int x = i;
            int y = sum / i;

            int t;
            if (i * i <= a) t = dp[i];
            else t = dp[mx];

            if (t <= y) {
                ans = min(ans, 2 * (x + y)); 
            }
        }
    }

    return ans;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int ans = INF;
    ans = min(ans, solve(a, b));
    ans = min(ans, solve(b, a));      
    cout << ans << '\n';

    return 0;
}