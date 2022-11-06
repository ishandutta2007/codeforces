// Contest: Codeforces Round #610 (Div. 2) (https://codeforces.com/contest/1282)
// Problem: D: Enchanted Artifact (https://codeforces.com/contest/1282/problem/D)


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

int ask(string_view s) {
    cout << s << '\n';
    int i; cin >> i;
    if (i <= 0)
        exit(0);
    return i;
}

int main() {
    ios::sync_with_stdio(false);

    int x = ask("a");
    if (x == 1) {
        int b = ask("ab");
        if (b == 2)
            ask("ba");
        else {
            ask("b");
            ask("aa");
        }
        assert(false);
    }

    if (x == 300)
        ask(string(300, 'b')), assert(false);

    int y = ask(string(x + 1, 'a'));
    if (y == x + 1)
        ask(string(x, 'b')), assert(false);

    int n = x + 1;
    string s(n, 'a');
    rep(i, n) {
        s[i] = 'b';
        int z = ask(s);
        if (z < y)
            y = z;
        else
            s[i] = 'a';
    }

    return 1;
}