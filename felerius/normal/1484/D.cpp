// Playlist (https://codeforces.com/contest/1484/problem/D)
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

struct Entry {
    int val, prev, next;
    bool del = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<Entry> l(n);
        rep(i, n) {
            cin >> l[i].val;
            l[i].prev = (i - 1 + n) % n;
            l[i].next = (i + 1) % n;
        }

        queue<pair<int, int>> q;
        rep(i, 1, n + 1) {
            int j = i % n;
            if (gcd(l[j].val, l[l[j].prev].val) == 1)
                q.emplace(l[j].prev, j);
        }

        vector<int> ans;
        while (sz(q)) {
            auto [prev, i] = q.front(); q.pop();
            if (l[i].del || l[i].prev != prev)
                continue;
            ans.push_back(i);
            int next = l[i].next;
            l[i].del = true;
            l[prev].next = next;
            l[next].prev = prev;
            if (gcd(l[prev].val, l[next].val) == 1)
                q.emplace(prev, next);
        }

        cout << sz(ans);
        trav(i, ans)
            cout << ' ' << (i + 1);
        cout << '\n';
    }

    return 0;
}