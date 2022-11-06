#include <bits/stdc++.h>

// Contest: Educational Codeforces Round 79 (Rated for Div. 2) (https://codeforces.com/contest/1279)
// Problem: D: Santa's Bot (https://codeforces.com/contest/1279/problem/D)

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

const ll M = 998244353;

ll mod_pow(ll b, ll e) {
    ll r = 1;
    while (e) {
        if (e % 2)
            r = (r * b) % M;
        b = b * b % M;
        e /= 2;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vl inv(1'000'001);
    rep(i, 1'000'001) inv[i] = mod_pow(i, M - 2);
    ll p = 0;
    vvi a(n);
    vi childs(1'000'001);
    rep(i, n) {
        int k; cin >> k;
        a[i].resize(k);
        rep(j, k)
            cin >> a[i][j], --a[i][j], childs[a[i][j]]++;
    }

    rep(i, n) {
        auto k = sz(a[i]);
        rep(j, k) {
            p += inv[n] * inv[k] % M * childs[a[i][j]] % M * inv[n] % M;
            p %= M;
        }
    }

    cout << p << '\n';
    return 0;
}