//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>
// #include <atcoder/math>

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

class Bitset {
  public:
    using ull = unsigned long long;
    const int w = 64;

    int size;
    int n;
    int needless;
    vector<ull> bits;
    //  i  bit 
    vector<ull> large_mask;

    Bitset(int n_) : size(n_) {
        n = (n_ + w - 1) / w;
        bits.resize(n + 1);
        large_mask.resize(w + 1);
        for (int i = 1; i <= w; i++) {
            large_mask[i] = (large_mask[i - 1] >> 1) | (1ULL << (w - 1));
        }

        needless = large_mask[(w - n_ % w) % w];
    }

    bool get(int i) const {
        int i1 = i / w;
        int i2 = i - i1 * w;
        return bits[i1] & (1ULL << i2);
    }

    void set(int i) {
        int i1 = i / w;
        int i2 = i - i1 * w;
        bits[i1] |= 1ULL << i2;
    }

    void reset() {
        fill(all(bits), 0);
    }

    int count() {
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += __builtin_popcountll(bits[i]);
        }
        return res;
    }

    // i  bit  1 i -> i + 1
    void left_shift(int i) {
        int i1 = i / w;
        int i2 = i - i1 * w;

        for (int i = n - 1; i > i1; i--) {
            bool top = bits[i] & (1ULL << (w - 1));
            bits[i] <<= 1;
            if (top) {
                bits[i + 1] |= 1ULL;
            }
        }
        bool top = bits[i1] & (1ULL << (w - 1));

        ull tar = bits[i1] & large_mask[w - i2];
        tar <<= 1;
        bits[i1] &= ~large_mask[w - i2];
        bits[i1] |= tar;
        if (top) {
            bits[i1 + 1] |= 1ULL;
        }

        bits[n] = 0;
        bits[n - 1] &= ~needless;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << (int)get(i);
        }
        cout << endl;
    }
};

const int MAXN = 555555;

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

Bitset bit(200011);

void solve() {
    bit.reset();

    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        y--;
        bool exi = bit.get(y);
        bit.left_shift(y);

        if (!exi) {
            bit.set(y + 1);
        }
        // bit.show();
    }
    // bit.show();
    int p = bit.count();
    cout << nHr(n + 1, n - 1 - p) << endl;
}

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     vi a;
//     rep(i, m) {
//         int x, y;
//         cin >> x >> y;
//         y--;
//         bool exi = false;
//         for (int j = 0; j < a.size(); j++) {
//             if (a[j] == y) {
//                 exi = true;
//             }
//         }
//         for (int j = 0; j < a.size(); j++) {
//             if (a[j] >= y) {
//                 a[j]++;
//             }
//         }

//         if (!exi) {
//             a.push_back(y + 1);
//             sort(all(a));
//         }
//     }
//     int p = a.size();
//     DEBUG_VEC(a);
//     cout << nHr(n + 1, n - 1 - p) << endl;
// }

signed main() {
    set_fact(400011);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}