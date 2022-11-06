#include <bits/stdc++.h>

// Contest: Codeforces Round #590 (Div. 3) (https://codeforces.com/contest/1234)
// Problem: F: Yet Another Substring Reverse (https://codeforces.com/contest/1234/problem/F)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    auto n = s.size();

    vector<uint8_t> exists(1u << 20);
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        bitset<20> b;
        int j = i;
        while (j >= 0 && !b[s[j] - 'a']) {
            b[s[j] - 'a'] = true;
            --j;

            exists[b.to_ulong()] = true;
        }
    }

    vector<int> dp(1u << 20u);
    dp[0] = 0;
    for (u32 m = 1; m < (1u << 20u); ++m) {
        if (exists[m]) {
            dp[m] = __builtin_popcountll(m);
        } else {
            for (u32 i = 0; i < 20; ++i) {
                if (((m >> i) & 1u) == 0)
                    continue;
                dp[m] = max(dp[m], dp[m & ~(1u << i)]);
            }
        }
    }

    int mx = 0;
    for (u32 m = 1; m < (1u << 20u); ++m) {
        if (!exists[m])
            continue;
        mx = max(mx, dp[m] + dp[~m & 0xFFFFFu]);
    }

    cout << mx << '\n';

    return 0;
}