// Short Task (https://codeforces.com/contest/1512/problem/G)
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
// begin "cp-lib/math/sieves/multiplicative.hpp"
namespace cp_lib {
    template <int N, class F>
    auto multiplicative_function_sieve(F f) {
        array<decltype(f(0, 0, 0, 0)), N + 1> sieve{};
        vector<int> exp(N + 1), prime;
        sieve[1] = 1;
        rep(i, 2, N + 1) {
            if (!sieve[i]) {
                prime.push_back(i);
                for (ll e = 1, ie = i; ie <= N; ++e, ie *= i)
                    sieve[ie] = f(i, int(e), int(ie), sieve[ie / i]), exp[ie] = int(ie);
            }
            for (int j = 0; j < sz(prime) && ll(i) * prime[j] <= N; ++j) {
                if (i % prime[j] == 0) {
                    exp[i * prime[j]] = exp[i] * prime[j];
                    sieve[i * prime[j]] = sieve[i / exp[i]] * sieve[exp[i * prime[j]]];
                    break;
                }
                sieve[i * prime[j]] = sieve[i] * sieve[prime[j]];
                exp[i * prime[j]] = prime[j];
            }
        }
        return sieve;
    }
}
// end "cp-lib/math/sieves/multiplicative.hpp"

using namespace cp_lib;

auto sieve = multiplicative_function_sieve<10'000'005>([](int p, int, int pe, ll) -> ll {
    return ((ll(pe) * p) - 1) / (p - 1);
});
int first[10'000'005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    rep(i, 1, sz(sieve))
        if (sieve[i] < sz(first) && first[sieve[i]] == 0)
            first[sieve[i]] = i;

    int t; cin >> t;
    while (t--) {
        int c; cin >> c;
        cout << (first[c] ? first[c] : -1) << '\n';
    }

    return 0;
}