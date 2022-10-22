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
// #define int ll

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
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

const int MAXN = 3555550;

vl fact(MAXN);
vl rfact(MAXN);

ll mod_pow(ll x, ll p, ll M = MOD) {
    if (p < 0) {
        x = mod_pow(x, M - 2, M);
        p = -p;
    }
    x %= M;
    ll a = 1;
    while (p) {
        if (p % 2)
            a = a * x % M;
        x = x * x % M;
        p /= 2;
    }
    return a;
}

ll mod_inverse(ll a, ll M = MOD) {
    return mod_pow(a, M - 2, M);
}

void set_fact(ll n, ll M = MOD) {
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1] % M;
    }
    rfact[n] = mod_inverse(fact[n], M);
    for (ll i = n - 1; i >= 0; i--) {
        rfact[i] = (i + 1) * rfact[i + 1] % M;
    }
}

//http://drken1215.hatenablog.com/entry/2018/06/08/210000
ll nCr(ll n, ll r, ll M = MOD) {
    if (r > n) return 0;
    assert(fact[2] == 2);
    ll ret = fact[n];
    if (rfact[r] == 0) {
        rfact[r] = mod_inverse(fact[r], M);
    }
    ret = (ret * rfact[r]) % M;
    if (rfact[n - r] == 0) {
        rfact[n - r] = mod_inverse(fact[n - r], M);
    }
    ret = (ret * rfact[n - r]) % M;
    return ret;
}

ll nHr(ll n, ll r) {
    return nCr(n + r - 1, r);
}

const ll inv2 = mod_inverse(2);

ll memo[2011][2011];

ll f(int a, int s, ll k) {
    if (memo[a][s] != -1) {
        return memo[a][s];
    }

    if (a == 0) {
        return memo[a][s] = 0;
    }
    if (s == 0) {
        return memo[a][s] = k * a % MOD;
    }

    ll x = (f(a, s - 1, k) - f(a - 1, s, k)) % MOD * inv2 % MOD;
    // DEBUG(x);

    ll ans = memo[a - 1][s] + x;
    ans = (ans % MOD + MOD) % MOD;

    return memo[a][s] = ans;
}

ll solve1(int n, int m, int k) {
    int a = m, s = n - m;

    rep(i, a + 1) rep(j, s + 1) memo[i][j] = -1;

    memo[0][0] = 0;
    return f(a, s, k);
}

vl p2(MAXN), ip2(MAXN);

ll solve2(int n, int m, ll k) {
    ll a = m, s = n - m;

    if (s == 0) {
        return a * k % MOD;
    }

    ll ans = 0;
    for (ll y = 1; y <= a; y++) {
        ll val = y * k % MOD;

        ll toori = nCr(s - 1 + a - y, a - y);
        ll div = ip2[s + a - y];

        ans += val * toori % MOD * div % MOD;
    }
    return ans % MOD;
}

signed main() {
    int t;
    cin >> t;
    set_fact(3000000);
    p2[0] = 1;
    rep(i, 3000111) p2[i + 1] = p2[i] * 2 % MOD;
    ip2[3000111] = mod_inverse(p2[3000111]);
    for (int i = 3000110; i >= 0; i--) {
        ip2[i] = ip2[i + 1] * 2 % MOD;
    }

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // ll ans1 = solve1(n, m, k);
        // cout << ans1 << endl;
        ll ans2 = solve2(n, m, k);
        cout << ans2 << endl;
    }
}