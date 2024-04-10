#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 74 (Rated for Div. 2) (https://codeforces.com/contest/1238)
// Problem: E: Keyboard Purchase (https://codeforces.com/contest/1238/problem/E)

using namespace std;

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

template <class F>
void iterate_bits(u32 m, F f) {
    while (m) {
        f(__builtin_ctzl(m));
        m &= m - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    u32 n, m; cin >> n >> m;
    string s; cin >> s;
    arr<int, 26, 26> d{};
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            continue;
        auto a = s[i] - 'a';
        auto b = s[i - 1] - 'a';
        d[a][b]++;
        d[b][a]++;
    }

    vector<pair<ll, ll>> dp(1u << m, pair((ll)1e18, (ll)1e18));
    for (u32 i = 0; i < m; ++i) {
        ll out = 0;
        for (int j = 0; j < m; ++j)
            out += d[i][j];
        dp[1u << i] = {0, out};
    }

    for (u32 s = 1; s < (1u << m); ++s) {
        if (__builtin_popcountl(s) == 1)
            continue;
        iterate_bits(s, [&](auto i) {
            auto s_without = s & ~(1u << i);
            auto [cost, to_right] = dp[s_without];
            ll i_right = 0, i_left = 0;
            for (u32 j = 0; j < m; ++j) {
                if ((s_without >> j) & 1)
                    i_left += d[i][j];
                else
                    i_right += d[i][j];
            }

            auto new_cost = cost + to_right;
            auto new_to_right = to_right - i_left + i_right;
            dp[s] = min(dp[s], pair(new_cost, new_to_right));
        });
    }

    cout << dp[(1u << m) - 1].first << '\n';

    return 0;
}