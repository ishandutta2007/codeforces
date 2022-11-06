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

const int N = 1'000'005;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vpi r(n);
    for (auto& [x, y] : r) cin >> x >> y;
    vpi l1(m);
    for (auto& [x, y] : l1) cin >> x >> y;
    sort(all(l1));
    vpi l;
    for (auto& [x, y] : l1) {
        while (sz(l) && l.back().second <= y)
            l.pop_back();
        l.emplace_back(x, y);
    }

    vi nextl(n);
    vvi evt(N);
    multiset<int> ydiffs;
    auto calc_diff = [&](int i, int j) {
        if (r[i].second > l[j].second)
            return 0;
        return l[j].second + 1 - r[i].second;
    };

    rep(i, n) {
        auto [x, y] = r[i];
        auto it = lower_bound(all(l), pair(x, 0));
        nextl[i] = (int)(it - begin(l));
        if (nextl[i] < sz(l))
            ydiffs.emplace(calc_diff(i, nextl[i]));
        for (; it != end(l); ++it)
            evt[it->first + 1 - x].emplace_back(i);
    }

    if (!sz(ydiffs))
        cout << "0\n", exit(0);

    int mn = *rbegin(ydiffs);
    rep(x, N) {
        trav(i, evt[x]) {
            int olddiff = calc_diff(i, nextl[i]);
            ydiffs.erase(ydiffs.find(olddiff));
            nextl[i]++;
            if (nextl[i] < sz(l))
                ydiffs.emplace(calc_diff(i, nextl[i]));
        }
        mn = min(mn, x + (sz(ydiffs) ? *rbegin(ydiffs) : 0));
    }

    cout << mn << '\n';
    return 0;
}