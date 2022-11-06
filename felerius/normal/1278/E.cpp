#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 78 (Rated for Div. 2) (https://codeforces.com/contest/1278)
// Problem: E: Tests for problem D (https://codeforces.com/contest/1278/problem/E)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define trav(a, b)  for(auto& a : b)

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = long long;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

[[maybe_unused]] const int INF = (int)1e9;
[[maybe_unused]] const ll INFL = (ll)1e18;

vvi adj;
using list_it = list<pair<int, bool>>::iterator;

pair<list_it, list_it> insert(int v, int p, list<pair<int, bool>>& l, list_it lit, list_it rit) {
    list_it nlit, rr;
    if (lit == end(l)) {
        nlit = l.insert(end(l), pair(v, false));
        rr = l.insert(end(l), pair(v, true));
    } else {
        nlit = l.insert(lit, pair(v, false));
        rr = l.insert(next(rit), pair(v, true));
    }
    auto nrit = nlit;
    trav(v2, adj[v]) {
        if (v2 == p)
            continue;
        tie(nlit, nrit) = insert(v2, v, l, nlit, nrit);
    }
    return {nlit, rr};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    adj.resize(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b; --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    list<pair<int, bool>> l;
    insert(0, -1, l, end(l), end(l));

    vpi seg(n, pair(-1, -1));
    auto it = begin(l);
    rep(i, 2 * n) {
        if (it->second)
            seg[it->first].second = i + 1;
        else
            seg[it->first].first = i + 1;
        ++it;
    }

    for (auto [l, r] : seg)
        cout << l << ' ' << r << '\n';

    return 0;
}