#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 1000 + 13;

/*

*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    li k;
    cin >> n >> k;

    vector<li> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(dp[i - 1] == -1 || dp[i - 2] == -1 || dp[i - 1] + dp[i - 2] >= INF)
            dp[i] = -1;
        else
            dp[i] = dp[i - 1] + dp[i - 2];
//        cout << dp[i] << endl;
    }

    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        if(dp[n - i - 1] == -1 || dp[n - i - 1] >= k) {
            ans[i] = i;
        } else {
            k -= dp[n - i - 1];
            ans[i] = i + 1;
            ans[i + 1] = i;
            i++;

        }
    }

    for(auto x : ans)
        cout << x + 1 << ' ';
}