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

bool isprime(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int ask(char c, int x) {
    cout << c << ' ' << x << '\n';
    cout.flush();
    int r; cin >> r;
    return r;
}

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    if (n == 1)
        cout << "C 1\n", exit(0);

    vi p;
    reps(i, 2, n + 1)
        if (isprime(i))
            p.push_back(i);
    reverse(all(p));

    int rem = n;
    while ((ll)p.back() * p.back() <= n) {
        rem -= ask('B', p.back());
        if (ask('A', 1) != rem) {
            int r = p.back();
            trav(pi, p) {
                while ((ll)r * pi <= n) {
                    if (!ask('A', r * pi))
                        break;
                    r *= pi;
                }
            }
            cout << "C " << r << '\n';
            return 0;
        }
        p.pop_back();
    }

    while (sz(p) > 1) {
        int m = sz(p) / 2;
        rep(i, m)
            ask('B', p[i]);
        rem -= m;
        if (ask('A', 1) != rem) {
            rep(i, m)
                if (ask('A', p[i]))
                    cout << "C " << p[i] << '\n', exit(0);
        }
        p.erase(begin(p), begin(p) + m);
    }

    ask('B', p[0]);
    int ans = (ask('A', p[0]) ? p[0] : 1);
    cout << "C " << ans << '\n';
    return 0;
}