#include <bits/stdc++.h>

// Contest: Codeforces Global Round 6 (https://codeforces.com/contest/1266)
// Problem: D: Decreasing Debts (https://codeforces.com/contest/1266/problem/D)

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<pl> b(n);
    rep(i, n) b[i].second = i;
    rep(i, m) {
        int u, v, d; cin >> u >> v >> d; --u, --v;
        b[u].first -= d, b[v].first += d;
    }

    sort(all(b));
    vector<tuple<int, int, ll>> e;
    int i = 0, j = n - 1;
    while (b[i].first < 0) {
        ll mn = min(-b[i].first, b[j].first);
        e.emplace_back(b[i].second, b[j].second, mn);
        if (!(b[i].first += mn)) ++i;
        if (!(b[j].first -= mn)) --j;
    }

    cout << sz(e) << '\n';
    for (auto [i, j, d] : e)
        cout << ++i << ' ' << ++j << ' ' << d << '\n';

    return 0;
}