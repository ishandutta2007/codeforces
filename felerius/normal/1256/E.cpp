#include <bits/stdc++.h>

// Contest: Codeforces Round #598 (Div. 3) (https://codeforces.com/contest/1256)
// Problem: E: Yet Another Division Into Teams (https://codeforces.com/contest/1256/problem/E)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll, int>> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i].first, s[i].second = i;

    sort(begin(s), end(s));
    vector<pair<ll, int>> dp(n + 1);
    dp[0] = {0, 0};
    dp[1] = dp[2] = {INF, 0};
    for (int i = 3; i <= n; ++i) {
        dp[i] = {dp[i - 3].first + s[i - 1].first - s[i - 3].first, 3};
        if (i >= 4)
            dp[i] = min(dp[i], pair(dp[i - 4].first + s[i - 1].first - s[i - 4].first, 4));
        if (i >= 5)
            dp[i] = min(dp[i], pair(dp[i - 5].first + s[i - 1].first - s[i - 5].first, 5));
    }

    vi t(n);
    int i = n, ti = 0;
    while (i > 0) {
        auto c = dp[i].second;
        for (int k = 0; k < c; ++k)
            t[s[i - k - 1].second] = ti;
        ++ti;
        i -= c;
    }

    cout << dp[n].first << ' ' << ti << '\n';
    for (auto ti : t)
        cout << (ti + 1) << ' ';
    cout << '\n';

    return 0;
}