// region boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <chrono>
#include <cstdint>
#include <deque>
#include <exception>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#if __cplusplus >= 201703L
#   include <optional>
#   include <string_view>
#   include <variant>
#endif

using namespace std;

#if __cplusplus >= 201703L
#   define all(a)      begin(a),end(a)
#   define sz(x)       ((int)size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define trav(a, b)     for(auto& a : b)

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18 + 5;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion

template <class F>
void gen_all(vpi& f, int l, int r, int base, F func) {
    if (l == r) {
        func(base);
        return;
    }

    auto [b, e] = f[l];
    int be = 1;
    rep(i, e + 1) {
        gen_all(f, l + 1, r, base * be, func);
        be *= b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vpi f;
        for (ll i = 2; i * i <= n; ++i) {
            if (n % i) continue;
            f.emplace_back((int)i, 0);
            while (n % i == 0)
                n /= i, f.back().second++;
        }
        if (n > 1)
            f.emplace_back(n, 1);

        auto [b1, e1] = f[0];
        vi ans = {b1};
        rep(_, e1 - 1)
            ans.push_back(ans.back() * b1);

        reps(i, 1, sz(f)) {
            auto [b, e] = f[i];
            int tie = f[i-1].first * b;
            ans.push_back(tie);
            ans.push_back(b);
            rep(_, e - 1)
                ans.push_back(ans.back() * b);

            int be = 1;
            rep(_, e) {
                be *= b;
                gen_all(f, 0, i, be, [&, b=b](int val) {
                    if (val == tie)
                        return;
                    int val2 = val;
                    while (val2 % b == 0)
                        val2 /= b;
                    if (val2 > 1)
                        ans.push_back(val);
                });
            }
        }

        trav(i, ans)
            cout << i << ' ';
        cout << '\n' << (int)(gcd(ans[0], ans.back()) == 1) << '\n';
    }

    return 0;
}