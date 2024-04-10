/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/string>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
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
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
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

ll and_ask(ll i, ll j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    ll res;
    cin >> res;
    return res;
}

ll or_ask(ll i, ll j) {
    cout << "or " << i + 1 << " " << j + 1 << endl;
    ll res;
    cin >> res;
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vi a(n);

    ll and01, or01;
    ll and02, or02;
    ll and12, or12;
    and01 = and_ask(0, 1);
    or01 = or_ask(0, 1);
    and02 = and_ask(0, 2);
    or02 = or_ask(0, 2);
    and12 = and_ask(1, 2);
    or12 = or_ask(1, 2);

    ll mask = 1LL << 40;

    while (mask > 0) {
        auto f = [=](ll x) {
            return (bool)(x & mask);
        };
        if (!f(or01) && !f(or02) && !f(or12)) {
        } else if (f(and01) && f(and02) && f(and12)) {
            rep(i, 3) a[i] |= mask;
        } else if (!f(and01) && !f(and02) && !f(and12)) {
            if (!f(or01)) {
                a[2] |= mask;
            } else if (!f(or02)) {
                a[1] |= mask;

            } else if (!f(or12)) {
                a[0] |= mask;
            }
        } else {
            if (f(and01)) {
                a[0] |= mask;
                a[1] |= mask;
            } else if (f(and02)) {
                a[0] |= mask;
                a[2] |= mask;
            } else if (f(and12)) {
                a[1] |= mask;
                a[2] |= mask;
            }
        }

        mask >>= 1;
    }

    for (int i = 3; i < n; i++) {
        ll an = and_ask(0, i);
        ll o = or_ask(0, i);

        ll mask = 1LL << 40;
        while (mask > 0) {
            if (a[0] & mask) {
                if (an & mask) a[i] |= mask;
            } else {
                if (o & mask) a[i] |= mask;
            }
            mask >>= 1;
        }
    }
    // DEBUG_VEC(a);
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}