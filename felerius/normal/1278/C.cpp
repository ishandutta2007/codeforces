#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 78 (Rated for Div. 2) (https://codeforces.com/contest/1278)
// Problem: C: Berry Jam (https://codeforces.com/contest/1278/problem/C)

using namespace std;

#define sz(x)       (int)size(x)
#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define reps(a, b, c)   for(int a = (b); a < (c); ++a)
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
        int n; cin >> n;
        vi a(2 * n);
        trav(ai, a) cin >> ai;
        vi md(2 * n + 1, INF);
        int d = 0;
        md[n] = n;
        rep(i, n) {
            d += a[i] == 1 ? 1 : -1;
            md[d + n] = min(md[d + n], n - (i + 1));
        }
        int mn = n + md[n];
        d = 0;
        rep(i, n) {
            d += a[2 * n - i - 1] == 1 ? 1 : -1;
            mn = min(mn, n - (i + 1) + md[-d + n]);
        }

        cout << mn << '\n';
    }

    return 0;
}