#include <bits/stdc++.h>

using namespace std;

#define SZ(a)   int(size(a))
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)

using ll = long long;
using i128 = __int128_t;
using ld = long double;
using pii = pair<int, int>;

const int kK = 22;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    array<int, 1 << kK> dp;
    dp.fill(-1);
    for (int x : a) dp[x] = x;
    for (int i = 0; i < kK; i++) {
        for (int msk = 0; msk < 1 << kK; msk++) if (msk >> i & 1) {
            dp[msk] = max(dp[msk], dp[msk ^ (1 << i)]);
        }
    }

    for (int i = 0; i < n; i++) {
        int x = a[i] ^ ((1 << kK) - 1);
        cout << dp[x] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
}