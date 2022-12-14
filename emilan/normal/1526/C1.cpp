#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<ll> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) if (dp[j] != -1) {
            dp[j + 1] = max(dp[j] + a[i], dp[j + 1]);
        }
    }

    for (int i = n; i >= 0; i--) {
        if (dp[i] != -1) return cout << i, 0;
    }
}