#include <bits/stdc++.h>

using namespace std;

#define REP(i, n)   for (int i = 0; (i) < (n); (i)++)
#define SZ(a)       int(size(a))
#define ALL(a)      begin(a), end(a)
#define RALL(a)     rbegin(a), rend(a)

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using ld = long double;
using pii = pair<int, int>;

bool try_knapsack(const vector<int> &wei, int m) {
    vector<bool> dp(m + 1);
    dp[0] = true;
    for (int w : wei) {
        for (int i = m; i >= w; i--) if (dp[i - w]) {
            dp[i] = true;
        }
    }
    return dp[m];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int ans = INT_MAX;
    REP(cnt1, 3) REP(cnt2, 3) {
        vector<int> knapsack;
        knapsack.insert(end(knapsack), cnt1, 1);
        knapsack.insert(end(knapsack), cnt2, 2);

        int max_cnt3 = 0;
        for (int x : a) {
            bool ok = false;
            for (int cnt3 = max(x / 3 - 2, 0); cnt3 <= x / 3; cnt3++) {
                if (try_knapsack(knapsack, x - 3 * cnt3)) {
                    ok = true;
                    max_cnt3 = max(max_cnt3, cnt3);
                    break;
                }
            }
            if (!ok) goto bye;
        }
        ans = min(ans, cnt1 + cnt2 + max_cnt3);
bye:
        ;
    }
    cout << ans << '\n';
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