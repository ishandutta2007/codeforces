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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
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
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((u32)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
// endregion

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vvi files(m);
    vi clust(n, -1);

    rep(i, m) {
        int ni; cin >> ni;
        files[i].resize(ni);
        trav(ci, files[i])
            cin >> ci, --ci, clust[ci] = i;
    }

    int fr = 0;
    while (clust[fr] != -1) ++fr;

    vpi op;
    int k = 0;
    rep(i, m) {
        rep(j, sz(files[i])) {
            if (files[i][j] == k) {
                ++k;
                continue;
            }

            int from = files[i][j];
            if (fr == k) {
                op.emplace_back(from, k);
                clust[k] = i;
                clust[from] = -1;
                files[i][j] = k;
                fr = from;
                ++k;
                continue;
            }

            int clust_away = clust[k];

            op.emplace_back(k, fr);
            op.emplace_back(from, k);

            clust[from] = -1;
            clust[k] = i;
            clust[fr] = clust_away;

            files[i][j] = k;
            replace(all(files[clust_away]), k, fr);

            fr = from;
            ++k;
        }
    }

    cout << sz(op) << '\n';
    for (auto& [a, b] : op)
        cout << (a + 1) << ' ' << (b + 1) << '\n';

    return 0;
}