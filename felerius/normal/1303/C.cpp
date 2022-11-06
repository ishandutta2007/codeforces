// Contest: Educational Codeforces Round 82 (Rated for Div. 2) (https://codeforces.com/contest/1303)
// Problem: C: Perfect Keyboard (https://codeforces.com/contest/1303/problem/C)


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

MAYBE_UNUSED static constexpr int INF = (int)1e9;
MAYBE_UNUSED static constexpr ll INFL = (ll)1e18;
//endregion }}}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<char> kb(100, '\0');
        kb[50] = s[0];
        int i = 50;
        bool pos = true;
        array<bool, 26> seen{};
        seen[s[0] - 'a'] = true;
        reps(j, 1, sz(s)) {
            char c = s[j];
            if (kb[i-1] == c)
                --i;
            else if (kb[i+1] == c)
                ++i;
            else if (kb[i-1] == '\0' && !seen[c - 'a'])
                --i, kb[i] = c;
            else if (kb[i+1] == '\0' && !seen[c - 'a'])
                ++i, kb[i] = c;
            else {
                pos = false;
                break;
            }
            seen[c - 'a'] = true;
        }

        if (!pos)
            cout << "NO\n";
        else {
            int j = 0;
            while (kb[j] == '\0') ++j;
            cout << "YES\n";
            while (kb[j] != '\0')
                cout << kb[j++];
            rep(k, 26)
                if (!seen[k])
                    cout << ((char)('a' + k));
            cout << '\n';
        }
    }

    return 0;
}