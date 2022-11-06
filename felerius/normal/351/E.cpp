#include <bits/stdc++.h>

// Contest: 20 - 2100 <= Codeforces Rating <= 2199 (https://a2oj.com/ladder?ID=20)
// Problem: (29) Jeff and Permutation (Difficulty: 5) (http://codeforces.com/problemset/problem/351/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> p(n);
    for (auto& pi : p) {
        cin >> pi;
        pi = abs(pi);
    }

    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) { return p[i] > p[j]; });

    vector<int> dp(n), dp_prev(n);
    for (int i = 0; i < n; ++i) {
        int left = 0;
        int right = 0;
        for (int j = i + 1; j < n; ++j) {
            left += p[idx[j]] < p[idx[i]] && idx[j] < idx[i];
            right += p[idx[j]] < p[idx[i]] && idx[j] > idx[i];
        }

        for (int j = 0; j < n; ++j) {
            dp[j] = dp_prev[j] + left;
            if (j > 0)
                dp[j] = min(dp[j], dp_prev[j - 1] + right);
        }

        swap(dp, dp_prev);
    }

    cout << *min_element(begin(dp_prev), end(dp_prev)) << '\n';
    return 0;
}