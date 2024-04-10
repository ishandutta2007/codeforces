#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 78 (Rated for Div. 2) (https://codeforces.com/contest/1278)
// Problem: F: Cards (https://codeforces.com/contest/1278/problem/F)

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

ll M = 998244353;

int mod_pow(ll b, ll e) {
    ll res = 1;
    for (; e; b = b * b % M, e /= 2)
        if (e % 2) res = res * b % M;
    return (int)res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vi f(k + 1), fi(k + 1), fn(k + 1);
    f[0] = 1;
    reps(i, 1, k + 1) f[i] = (ll)f[i - 1] * i % M;
    rep(i, k + 1) fi[i] = mod_pow(f[i], M - 2);
    fn[0] = 1;
    reps(i, 1, k + 1) fn[i] = fn[i - 1] * (ll)(n - i + 1) % M;
    auto choose = [&](int n, int k) {
        if (k > n)
            return 0ll;
        return (ll)f[n] * fi[n - k] % M * (ll)fi[k] % M;
    };
    auto choose_n = [&](int k) {
        return fn[k] * (ll)fi[k] % M;
    };
    ll sum = 0;
    auto p = mod_pow(m, M - 2);
    auto q = (ll)(m - 1) * p % M;
    vi nmkitok(k + 1);
    rep(i, k + 1)
        nmkitok[i] = mod_pow(n - i, k);
    rep(j, k + 1) {
        ll si = 0;
        rep(ki, j + 1) {
            si += (ll)(ki % 2 ? M - 1 : 1) * choose(j, ki) % M * nmkitok[ki] % M;
            si %= M;
        }
        sum += mod_pow(M - q, j) * (ll)choose_n(j) % M * si % M;
        sum %= M;
    }

    cout << sum << '\n';
    return 0;
}