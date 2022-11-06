#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 78 (Rated for Div. 2) (https://codeforces.com/contest/1278)
// Problem: D: Segment Tree (https://codeforces.com/contest/1278/problem/D)

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

    int n; cin >> n;
    vpi seg(n);
    vector<tuple<int, int, int, bool>> evt;
    rep(i, n) {
        int l, r; cin >> l >> r; --l, --r;
        evt.emplace_back(l, r, i, false);
        evt.emplace_back(r, l, i, true);
    }
    sort(all(evt));

    vvi adj(n);
    set<pi> act;
    int m = 0;
    for (auto [x, x2, i, e] : evt) {
        if (e)
            act.erase(pair(x, i));
        else {
            auto it = begin(act);
            while (it != end(act) && it->first < x2) {
                if (++m > n - 1)
                    cout << "NO\n", exit(0);
                adj[i].push_back(it->second);
                adj[it->second].push_back(i);
                ++it;
            }
            act.emplace(x2, i);
        }
    }

    vi par(n, -1);
    queue<int> q;
    par[0] = 0;
    q.emplace(0);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (auto v2 : adj[v]) {
            if (v2 == par[v])
                continue;
            if (par[v2] != -1)
                cout << "NO\n", exit(0);
            par[v2] = v;
            q.emplace(v2);
        }
    }

    bool a = true;
    for (int p : par)
        a &= p != -1;
    cout << (a ? "YES\n" : "NO\n");

    return 0;
}