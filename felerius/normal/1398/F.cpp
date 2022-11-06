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

    int n; cin >> n;
    string s; cin >> s;

    int i = 0;
    while (i < n) {
        if (s[i] != '?') {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && s[j] == '?')
            ++j;
        if (i == 0 || j == n || s[i-1] == s[j]) {
            if (i == 0 && j == n) {
                reps(x, 1, n + 1)
                    cout << (n / x) << ' ';
                cout << '\n';
                return 0;
            }
            char c = i == 0 ? s[j] : s[i-1];
            reps(k, i, j)
                s[k] = c;
        }
        i = j;
    }

    using Block = array<int, 4>;
    vector<Block> blocks;
    i = 0;
    while (i < n) {
        int j = i;
        while (j < n && s[j] == '?')
            ++j;
        int k = j;
        while (k < n && s[k] == s[j])
            ++k;
        int l = k;
        while (l < n && s[l] == '?')
            ++l;
        blocks.push_back({i, j - i, k - j, l - k});
        i = k;
    }

    vector<Block> blocks_next;
    reps(x, 1, n + 1) {
        blocks_next.clear();
        auto it = begin(blocks);
        int used = 0, used_i = -1, cnt = 0;
        while (it != end(blocks)) {
            auto [idx, bef, mid, aft] = *it++;
            if (bef + mid + aft >= x)
                blocks_next.push_back({idx, bef, mid, aft});

            int w = bef + mid + aft;
            if (used_i == idx)
                w -= used;
            cnt += w / x;

            int rem = min(aft, w % x);
            used = aft - rem;
            used_i = idx + bef + mid;
        }

        cout << cnt << ' ';
        swap(blocks, blocks_next);
    }

    cout << '\n';
    return 0;
}