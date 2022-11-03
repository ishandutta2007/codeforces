#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const ld e = 1e-8;

/*
10000 1000000000 1 1000000000 10000
*/

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n, vector<int>(3, 1e9));
    dp[0][0] = 1;
    if(a[0] & 1) {
        dp[0][1] = 0;
    }

    if(a[0] & 2) {
        dp[0][2] = 0;
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++)
            dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
        for(int j = 1; j < 3; j++) {
            if(a[i] & j) {
                for(int l = 0; l < 3; l++)
                    if(l != j)
                        dp[i][j] = min(dp[i][j], dp[i - 1][l]);
            }


        }
    }

    int ans = 1e9;
    for(int i = 0; i < 3; i++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans << endl;
}