#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
ll mod = 1000000009;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
    ll res = 1;
    while (n) {
        if (n & 1)res = res * x % m;
        x = x * x % m; n >>= 1;
    }
    return res;
}
struct modint {
    ll n;
    modint() :n(0) { ; }
    modint(ll m) :n(m) {
        if (n >= mod)n %= mod;
        else if (n < 0)n = (n % mod + mod) % mod;
    }
    operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
    if (n == 0)return modint(1);
    modint res = (a * a) ^ (n / 2);
    if (n % 2)res = res * a;
    return res;
}

ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
    fact[0] = modint(1);
    for (int i = 0; i < max_n - 1; i++) {
        fact[i + 1] = fact[i] * modint(i + 1);
    }
    factinv[max_n - 1] = modint(1) / fact[max_n - 1];
    for (int i = max_n - 2; i >= 0; i--) {
        factinv[i] = factinv[i + 1] * modint(i + 1);
    }
}
modint comb(int a, int b) {
    if (a < 0 || b < 0 || a < b)return 0;
    return fact[a] * factinv[b] * factinv[a - b];
}

using mP = pair<modint, modint>;
mP mul(mP a, mP b) {
    return { a.first * b.first,a.second * b.first + a.first * b.second };
}
mP plu(mP a, mP b) {
    return { a.first + b.first,a.second + b.second };
}


mP dp[501];
bool used[501];
void init() {
    init_f();
    dp[0] = { 1,0 };
    dp[1] = { 2,0 };
    for (int n = 2; n <= 500; n++) {
        rep(j, n) {
            modint cnt = n + 1; modint sum = 0;
            rep(k, n)sum += abs(j - k);
            mP cl = dp[j];
            mP cr = dp[n - 1 - j];
            mP x = mul(cl, cr);
            x.first *= comb(n - 1, j);
            x.second *= comb(n - 1, j);
            x = mul(x, { cnt,sum });
            dp[n] = plu(dp[n], x);
        }
    }
}

mP dp2[502][501];
void solve() {
    int n, m; cin >> n >> m >> mod;
    init();
    dp2[0][0] = { 1,0 };
    rep(i, n) {
        rep(k, i + 1) {
            for (int j = i; j < n; j++) {
                int ni = j + 2; ni = min(ni, n);
                int nk = k + j - i + 1;
                if (nk <= m) {
                    mP x = mul(dp2[i][k], dp[j - i + 1]);
                    x.first *= comb(nk, k);
                    x.second *= comb(nk, k);
                    dp2[ni][nk] = plu(dp2[ni][nk], x);
                }
            }
            dp2[i + 1][k] = plu(dp2[i + 1][k], dp2[i][k]);
        }
    }
    modint ans = dp2[n][m].second;
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
     //init_f();
     //init();
     //expr();
     //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}