// Travelling Salesman Problem (https://codeforces.com/contest/1504/problem/E)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

constexpr int N = 100'005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector a(n, pair(0, 0));
    for (auto& [ai, ci] : a)
        cin >> ai >> ci;
    sort(all(a));

    vector dp(n, INFL);
    dp[0] = 0;
    ll min_low = INFL;
    multiset<ll> set_high;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> switch_q;

    set_high.emplace(0);
    switch_q.emplace(a[0].first + a[0].second, 0);

    rep(i, 1, n) {
        while (sz(switch_q) && switch_q.top().first <= a[i].first) {
            int j = switch_q.top().second;
            switch_q.pop();
            set_high.erase(set_high.find(dp[j]));
            min_low = min(min_low, dp[j] - a[j].first - a[j].second);
        }

        if (sz(set_high))
            dp[i] = *begin(set_high);
        dp[i] = min(dp[i], min_low + a[i].first);

        set_high.emplace(dp[i]);
        switch_q.emplace(a[i].first + a[i].second, i);
    }

    ll ans = dp.back();
    rep(i, n)
        ans += a[i].second;
    cout << ans << '\n';

    return 0;
}