// The Number of Pairs (https://codeforces.com/contest/1499/problem/D)
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

constexpr int N = 20'000'005;
uint8_t num_prime_factors[N];
vector<int> primes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i < N; ++i) {
        if (!num_prime_factors[i]) {
            primes.push_back(i);
            num_prime_factors[i] = 1;
        }
        for (int j = 0; j < sz(primes) && ll(i) * primes[j] < N; ++j) {
            if (i % primes[j] == 0) {
                num_prime_factors[i * primes[j]] = num_prime_factors[i];
                break;
            }
            num_prime_factors[i * primes[j]] = num_prime_factors[i] + 1;
        }
    }

    int t; cin >> t;
    while (t--) {
        int c, d, x; cin >> c >> d >> x;

        int cnt = 0;
        auto check = [&](int g) {
            if ((x / g + d) % c) return;
            cnt += 1 << num_prime_factors[(x / g + d) / c];
        };

        for (int i = 1; i * i <= x; ++i) {
            if (x % i) continue;
            check(i);
            if (i * i != x)
                check(x / i);
        }

        cout << cnt << '\n';
    }

    return 0;
}