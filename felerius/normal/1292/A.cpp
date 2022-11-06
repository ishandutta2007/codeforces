#include <bits/stdc++.h>

// Contest: Codeforces Round #614 (Div. 1) (https://codeforces.com/contest/1292)
// Problem: A: NEKO's Maze Game (https://codeforces.com/contest/1292/problem/A)

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

    int n, q; cin >> n >> q;
    set<pi> blockers;
    vector<arr<bool, 2>> s(n);
    while (q--) {
        int r, c; cin >> r >> c; --r, --c;
        s[c][r] = !s[c][r];
        for (int dc : {-1, 0, 1}) {
            int nc = c + dc;
            if (nc < 0 || nc == n)
                continue;
            if (s[nc][1 - r]) {
                pi p = r == 0 ? pair(c, nc) : pair(nc, c);
                if (s[c][r]) {
                    blockers.insert(p);
                } else {
                    blockers.erase(p);
                }
            }
        }
        cout << (blockers.empty() ? "Yes\n" : "No\n");
    }

    return 0;
}