#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
constexpr int kM = 1e6 + 1;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    bitset<kM> exists;
    for (int x : a) exists[x] = true;

    array<i64, kM> dp = {};
    for (int i = kM - 1; i > 0; i--) {
        int cnt = 0;
        for (int j = 2 * i; j < kM; j += i) {
            if (exists[j]) cnt++;
            dp[i] -= dp[j];
        }
        dp[i] += cnt * i64(cnt - 1) / 2;
        if (exists[i] || dp[i] != 0) {
            exists[i] = true;
            dp[i] += cnt;
        }
    }

    cout << exists.count() - n << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}