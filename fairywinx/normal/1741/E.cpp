#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <set>

#define all(a) a.begin(), a.end()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> dp(n + 1);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; --i) {
        if (i + a[i] + 1 <= n) {
            if (dp[i + a[i] + 1])
                dp[i] = 1;
        }
        if (dp[i + 1]) {
            if (i - a[i] >= 0) {
                dp[i - a[i]] = 1;
            }
        }
    }
    cout << (dp[0] ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}