/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/modint>

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

template <typename T1, typename T2>
class LazySegmentTree {
  public:
    using F = function<T1(T1 &, T1 &)>;           // query_func
    using G = function<T2(T2 &, T2 &)>;           // update_func
    using H = function<T1(T1 &, T2 &, int, int)>; // lazy to node (node, lazy, left, right)
    int n;
    vector<T1> node;
    vector<T2> lazy;
    T1 e1;
    T2 e2;
    F query_func;
    G update_func;
    H eval_func;

    LazySegmentTree(vector<T1> a, F query_func, G update_func, H eval_func, T1 e1, T2 e2)
        : query_func(query_func), update_func(update_func), eval_func(eval_func), e1(e1), e2(e2) {
        int _n = a.size();
        n = 1;
        while (n < _n)
            n *= 2;
        node.resize(2 * n - 1, e1);
        lazy.resize(2 * n - 1, e2);
        for (int i = 0; i < _n; i++)
            node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--) {
            node[i] = query_func(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    inline void eval(int k, int l, int r) {
        if (lazy[k] != e2) { // Change
            node[k] = eval_func(node[k], lazy[k], l, r);
            if (r - l > 1) {
                lazy[2 * k + 1] = update_func(lazy[2 * k + 1], lazy[k]);
                lazy[2 * k + 2] = update_func(lazy[2 * k + 2], lazy[k]);
            }
            lazy[k] = e2; // Change
        }
    }

    void update(int a, int b, T2 x, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = update_func(lazy[k], x);
            eval(k, l, r);
        } else {
            update(a, b, x, 2 * k + 1, l, (l + r) / 2);
            update(a, b, x, 2 * k + 2, (l + r) / 2, r);
            node[k] = query_func(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    T1 query(int a, int b, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return e1;
        if (a <= l && r <= b) return node[k];
        T1 resl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        T1 resr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return query_func(resl, resr);
    }
};

int f(int a, int b) { return max(a, b); }
int g(int a, int b) { return a + b; }
int h(int a, int b, int l, int r) { return a + b; }

void solve(int n, int k, vi b) {
    vii a(n);

    rep(i, n * k) {
        b[i]--;
        int c = b[i];
        a[c].push_back(i);
    }

    LazySegmentTree<int, int> seg(vi(n * k), f, g, h, -inf, 0);

    int jou;
    if (n % (k - 1) == 0)
        jou = n / (k - 1);
    else
        jou = n / (k - 1) + 1;

    vi done(n);
    vi last(n, -1);
    vector<pii> ans(n);
    int cnt = 0;
    rep(i, n * k) {
        if (done[b[i]]) continue;
        int c = b[i];
        if (last[c] == -1) {
            last[c] = i;
            continue;
        }

        int l = last[c];
        int r = i + 1;
        int ma = seg.query(l, r, 0, 0, seg.n);
        if (ma == jou) {
            last[c] = i;
        } else {
            done[c] = true;
            cnt++;
            seg.update(l, r, 1, 0, 0, seg.n);
            ans[c] = pii(last[c], i);
        }
    }
    assert(cnt == n);

    for (pii lr : ans) {
        cout << lr.first + 1 << " " << lr.second + 1 << endl;
    }
}

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

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        // n = rnd(1, 100);
        // k = rnd(2, 100);
        vi a(n * k);
        // rep(i, n * k) a[i] = i % n + 1;

        // std::random_device seed_gen;
        // std::mt19937 engine(seed_gen());
        // std::shuffle(all(a), engine);
        rep(i, n * k) cin >> a[i];
        // DEBUG(n);
        // DEBUG(k);
        // DEBUG_VEC(a);

        solve(n, k, a);
    }
}