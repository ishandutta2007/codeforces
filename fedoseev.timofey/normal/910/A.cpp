#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Inf = 1e9;

int main() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    vector <int> dp(n + 1, Inf);
    dp[0] = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') continue;
        for (int k = 1; k <= d && i - k >= 0; ++k) {
            dp[i] = min(dp[i], dp[i - k] + 1);
        }
    }
    if (dp[n - 1] == Inf) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[n - 1] << endl;
}