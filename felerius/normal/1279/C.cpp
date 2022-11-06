#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 79 (Rated for Div. 2) (https://codeforces.com/contest/1279)
// Problem: C: Stack of Presents (https://codeforces.com/contest/1279/problem/C)

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

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vi a(n), b(m);
        trav(ai, a) cin >> ai, --ai;
        trav(bi, b) cin >> bi, --bi;

        vi pos(n);
        rep(i, n)
            pos[a[i]] = i;
        int ns = 0;
        ll op = 0;
        rep(i, m) {
            if (pos[b[i]] < ns)
                ++op;
            else
                ns = pos[b[i]] + 1, op += 2 * pos[b[i]] + 1 - 2 * i;
        }

        cout << op << '\n';
    }

    return 0;
}