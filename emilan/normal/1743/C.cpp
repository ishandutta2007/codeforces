#include <bits/stdc++.h>
// #include <atcoder/modint>

using namespace std;
// using namespace atcoder;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using pii = pair<int, int>;

const int kInf = 2e9;

void chmax(int &x, int y) {
    x = max(x, y);
}

void solve() {
    int n;
    cin >> n;
    vector<bool> b(n);
    for (auto x : b) {
        char c;
        cin >> c;
        x = c == '1';
    }
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    a.push_back(0);
    b.push_back(false);

    vector<array<int, 2>> dp(n + 1, {-kInf, -kInf});
    dp[0][b[0]] = 0;
    for (int i = 0; i < n; i++) {
        if (b[i + 1]) chmax(dp[i + 1][0], dp[i][0] + a[i]);
        chmax(dp[i + 1][b[i + 1]], max(dp[i][0], dp[i][1] + a[i]));
    }
    cout << dp[n][0] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}