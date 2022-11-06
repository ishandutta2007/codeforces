// Contest: Codeforces Round #636 (Div. 3) (https://codeforces.com/contest/1343)
// Problem: F: Restore the Permutation by Sorted Segments (https://codeforces.com/contest/1343/problem/F)


// region {{{ boilerplate
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
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<bitset<200>> a(n - 1);
        rep(i, n - 1) {
            int k, ki; cin >> k;
            while (k--)
                cin >> ki, --ki, a[i][ki] = true;
        }
        rep(i, n) {
            auto b = a;
            vi p(n);
            p[0] = i;
            rep(j, n - 1) {
                int x = -1;
                rep(y, n - 1) {
                    b[y][p[j]] = false;
                    if (b[y].count() == 1) {
                        if (x == -1)
                            x = y;
                        else {
                            x = -1;
                            break;
                        }
                    }
                }
                if (x == -1)
                    break;
                while (!b[x][p[j + 1]])
                    p[j + 1]++;
            }

            unordered_set<bitset<200>> c(all(a));
            bool valid = true;
            reps(j, 1, n) {
                bitset<200> bs;
                bs[p[j]] = true;
                bool found = false;
                for (int k = j - 1; !found && k >= 0; --k) {
                    bs[p[k]] = true;
                    auto it = c.find(bs);
                    if (it != end(c))
                        found = true, c.erase(it);
                }
                valid &= found;
                if (!valid) break;
            }
            if (valid) {
                trav(pi, p)
                    cout << (pi + 1) << ' ';
                cout << '\n';
                break;
            }
        }
    }

    return 0;
}