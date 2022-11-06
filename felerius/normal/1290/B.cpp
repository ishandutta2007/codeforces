// Contest: Codeforces Round #616 (Div. 1) (https://codeforces.com/contest/1290)
// Problem: B: Irreducible Anagrams (https://codeforces.com/contest/1290/problem/B)


// region {{{ boilerplate
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
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

#if __cpp_lib_nonmember_container_access >= 201411
#   define sz(x) ((int)size(x))
#else
#   define sz(x) ((int)(x).size())
#endif

#define rep(a, b)      for(int a = 0; a < (b); ++a)
#define reps(a, b, c)  for(int a = (b); a < (c); ++a)
#define all(a)         (a).begin(),(a).end()
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

#if __has_cpp_attribute(maybe_unused) >= 201603
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = sz(s);
    vector<array<int, 26>> next(n);
    next.back().fill(n);
    next.back()[s.back() - 'a'] = n - 1;
    for (int i = n-2; i >= 0; --i) {
        next[i] = next[i+1];
        next[i][s[i]-'a'] = i;
    }

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r; --l;
        if (s[l] != s[r-1] || l == r-1) {
            cout << "Yes\n";
            continue;
        }

        int c = 0;
        rep(i, 26)
            if (next[l][i] < r)
                ++c;
        cout << (c > 2 ? "Yes\n" : "No\n");
    }

    return 0;
}