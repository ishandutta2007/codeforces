// Contest: Codeforces Round #619 (Div. 2) (https://codeforces.com/contest/1301)
// Problem: E: Nanosoft (https://codeforces.com/contest/1301/problem/E)


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

template <class T, size_t... Is> struct arr_helper;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<typename arr_helper<T, Is...>::type, I>; };
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;

arr<int, 500, 500> up, dow, le, ri;
int n, m, q;
vector<string> g;
arr<int, 251, 499, 499> psum;

void calc_dirs() {
    rep(i, n) {
        char last = '\0'; int c = 0;
        rep(j, m) {
            if (g[i][j] == last)
                ++c;
            else
                last = g[i][j], c = 1;
            le[i][j] = c;
        }
    }

    rep(i, n) {
        char last = '\0'; int c = 0;
        for (int j = m - 1; j >= 0; --j) {
            if (g[i][j] == last)
                ++c;
            else
                last = g[i][j], c = 1;
            ri[i][j] = c;
        }
    }

    rep(j, m) {
        char last = '\0'; int c = 0;
        rep(i, n) {
            if (g[i][j] == last)
                ++c;
            else
                last = g[i][j], c = 1;
            up[i][j] = c;
        }
    }

    rep(j, m) {
        char last = '\0'; int c = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (g[i][j] == last)
                ++c;
            else
                last = g[i][j], c = 1;
            dow[i][j] = c;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    g.resize(n);
    trav(row, g) cin >> row;
    calc_dirs();

    auto outside = [&](int i, int j) { return i < 0 || i >= n || j < 0 || j >= m; };

    rep(i, n - 1) rep(j, m - 1) {
        reps(k, 1, min(n, m)) {
            int mni = i - k + 1, mxi = i + k;
            int mnj = j - k + 1, mxj = j + k;
            bool pos = true;
            if (outside(mni, mnj) || outside(mxi, mxj))
                pos = false;
            if (pos) {
                if (g[mni][mnj] != 'R' || dow[mni][mnj] < k || ri[mni][mnj] < k)
                    pos = false;
                if (g[mni][mxj] != 'G' || le[mni][mxj] < k || dow[mni][mxj] < k)
                    pos = false;
                if (g[mxi][mnj] != 'Y' || up[mxi][mnj] < k || ri[mxi][mnj] < k)
                    pos = false;
                if (g[mxi][mxj] != 'B' || le[mxi][mxj] < k || up[mxi][mxj] < k)
                    pos = false;
            }
            if (pos)
                psum[k][i][j] = 1;
            else {
                break;
            }
        }
    }

    rep(k, 251) {
        rep(i, n - 1) rep(j, m - 1) {
            if (i) psum[k][i][j] += psum[k][i-1][j];
            if (j) psum[k][i][j] += psum[k][i][j-1];
            if (i && j) psum[k][i][j] -= psum[k][i-1][j-1];
        }
    }

    auto eval = [&](int s, int i1, int i2, int j1, int j2) {  // inclusive!!
        int c = psum[s][i2][j2];
        if (i1) c -= psum[s][i1-1][j2];
        if (j1) c -= psum[s][i2][j1-1];
        if (i1 && j1) c += psum[s][i1-1][j1-1];
        return c > 0;
    };

    while (q--) {
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2; --i1, --i2, --j1, --j2;
        int l = 0, r = 251;
        while (r - l > 1) {
            int mi = (r + l) / 2;
            int ni1 = i1 + mi - 1, ni2 = i2 - mi;
            int nj1 = j1 + mi - 1, nj2 = j2 - mi;
            if (ni1 > ni2 || nj1 > nj2 || !eval(mi, ni1, ni2, nj1, nj2))
                r = mi;
            else
                l = mi;
        }
        cout << (4 *l * l) << '\n';
    }

    return 0;
}