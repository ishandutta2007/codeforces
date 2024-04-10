#include <bits/stdc++.h>

// Contest: Codeforces Round #611 (Div. 3) (https://codeforces.com/contest/1283)
// Problem: D: Christmas Trees (https://codeforces.com/contest/1283/problem/D)

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
    vi x(n);
    trav(xi,x) cin >> xi;

    set<int> occ;
    queue<pi> q;
    rep(i, n)
        q.emplace(i, -1), q.emplace(i, 1), occ.emplace(x[i]);

    vi pos;
    ll s = 0;
    for (int d = 1; m; ++d) {
        int qs = sz(q);
        for (int k = 0; k < qs && m; ++k) {
            assert(!q.empty());
            auto [i, dir] = q.front(); q.pop();
            if (occ.find(x[i] + d * dir) != end(occ))
                continue;
            s += d;
            occ.emplace(x[i] + d * dir);
            pos.push_back(x[i] + d * dir);
            q.emplace(i, dir);
            --m;
        }
    }

    cout << s << '\n';
    trav(p, pos) cout << p << ' ';
    cout << '\n';

    return 0;
}