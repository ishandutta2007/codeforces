#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

int a[200200];
int dp[200200][2]; // 0 - friend last, 1 - me last

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        memset(dp, 0x3f, sizeof(int) * 2 * (n + 5));
        dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i + 1]);
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][1] + a[i + 1] + a[i + 2]);
        }
        cout << min(dp[n][0], dp[n][1]) << '\n';
    }
}