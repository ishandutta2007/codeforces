#include <bits/stdc++.h>

// Contest: Codeforces Round #591 (Div. 1, based on Technocup 2020 Elimination Round 1) (https://codeforces.com/contest/1240)
// Problem: B: Sequence Sorting (https://codeforces.com/contest/1240/problem/B)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& ai : a) cin >> ai;

        map<int, int> m;
        for (auto ai : a) m[ai] = 0;
        auto it = begin(m);
        for (int i = 0; it != end(m); ++it, ++i)
            it->second = i;
        for (auto& ai : a) ai = m[ai];

        int n2 = m.size();
        vector<pair<int, int>> dp(n2, pair(-1, n2));

        multiset<int> before, after(begin(a), end(a));
        for (int i = 0; i < n; ++i) {
            auto it3 = after.find(a[i]);
            if (it3 != end(after))
                after.erase(it3);
            auto it = after.lower_bound(a[i]);
            if (it != begin(after))
                dp[a[i]].first = max(dp[a[i]].first, *prev(it));
            auto it2 = before.upper_bound(a[i]);
            if (it2 != end(before))
                dp[a[i]].second = min(dp[a[i]].second, *it2);
            before.emplace(a[i]);
        }

        int mx = 0;
        int l = 0, r = 0;
        while (r < n2) {
            if (r + 1 <= dp[l].second && dp[r].first < l)
                ++r;
            else
                ++l;
            mx = max(mx, r - l);
        }

        cout << (n2 - mx) << '\n';
    }

    return 0;
}