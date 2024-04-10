/*
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
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

class UnionFind {
  public:
    int n;
    vi par;
    vi ran;
    vi num;
    int g;

    UnionFind(int _n) {
        n = _n;
        g = n;
        par.resize(n);
        ran.resize(n);
        num.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            ran[i] = 0;
            num[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        int numsum = num[x] + num[y];
        if (x == y) {
            return;
        }
        if (ran[x] < ran[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (ran[x] == ran[y]) {
                ran[x]++;
            }
        }
        num[x] = num[y] = numsum;
        g--;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

bool check(vi a, vi b, int n, int m) {
    UnionFind uf(n);

    vi pos(n);
    rep(i, n) {
        pos[a[i]] = i;
    }

    int out = 0;
    rep(i, n) {
        int x = b[i];
        int j = pos[x];
        if (i != j) {
            uf.unite(i, j);
            out++;
        }
    }

    vi used(n);
    rep(i, n) {
        int x = uf.find(i);
        if (used[x]) continue;
        used[x] = true;
        if (uf.num[x] == 1) continue;
        out--;
    }
    return out <= m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }

    vi num(n);
    rep(i, n) {
        int k = (i - a[i] + 3 * n) % n;
        num[k]++;
    }

    vi ans;
    rep(i, n) {
        if (num[i] >= n / 3 - 1) {
            vi b(n);
            int x = 0;
            for (int j = i; j < n; j++) {
                b[j] = x++;
            }
            for (int j = 0; j < i; j++) {
                b[j] = x++;
            }

            if (check(a, b, n, m)) ans.push_back(i);
        }
    }

    cout << ans.size() << " ";
    for (int u : ans) {
        cout << u << " ";
    }
    cout << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}