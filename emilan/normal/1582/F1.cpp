#include <bits/stdc++.h>

using namespace std;

const int K = 512;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> pos(K);
    for (int i = 0; i < n; i++) {
        pos[ a[i] ].push_back(i);
    }

    // dp[a_val][xor_val] = min_pos
    vector<int> ans{0};
    vector<int> dp(K, n);
    dp[0] = -1;
    for (int i = 0; i < K - 1; i++) {
        vector<int> dp_nxt(K, n);

        for (int u = 0; u < K; u++) {
            auto it = upper_bound(pos[i].begin(), pos[i].end(), dp[u]);
            if (it == pos[i].end()) continue;

            dp_nxt[u ^ i] = *it;
            ans.push_back(u ^ i);
        }

        for (int p = 0; p < K; p++) {
            dp[p] = min(dp[p], dp_nxt[p]);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << '\n';
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}