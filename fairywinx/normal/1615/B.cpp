#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

// void solve() {
//     int l, r;
//     cin >> l >> r;
//     int ans = r + 228;
//     for (int i = 0; i < 30; ++i) {

//     }
// }

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    // SOLVE;
    const int N = 2e5 + 228;
    const int K = 20;
    vector<vector<int>> cnt(K, vector<int> (N));
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if ((1 << j) & i) {
                cnt[j][i] = cnt[j][i - 1] + 1;
            } else {
                cnt[j][i] = cnt[j][i - 1];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = r + 228;
        for (int i = 0; i < K; ++i) {
            ans = min(ans, r - l + 1 - (cnt[i][r] - cnt[i][l - 1]));
        }
        cout << ans << '\n';
    }
}