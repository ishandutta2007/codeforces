#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 76 (Rated for Div. 2) (https://codeforces.com/contest/1257)
// Problem: D: Yet Another Monster Killing Problem (https://codeforces.com/contest/1257/problem/D)

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto createRMQ = [](int n, auto init, auto combine) {
        // returns an exclusive query lambda
        using T = decltype(init(0));
        auto ilog = [](uint32_t i) { return 31 - __builtin_clz(i); };
        // rmq[k][i] stores min of interval [i, i+2^k)
        auto rmq = vector<vector<T>>(ilog(n)+1, vector<T>(n));
        // init bottom level
        for (int i = 0; i < n; ++i) rmq[0][i] = init(i);
        for (int k = 1; k <= ilog(n); k++)
            for (int i = 0; i + (1 << k) <= n; i++)
                rmq[k][i] = combine(rmq[k-1][i], rmq[k-1][i + (1 << (k-1))]);
        // mutable s.t. combine can take non-const args
        return [rmq=move(rmq), ilog, combine](int l, int r) mutable {
            auto log = ilog(r-l);
            return combine(rmq[log][l], rmq[log][r - (1 << log)]);
        };
    };

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        for (auto& ai : a) cin >> ai;
        int m; cin >> m;
        vpi h(m);
        for (auto& [p, s] : h) cin >> p >> s;

        auto rmq = createRMQ(n, [&](auto i) { return a[i]; }, [](int a, int b) { return max(a, b); });
        sort(begin(h), end(h), [](auto& a, auto& b) {
            return a.second > b.second;
        });

        auto it = begin(h);
        vi max_pow(n + 1);
        for (int i = n; i > 0; --i) {
            if (i < n)
                max_pow[i] = max_pow[i + 1];
            while (it != end(h) && it->second == i)
                max_pow[i] = max(max_pow[i], (it++)->first);
        }

        int mx_monst = *max_element(begin(a), end(a));
        if (mx_monst > max_pow[1]) {
            cout << "-1\n";
            continue;
        }

        vi dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = i + 1;
            while (r - l > 1) {
                int m = (l + r) / 2;
                int mx = rmq(i - m, i);
                if (mx <= max_pow[m])
                    l = m;
                else
                    r = m;
            }
            dp[i] = dp[i - l] + 1;
        }

        cout << dp[n] << '\n';
    }

    return 0;
}