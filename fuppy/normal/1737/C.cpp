//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

// #include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
// using namespace atcoder;

// #define _GLIBCXX_DEBUG

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

void dfs(vii a, set<vii> &st) {
    DEBUG_MAT(a);
    int n = a.size();
    if (st.count(a)) {
        return;
    }
    st.insert(a);

    rep(i, n) {
        rep(j, n) {
            if (a[i][j] == 0) {
                continue;
            }
            DEBUG(pii(i, j));
            rep(k, 8) {
                int ni = i + dy2[k], nj = j + dx2[k];
                int nni = i + dy2[k] * 2, nnj = j + dx2[k] * 2;

                if (not in(nni, 0, n) or not in(nnj, 0, n)) {
                    continue;
                }
                DEBUG(pii(i, j));
                if (a[ni][nj] == 1 && a[nni][nnj] == 0) {
                    vii b = a;
                    DEBUG_MAT(b);
                    b[i][j] = 0;
                    b[nni][nnj] = 1;
                    dfs(b, st);
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    map<int, int> mpx, mpy;
    bool c1 = false, c2 = false, c3 = false, c4 = false;
    rep(i, 3) {
        int x, y;
        cin >> x >> y;

        if (x == 1 && y == 1) {
            c1 = true;
        } else if (x == 1 && y == n) {
            c2 = true;
        } else if (x == n && y == 1) {
            c3 = true;
        } else if (x == n && y == n) {
            c4 = true;
        }
        mpx[x]++;
        mpy[y]++;
    }

    int X = -1, Y = -1;
    for (auto [x, c] : mpx) {
        assert(c == 1 or c == 2);
        if (c == 1) {
            X = x;
        }
    }

    for (auto [y, c] : mpy) {
        assert(c == 1 or c == 2);
        if (c == 1) {
            Y = y;
        }
    }

    assert(X != -1);
    assert(Y != -1);
    // DEBUG(pii(X, Y));

    int x, y;
    cin >> x >> y;

    if (c1 && X == 2 && Y == 2) {
        YES(x == 1 or y == 1);
        return;
    }
    if (c2 && X == 2 && Y == n - 1) {
        YES(x == 1 or y == n);
        return;
    }
    if (c3 && X == n - 1 && Y == 2) {
        YES(x == n or y == 1);
        return;
    }
    if (c4 && X == n - 1 && Y == n - 1) {
        YES(x == n or y == n);
        return;
    }

    if (X % 2 == x % 2 && Y % 2 == y % 2) {
        NO();
    } else {
        YES();
    }
}

signed main() {
    // while (true) {
    //     int n;
    //     cin >> n;
    //     vii a(n, vi(n));
    //     int y1, x1, y2, x2, y3, x3;
    //     cin >> y1 >> x1 >> y2 >> x2 >> y3 >> x3;
    //     y1--;
    //     x1--;
    //     y2--;
    //     x2--;
    //     y3--;
    //     x3--;
    //     a[y1][x1] = 1;
    //     a[y2][x2] = 1;
    //     a[y3][x3] = 1;

    //     set<vii> st;

    //     dfs(a, st);

    //     vii can(n, vi(n));
    //     for (vii x : st) {
    //         rep(i, n) {
    //             rep(j, n) {
    //                 can[i][j] |= x[i][j];
    //             }
    //         }
    //     }
    //     DEBUG_MAT(can);
    // }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}