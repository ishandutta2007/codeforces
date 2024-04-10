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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        int cnt[500] = {0};
        trav(ai, a) cin >> ai, cnt[--ai]++;

        vi ix(n);
        iota(all(ix), 0);
        sort(all(ix), [&](int i, int j) { return a[i] < a[j]; });
        vi p(n);
        rep(i, n)
            p[ix[i]] = i;

        int doub = -1;
        rep(i, 500)
            if (cnt[i] > 1)
                doub = i;

        int inv = 0;
        rep(i, n) reps(j, i+1, n)
            inv += p[i] > p[j];
        if (inv % 2) {
            if (doub == -1) {
                cout << "-1\n";
                continue;
            }
            auto i = (int)(find(all(a), doub) - begin(a));
            auto j = (int)(find(begin(a) + i + 1, end(a), doub) - begin(a));
            swap(p[i], p[j]);
        }

        vi op;
        auto rot = [&](int i) {
            op.push_back(i);
            rotate(begin(p) + i, begin(p) + i + 2, begin(p) + i + 3);
        };

        rep(i, n - 3) {
            int idx = (int)(find(all(p), i) - begin(p));
            while (idx - i > 1)
                idx -= 2, rot(idx);
            if (idx > i)
                rot(i), rot(i);
        }
        while (!is_sorted(end(p) - 3, end(p)))
            rot(n - 3);

        cout << sz(op) << '\n';
        trav(i, op)
            cout << (i + 1) << ' ';
        cout << '\n';
    }

    return 0;
}