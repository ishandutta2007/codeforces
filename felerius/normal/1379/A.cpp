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

int occ(string& s) {
    auto pos = s.find("abacaba");
    if (pos == string::npos)
        return 0;
    auto pos2 = s.find("abacaba", pos + 1);
    return pos2 == string::npos ? 1 : 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        auto o = occ(s);
        if (o == 1) {
            trav(c, s)
                if (c == '?')
                    c = 'd';
            cout << "Yes\n" << s << '\n';
            continue;
        } else if (o == 2) {
            cout << "No\n";
            continue;
        }

        bool done = false;
        rep(i, n - 6) {
            const char* want = "abacaba";
            bool can = true;
            rep(j, 7)
                can = can && (s[i+j] == '?' || s[i+j] == want[j]);
            if (!can)
                continue;
            string s2 = s;
            rep(j, 7)
                if (s[i+j] == '?')
                    s2[i+j] = want[j];
            trav(c, s2)
                if (c == '?')
                    c = 'd';
            if (occ(s2) == 1) {
                cout << "Yes\n" << s2 << '\n';
                done = true;
                break;
            }
        }
        if (!done)
            cout << "No\n";
    }

    return 0;
}