// Contest: Codeforces Round #617 (Div. 3) (https://codeforces.com/contest/1296)
// Problem: E1: String Coloring (easy version) (https://codeforces.com/contest/1296/problem/E1)


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

    int n; cin >> n;
    string s; cin >> s;

    vvi adj(n);
    rep(i, n) reps(j, i + 1, n)
        if (s[i] > s[j])
            adj[i].push_back(j), adj[j].push_back(i);

    vi c(n, -1);
    rep(i, n) {
        if (c[i] != -1)
            continue;
        queue<int> q;
        c[i] = 0;
        q.push(i);
        while (sz(q)) {
            auto v = q.front(); q.pop();
            for (auto v2 : adj[v]) {
                if (c[v2] == -1)
                    c[v2] = 1 - c[v], q.push(v2);
                else if (c[v] == c[v2])
                    cout << "NO\n", exit(0);
            }
        }
    }

    cout << "YES\n";
    trav(ci, c)
        cout << ci;
    cout << '\n';

    return 0;
}