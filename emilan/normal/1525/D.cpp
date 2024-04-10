#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 5000;
int dp[N + 1][N + 1];

void solve() {
    int n;
    cin >> n;
    vector<int> occu, free;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) free.push_back(i);
        else occu.push_back(i);
    }

    n = occu.size();
    int m = free.size();

    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        int mn = dp[i][i];
        for (int j = i; j < m; j++) {
            mn = min(dp[i][j], mn);
            dp[i + 1][j + 1] = mn + abs(free[j] - occu[i]);
        }
    }

    cout << *min_element(dp[n], dp[n] + m + 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}