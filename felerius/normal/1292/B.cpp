#include <bits/stdc++.h>

// Contest: Codeforces Round #614 (Div. 1) (https://codeforces.com/contest/1292)
// Problem: B: Aroma's Search (https://codeforces.com/contest/1292/problem/B)

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
ll MX = 30000000000000000ll;

ll dist(pl a, pl b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x0, y0, ax, ay, bx, by; cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t; cin >> xs >> ys >> t;
    pl s = {xs, ys};

    vector<pl> nodes = {{x0, y0}};
    while (nodes.back().first < MX && nodes.back().second < MX) {
        nodes.emplace_back(nodes.back().first * ax + bx, nodes.back().second * ay + by);
    }

    int n = sz(nodes), mx = 0;
    rep(i, n) {
        ll d1 = dist(nodes[i], s), d2 = d1;
        int j = i, k = i;
        while (j >= 0 && d1 <= t) {
            --j;
            if (j >= 0)
                d1 += dist(nodes[j], nodes[j + 1]);
        }
        while (k < n && d2 <= t) {
            ++k;
            if (k < n)
                d2 += dist(nodes[k], nodes[k - 1]);
        }
        mx = max({mx, i - j, k - i});
    }

    cout << mx << '\n';
    return 0;
}