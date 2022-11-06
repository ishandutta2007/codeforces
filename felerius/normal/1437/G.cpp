
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
#   define all(a)      ::begin(a),::end(a)
#   define sz(x)       ((int)::size(x))
#else
#   define all(a)      (a).begin(),(a).end()
#   define sz(x)       ((int)(x).size())
#endif

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep0(i, r)       for (int i = 0; i < r; ++i)
#define _repn(i, l, r)    for (int i = l; i < r; ++i)
#define _repr0(i, r)      for (int i = r; i >= 0; --i)
#define _reprn(i, r, l)   for (int i = r; i >= l; --i)
#define rep(...)          _choose(__VA_ARGS__, _repn, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _reprn, _repr0, suppress_warning)(__VA_ARGS__)
#define trav(a, b)        for(auto& a : b)

using ll = long long;
using ld = long double;

#if __cplusplus >= 201703L
#   define MAYBE_UNUSED [[maybe_unused]]
#else
#   define MAYBE_UNUSED
#endif

MAYBE_UNUSED static constexpr int INF = (int)1e9 + 5;
MAYBE_UNUSED static constexpr ll INFL = (ll)INF * INF;
MAYBE_UNUSED static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());

namespace cp_lib {}


namespace cp_lib {
    template <size_t K>
    struct AhoCorasickNode {
        array<int, K> next;
        AhoCorasickNode() { next.fill(-1); }
    };

    template <class Node>
    struct AhoCorasick {
     private:
        vector<Node> d = {Node()};

     public:
        Node& operator[](size_t i) { return d[i]; }
        const Node& operator[](size_t i) const { return d[i]; }

        template <class Iter, class F>
        int add(Iter it, Iter end, F f) {
            int v = 0;
            while (it != end) {
                int i = f(*it++);
                if (d[v].next[i] == -1)
                    d[v].next[i] = sz(d), d.emplace_back();
                v = d[v].next[i];
            }
            return v;
        }

        int add(string_view s, char base) {
            return add(all(s), [&](char c) { return c - base; });
        }

        void finalize() {
            if (!sz(d)) return;
            queue<array<int, 4>> q;
            q.push({0, -1, -1, -1});
            while (sz(q)) {
                auto [v, c, p, plink] = q.front(); q.pop();
                int link = (!v || !p ? 0 : d[plink].next[c]);
                if (v)
                    d[v].finalize(*this, c, link, p);
                rep(i, sz(d[v].next)) {
                    if (d[v].next[i] == -1)
                        d[v].next[i] = (v ? d[link].next[i] : 0);
                    else
                        q.push({d[v].next[i], i, v, link});
                }
            }
        }
    };
}

using namespace cp_lib;

struct AcNode : AhoCorasickNode<26> {
    multiset<int> suspicions;
    int terminal_link = 0;

    void finalize(const AhoCorasick<AcNode>& ac, int, int link, int) {
        terminal_link = (sz(ac[link].suspicions) ? link : ac[link].terminal_link);
    }
};
using AhoCora = AhoCorasick<AcNode>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> sus(n), nodes(n);
    AhoCora ac;
    string s;
    rep(i, n) {
        cin >> s;
        nodes[i] = ac.add(s, 'a');
        ac[nodes[i]].suspicions.emplace(0);
    }
    ac.finalize();

    while (m--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int i, x; cin >> i >> x; --i;
            int v = nodes[i];
            ac[v].suspicions.erase(ac[v].suspicions.find(sus[i]));
            sus[i] = x;
            ac[v].suspicions.emplace(sus[i]);
        } else {
            cin >> s;
            int v = 0, mx = -1;
            trav(c, s) {
                v = ac[v].next[c - 'a'];
                int v2 = (sz(ac[v].suspicions) ? v : ac[v].terminal_link);
                while (v2)
                    mx = max(mx, *rbegin(ac[v2].suspicions)), v2 = ac[v2].terminal_link;
            }

            cout << mx << '\n';
        }
    }

    return 0;
}