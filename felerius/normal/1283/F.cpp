#include <bits/stdc++.h>

// Contest: Codeforces Round #611 (Div. 3) (https://codeforces.com/contest/1283)
// Problem: F: DIY Garland (https://codeforces.com/contest/1283/problem/F)

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

    vector<bool> known(n);
    int root; cin >> root; --root;
    int last = root;
    int path_to = root == n - 1 ? n - 2 : n - 1;
    known[root] = true;
    vpi e;
    rep(_, n - 2) {
        int v; cin >> v; --v;
        if (known[v] || v == path_to) {
            e.emplace_back(last, path_to);
            known[path_to] = true;
            while (known[path_to]) --path_to;
            last = v;
        } else {
            e.emplace_back(last, v);
            last = v;
            known[v] = true;
        }
    }

    e.emplace_back(last, path_to);
    cout << (root + 1) << '\n';
    for (auto [a, b] : e)
        cout << (a+1) << ' ' << (b+1) << '\n';

    return 0;
}