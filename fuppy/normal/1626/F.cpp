/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/maxflow>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                                \
    cerr << #v << endl;                             \
    for (int iv = 0; iv < v.size(); iv++) {         \
        for (int jv = 0; jv < v[iv].size(); jv++) { \
            cerr << v[iv][jv] << " ";               \
        }                                           \
        cerr << endl;                               \
    }
typedef long long ll;
#define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

ll gcd(ll a, ll b) {
    if (b > a) {
        swap(a, b);
    }
    if (b == 0) return a;
    ll r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

signed main() {
    // map<ll, int> st;
    // rep(i, 1 << 16) {
    //     ll mul = 1;
    //     rep(k, 16) {
    //         if (i & (1 << k)) {
    //             mul = lcm(mul, k + 1);
    //         }
    //     }
    //     st[mul]++;
    //     // st.insert(mul);
    // }
    // DEBUG(st.size());
    // for (auto [x, n] : st) {
    //     cout << x << " " << n << endl;
    // }

    ll n, a0, x, y, k, M;
    cin >> n >> a0 >> x >> y >> k >> M;

    vl a(n);
    a[0] = a0;
    for (int i = 1; i < n; i++) {
        a[i] = (a[i - 1] * x + y) % M;
    }
    // DEBUG_VEC(a);

    ll ma = 1;
    rep1(x, k - 1) ma = lcm(ma, x);

    vector<pll> dp(ma), ndp(ma);
    rep(i, n) {
        (dp[a[i] % ma].first += a[i]) %= MOD;
        dp[a[i] % ma].second += 1;
    }

    vl ps(k + 1);
    ps[0] = 1;
    rep(i, k) ps[i + 1] = ps[i] * n % MOD;

    // DEBUG_VEC(dp);
    ll ans = 0;
    rep1(i, k) {
        fill(all(ndp), pll(0, 0));

        rep(j, ma) {
            // not choose
            (ndp[j].first += dp[j].first * (n - 1)) %= MOD;
            (ndp[j].second += dp[j].second * (n - 1)) %= MOD;

            // choose
            ans += dp[j].first * ps[k - i] % MOD;
            ll ha = j % i;
            ll nj = j - ha;
            (ndp[nj].first += dp[j].first - ha * dp[j].second) %= MOD;
            (ndp[nj].second += dp[j].second) %= MOD;
        }
        // DEBUG_VEC(ndp);
        swap(dp, ndp);
    }
    cout << (ans % MOD + MOD) % MOD << endl;
}