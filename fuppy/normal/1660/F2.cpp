/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/convolution>

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
vi dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
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

template <typename T>
class SegmentTree {
  public:
    using F = function<T(T &, T &)>;
    int n;
    vector<T> dat;
    T e;
    F query_func;
    F update_func;

    SegmentTree(vector<T> a, F query_func, F update_func, T e) : n(a.size()), query_func(query_func), update_func(update_func), e(e) {
        if (n == 0) {
            a.push_back(e);
            n++;
        }
        dat.resize(4 * n);
        init(0, 0, n, a);
    }

    void init(int k, int l, int r, vector<T> &a) {
        if (r - l == 1) {
            dat[k] = a[l];
        } else {
            int lch = 2 * k + 1, rch = 2 * k + 2;
            init(lch, l, (l + r) / 2, a);
            init(rch, (l + r) / 2, r, a);
            dat[k] = query_func(dat[lch], dat[rch]);
        }
    }

    void update(int k, T a, int v, int l, int r) {
        if (r - l == 1) {
            dat[v] = update_func(dat[v], a);
        } else {
            if (k < (l + r) / 2)
                update(k, a, 2 * v + 1, l, (l + r) / 2);
            else {
                update(k, a, 2 * v + 2, (l + r) / 2, r);
            }
            dat[v] = query_func(dat[v * 2 + 1], dat[v * 2 + 2]);
        }
    }

    void update(int k, T a) {
        update(k, a, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return e;
        }
        if (a <= l && r <= b) {
            return dat[k];
        } else {
            T ul = query(a, b, k * 2 + 1, l, (l + r) / 2);
            T ur = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return query_func(ul, ur);
        }
    }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    int find(int a, int b, int k, int l, int r, int x) {
        if (dat[k] < x || r <= a || b <= l) return -1;
        if (l + 1 == r) {
            if (dat[k] >= x)
                return l;
            else
                return -1;
        }
        int rv = find(a, b, 2 * k + 2, (l + r) / 2, r, x);
        if (rv != -1) return rv;
        return find(a, b, 2 * k + 1, l, (l + r) / 2, x);
    }
};

int f(int a, int b) { return a + b; }
int g(int a, int b) { return a + b; }

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    ll ans = 0;
    vector<SegmentTree<int>> seg;
    int m = 2 * n + 1;
    rep(i, 3) {
        seg.push_back(SegmentTree<int>(vi(m), f, g, 0));
    }

    int su = 0;
    seg[0].update(n, 1);
    rep(i, n) {
        if (s[i] == '-')
            su++;
        else
            su--;

        int idx = (su % 3 + 3) % 3;
        ans += seg[idx].query(0, su + n + 1);

        seg[idx].update(su + n, 1);
    }
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}