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

void solve(int n) {
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }
    if (n <= 4) {
        cout << n - 1 << endl;
        rep1(i, n - 1) cout << i << " " << i << endl;
        return;
    }

    vector<pii> res;

    int m;
    int oy, ox;
    if (n % 3 == 2) {
        res.emplace_back(0, 0);
        oy = 1;
        ox = 2;
    } else if (n % 3 == 0) {
        res.emplace_back(0, 0);
        res.emplace_back(1, 1);
        oy = 2;
        ox = 3;
    } else {
        res.emplace_back(0, 0);
        res.emplace_back(1, 1);
        res.emplace_back(2, 2);
        oy = 3;
        ox = 4;
    }

    m = n - (int)res.size();
    m = (m - 1) / 3;

    rep(_, m) {
        res.emplace_back(oy, ox);
        res.emplace_back(oy + m, ox - 1);
        oy++;
        ox += 2;
    }

    cout << res.size() << endl;
    for (auto [y, x] : res) {
        cout << y + 1 << " " << x + 1 << endl;
    }

    // vii a(n, vi(n));
    // for (auto [y, x] : res) {
    //     a[y][x] = 1;
    // }
    // DEBUG_MAT(a);
}

void guchoku(int n) {
    int m = n * n;

    int mi = inf;
    vii best(n, vi(n));
    rep(i, 1LL << m) {
        vii a(n, vi(n));

        int bit = 0;
        rep(j, m) {
            if (i & (1LL << j)) {
                int y = j / n, x = j % n;
                a[y][x] = 2;
                bit++;
            }
        }

        if (mi <= bit) continue;

        rep(y, n) {
            rep(x, n) {
                if (a[y][x] >= 2) {
                    rep(k, n) {
                        a[y][k] |= 1;
                        a[k][x] |= 1;
                    }

                    for (int k = -n; k <= n; k++) {
                        int ny = y + k, nx = x + k;
                        if (not in(ny, 0, n) or not in(nx, 0, n)) continue;
                        a[ny][nx] |= 1;
                    }
                }
            }
        }

        bool suc = true;
        rep(i, n) {
            rep(j, n) {
                if (a[i][j] == 0) suc = false;
            }
        }

        if (suc) {
            mi = bit;
            best = a;
        }
    }
    DEBUG(mi);
    DEBUG_MAT(best);
}

void guchoku2(int n) {
    int m = n * n;

    int mi = inf;
    vii best(n, vi(n));

    vii p2i(n + 1);
    rep(i, 1 << n) p2i[popcount(i)].push_back(i);

    rep1(p, n) {
        for (int yi : p2i[p]) {
            for (int xi : p2i[p]) {
                vii a(n, vi(n));
                rep(y, n) {
                    rep(x, n) {
                        if ((yi & (1 << y)) || (xi & (1 << x))) {
                            a[y][x] = 2;
                        }
                    }
                }

                vi yx;
                rep(y, n) {
                    rep(x, n) {
                        if (a[y][x] == 0) {
                            yx.push_back(y - x);
                        }
                    }
                }
                sort(all(yx));
                UNIQUE(yx);

                if (yx.size() > p) continue;

                vi ys, xs;
                rep(y, n) {
                    if (yi & (1 << y)) ys.push_back(y);
                    if (xi & (1 << y)) xs.push_back(y);
                }

                set<int> st;
                do {
                    st.clear();

                    rep(i, ys.size()) {
                        st.insert(ys[i] - xs[i]);
                    }

                    bool flag = true;
                    for (int v : yx) {
                        if (st.count(v) == 0) flag = false;
                    }

                    if (flag) {
                        cout << p << endl;
                        DEBUG_VEC(ys);
                        DEBUG_VEC(xs);
                        vii b(n, vi(n));
                        rep(i, ys.size()) b[ys[i]][xs[i]] = 1;

                        DEBUG_MAT(b);

                        return;
                    }

                } while (next_permutation(all(xs)));
            }
        }
    }
    DEBUG(mi);
    DEBUG_MAT(best);
}

signed main() {
    int t = 1;
    // cin >> t;
    rep1(cas, t) {
        // DEBUG(cas);
        int n = cas;
        cin >> n;
        solve(n);
        // guchoku2(n);
    }
}