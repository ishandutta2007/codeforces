//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/maxflow>
// #include <atcoder/lazysegtree>

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
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
// struct Setup_io {
//     Setup_io() {
//         ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//         cout << fixed << setprecision(25);
//     }
// } setup_io;
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

struct dice {
    mt19937 mt;
    dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    // [0, x)
    ll operator()(ll x) { return this->operator()(0, x); }
    // [x, y)
    ll operator()(ll x, ll y) {
        uniform_int_distribution<ll> dist(x, y - 1);
        return dist(mt);
    }
    vl operator()(int n, ll x, ll y) {
        vl res(n);
        for (int i = 0; i < n; i++)
            res[i] = this->operator()(x, y);
        return res;
    }
} rnd;

// https://ei1333.github.io/algorithm/sparse-table.html
template <typename T>
struct SparseTable {
    vector<vector<T>> st;
    using F = function<T(T &, T &)>;
    F f;

    SparseTable() {}

    SparseTable(const vector<T> &v, const F &f) : f(f) {
        int b = 0;
        while ((1 << b) <= v.size())
            ++b;
        st.assign(b, vector<T>(1 << b));
        for (int i = 0; i < v.size(); i++) {
            st[0][i] = v[i];
        }
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <= (1 << b); j++) {
                st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    inline T query(int l, int r) // [l, r)
    {
        int b = 32 - __builtin_clz(r - l) - 1;
        return (f(st[b][l], st[b][r - (1 << b)]));
    }
};

int f(int a, int b) {
    return a + b;
}

void solve() {
    int n, c;
    cin >> n >> c;

    // n = rnd(1, 30);
    // c = rnd(1, 100);

    vi exi(c + 1);
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        // a[i] = rnd(1, c + 1);
        exi[a[i]] = true;
    }
    sort(all(a));
    UNIQUE(a);

    n = a.size();

    if (a[0] != 1) {
        No();
        return;
    }

    SparseTable<int> spa(exi, f);

    for (int i = 1; i < n; i++) {
        int x = a[i];

        auto itr = lower_bound(all(a), 2 * x);
        for (int tar = 2; tar * x <= c; tar++) {
            int l = x * tar, r = x * (tar + 1);
            r = min(r, c + 1);

            int s = spa.query(l, r);
            if (s == 0) {
                continue;
            }

            if (!exi[tar]) {
                No();
                return;
            }
        }
        // int tar = 1;
        // int r = i;

        // while (r < n) {
        //     int l = r;
        //     while (r < n && a[r] / x == tar) {
        //         r++;
        //     }
        //     if (l == r) {
        //         tar++;
        //         continue;
        //     }

        //     if (!exi[tar]) {
        //         No();
        //         return;
        //     }
        //     tar++;
        // }
    }
    Yes();
}

signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}