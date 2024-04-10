// Min Cost String (https://codeforces.com/contest/1511/problem/D)
// begin "cp-lib/boilerplate.hpp"
#include <bits/stdc++.h>

#define _choose(_1, _2, _3, chosen, ...) chosen
#define _rep(i, l, r)     for (int i = l; i < r; ++i)
#define _rep0(i, r)       _rep(i, 0, r)
#define _repr(i, r, l)    for (int i = r; i >= l; --i)
#define _repr0(i, r)      _repr(i, r, 0)
#define rep(...)          _choose(__VA_ARGS__, _rep, _rep0, suppress_warning)(__VA_ARGS__)
#define repr(...)         _choose(__VA_ARGS__, _repr, _repr0, suppress_warning)(__VA_ARGS__)
#define all(a)      ::begin(a),::end(a)
#define sz(c)       int(::size(c))
#define trav(a, b)  for(auto& a : b)

using namespace std;

using ll = long long;
using ld = long double;
using u64 = uint64_t;
using u32 = uint32_t;

[[maybe_unused]] static constexpr int INF = int(1e9 + 5);
[[maybe_unused]] static constexpr ll INFL = ll(INF) * INF;
[[maybe_unused]] static mt19937 rng(u32(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count()));

namespace cp_lib {}
// end "cp-lib/boilerplate.hpp"

using namespace cp_lib;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    vector adj(k, vector<int>());
    rep(i, k) rep(j, k)
        adj[i].push_back(j);

    vector<int> st = {0};
    vector idx(k, 0);
    string s;
    while (sz(st)) {
        int v = st.back(); st.pop_back();
        if (idx[v] == sz(adj[v])) {
            s.push_back(char('a' + v));
        } else {
            st.push_back(v);
            st.push_back(adj[v][idx[v]]);
            idx[v]++;
        }
    }

    s.pop_back();
    while (n >= sz(s))
        cout << s, n -= sz(s);
    rep(i, n)
        cout << s[i];
    cout << '\n';

    return 0;
}