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

struct CompressedString {
    array<char, 10> d;
    bool increasing = false;
    int len = 0;

    CompressedString() { d.fill(' '); }

    char front() {
        return len < 10 ? d[10 - len] : d[0];
    }

    void prepend(char c) {
        if (len && c != front())
            increasing = (c < front());

        if (len < 10)
            d[10 - ++len] = c;
        else {
            if (len == 10)
                d[5] = d[6] = d[7] = '.';
            rotate(begin(d), begin(d) + 4, begin(d) + 5);
            d[0] = c;
            ++len;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = sz(s);
    vector<CompressedString> res(n + 1);

    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n && s[i] == s[i+1]) {
            res[i] = res[i+2];
            if (res[i].len && (s[i] < res[i].front() || (s[i] == res[i].front() && res[i].increasing)))
                res[i].prepend(s[i]), res[i].prepend(s[i]);
        } else {
            res[i] = res[i+1];
            res[i].prepend(s[i]);
        }
    }

    rep(i, n) {
        cout << res[i].len << ' ';
        reps(j, max(0, 10 - res[i].len), 10)
            cout << res[i].d[j];
        cout << '\n';
    }

    return 0;
}