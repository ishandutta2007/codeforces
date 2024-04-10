//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

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

template <typename OperatorMonoid>
struct DuelSegmentTree {
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height;
    vector<OperatorMonoid> lazy;
    const H h;
    const OperatorMonoid OM0;

    DuelSegmentTree(int n, const H h, const OperatorMonoid OM0)
        : h(h), OM0(OM0) {
        sz = 1;
        height = 0;
        while (sz < n)
            sz <<= 1, height++;
        lazy.assign(2 * sz, OM0);
    }

    inline void propagate(int k) {
        if (lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            lazy[k] = OM0;
        }
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--)
            propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
    }

    OperatorMonoid operator[](int k) {
        thrust(k += sz);
        return lazy[k];
    }
};

ll f(ll a, ll b) { return a + b; }

void solve() {
    int n, q;
    cin >> n >> q;
    set<pii> thre;
    thre.insert(pii(n, 0));
    vl add(n);
    DuelSegmentTree<ll> seg(n, f, 0);

    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 'C') {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            c--;

            int now = l;
            auto itr = thre.lower_bound(pii(now, -inf));

            bool ins = true;
            if (itr->first == now) {
                ins = false;
                itr++;
            }

            bool fir = true;
            ll ini_col;
            while (now < r) {
                auto [nex, col] = *itr;
                if (fir) {
                    ini_col = col;
                    fir = false;
                }

                if (nex < r) {
                    seg.update(now, nex, add[col]);
                    now = nex;
                    itr = thre.erase(itr);
                } else {
                    seg.update(now, r, add[col]);
                    now = nex;

                    if (now == r) {
                        thre.erase(itr);
                    }
                }
            }

            if (ins) {
                thre.insert(pll(l, ini_col));
            }
            thre.insert(pll(r, c));

            seg.update(l, r, -add[c]);
        } else if (s[0] == 'A') {
            int c, x;
            cin >> c >> x;
            c--;
            add[c] += x;
        } else {
            int i;
            cin >> i;
            i--;
            auto itr = thre.lower_bound(pii(i + 1, -inf));
            int col = itr->second;

            cout << seg[i] + add[col] << endl;
        }
    }
}

signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}