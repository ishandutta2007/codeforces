#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, INF = 1e9;
int dp[N][2];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, c;
    cin >> n >> c;
    vector<int> a(n - 1), b(n - 1);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    dp[0][0] = 0;
    dp[0][1] = INF;
    cout << 0;
    for (int i = 0; i < n - 1; i++) {
        dp[i + 1][0] = min(dp[i][0], dp[i][1]) + a[i];
        dp[i + 1][1] = min(dp[i][0] + c, dp[i][1]) + b[i];
        cout << ' ' << min(dp[i + 1][0], dp[i + 1][1]);
    }
}