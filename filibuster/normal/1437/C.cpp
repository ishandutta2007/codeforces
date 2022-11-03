#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

/*
1
228 21 11 3
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<vector<int>> dp(n * 2, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for(int i = 1; i < n * 2; i++) {
        dp[i][0] = 0;
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1] + abs(i - a[j - 1]));
        }
    }

    cout << dp[n * 2 - 1][n] << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();


}