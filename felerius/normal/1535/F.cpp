// String Distance (https://codeforces.com/contest/1535/problem/F)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>
#ifdef LOCAL
#  include <dbg.h>
#else
#  define dbg(...) do {} while (0)
#endif

#define _choose(_1, _2, _3, x, ...)     x
#define _rep(i, l, r)                   for (int i = l; i < r; ++i)
#define _rep0(i, r)                     _rep(i, 0, r)
#define rep(...)                        _choose(__VA_ARGS__, _rep, _rep0, _)(__VA_ARGS__)
#define _repr(i, r, l, ...)             for (int i = r; i >= l; --i)
#define repr(...)                       _repr(__VA_ARGS__, 0)
#define all(a)                          ::begin(a),::end(a)
#define trav(a, b)                      for (auto&& a : b)

using namespace std;
namespace cp_lib {}

using ll = long long;
using ld = long double;
[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
template <class C> int sz(const C& c) { return int(::size(c)); }
// end "cp-lib/boilerplate.hpp"
// begin "cp-lib/string/hashing.hpp"
// begin "../rng.hpp"
[[maybe_unused]] static mt19937 rng(uint32_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));
// end "../rng.hpp"

namespace cp_lib::_hashing_detail {
    template <class H>
    struct IntervalHash {
        uint32_t n;
        vector<uint64_t> h;

        template <class Iter>
        IntervalHash(Iter it, Iter end) : n(uint32_t(end - it)), h(n + 1) {
            rep(i, n)
                h[i + 1] = H::add(h[i], H::mul(it[i], H::ae[i]));
        }

        auto get(int l, int r) { return H::mul(H::sub(h[r], h[l]), H::ae[n - l]); }
    };

    template <size_t N>
    struct HashSetup {
        static constexpr uint64_t MOD = 8554803928767475367, INV = 2879366533815572759, R2 = 5238070210108173946;

        static constexpr auto add(uint64_t a, uint64_t b) { uint64_t x = a + b; return x - (x >= MOD) * MOD; }
        static constexpr auto sub(uint64_t a, uint64_t b) { return a - b + (b > a) * MOD; }
        static constexpr auto reduce(uint64_t a, uint64_t b) { return sub(a, uint64_t(((unsigned __int128)(b * INV) * MOD) >> 64));}
        static constexpr auto mul(uint64_t a, uint64_t b) { auto x = (unsigned __int128)a * b; return reduce(uint64_t(x >> 64), uint64_t(x)); }
        static constexpr auto mont(uint64_t a) { return mul(a, R2); }

        static array<uint64_t, N + 1> ae;

        static void init() {
            ae[0] = mont(1);
            ae[1] = mont(((uint64_t(rng()) << 29) ^ rng()) | (1ull << 61)); // [2^61, 2^62)
            rep(i, 2, N + 1)
                ae[i] = mul(ae[i - 1], ae[1]);
        }

        template <class Iter>
        static IntervalHash<HashSetup> interval(Iter it, Iter end) { return {it, end}; }
        static auto interval(string_view s) { return interval(all(s)); }

        template <class Iter>
        static auto hash(Iter it, Iter end) {
            uint64_t h = 0;
            rep(i, end - it)
                h = add(h, mul(it[i], ae[i]));
            return h;
        }
        static auto hash(string_view s) { return hash(all(s)); }
    };

    template <size_t N> array<uint64_t, N + 1> HashSetup<N>::ae;
}

namespace cp_lib { using _hashing_detail::HashSetup; }
// end "cp-lib/string/hashing.hpp"

#include <bits/extc++.h> /** keep-include */
struct chash { // large odd number for C
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(pair<uint64_t, uint64_t> x) const { return __builtin_bswap64((x.first ^ x.second)*C); }
};
using HashTable = __gnu_pbds::gp_hash_table<pair<uint64_t, uint64_t>,int,chash>;

using namespace cp_lib;

using Hash = HashSetup<200'005>;
using IntervalHash = decltype(Hash::interval(string()));

template <class It>
ll solve_short_strings(It it, It it_end) {
    int n = int(it_end - it), m = sz(it->second);
    vector which(m + 1, vector(m + 1, vector<int>()));
    vector<IntervalHash> h;
    rep(i, n)
        h.push_back(Hash::interval(it[i].second));

    ll cnt = 0;
    rep(i, n) {
        auto& s = it[i].second;
        int l = 0;
        while (l < m) {
            int r = l + 1;
            while (r < m && s[r] >= s[r - 1])
                ++r;

            which[l][r].push_back(i);
            l = r;
        }
    }

    HashTable hash_map;
    rep(l, m + 1) rep(r, l, m + 1) {
        hash_map.clear();
        rep(i, n) {
            auto pref_h = h[i].get(0, l);
            auto suff_h = h[i].get(r, m);
            hash_map[pair(pref_h, suff_h)]++;
        }

        trav(i, which[l][r]) {
            auto pref_h = h[i].get(0, l);
            auto suff_h = h[i].get(r, m);
            cnt += hash_map[pair(pref_h, suff_h)] - 1;
        }
    }

    return cnt;
}

template <class It>
ll solve_few_strings(It it, It it_end) {
    int n = int(it_end - it), m = sz(it->second);
    vector<IntervalHash> h;
    rep(i, n)
        h.push_back(Hash::interval(it[i].second));

    ll cnt = 0;
    rep(i, n) {
        auto& s = it[i].second;
        int l = 0;
        while (l < m) {
            int r = l + 1;
            while (r < m && s[r] >= s[r - 1])
                ++r;

            auto mid_hash = Hash::sub(h[i].h[r], h[i].h[l]);
            rep(j, n) {
                if (i == j)
                    continue;
                auto sorted_hash = h[j].h[l];
                sorted_hash = Hash::add(sorted_hash, mid_hash);
                sorted_hash = Hash::add(sorted_hash, Hash::sub(h[j].h.back(), h[j].h[r]));
                cnt += (sorted_hash == h[i].h.back());
            }

            l = r;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Hash::init();

    int n; cin >> n;
    vector<pair<array<int, 26>, string>> s(n);
    for (auto& [cnts, si] : s) {
        cin >> si;
        trav(c, si)
            cnts[c - 'a']++;
    }
    sort(all(s));

    ll ans = n * ll(n - 1) / 2 * 1337;
    int i = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[i].first == s[j].first)
            ++j;

        int w = j - i;
        ll dist1;
        constexpr int SQRT = 350;
        if (sz(s[0].second) <= SQRT)
            dist1 = solve_short_strings(begin(s) + i, begin(s) + j);
        else
            dist1 = solve_few_strings(begin(s) + i, begin(s) + j);
        ans -= w * ll(w - 1) / 2 * 1335 + dist1;
        i = j;
    }

    cout << ans << '\n';
    return 0;
}