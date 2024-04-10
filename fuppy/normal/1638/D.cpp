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

void solve() {
    int h, w;
    cin >> h >> w;
    vii c(h, vi(w));
    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j];
        }
    }

    using tup = tuple<int, int, int>;
    queue<tup> qu;
    vector<tup> ans;

    vii used(h, vi(w));
    rep(i, h - 1) {
        rep(j, w - 1) {
            int col = c[i][j];
            bool flag = true;
            rep(dy, 2) rep(dx, 2) {
                if (c[i + dy][j + dx] != col) {
                    flag = false;
                }
            }
            if (flag) {
                used[i][j] = true;
                qu.push(tup(i, j, col));
            }
        }
    }

    vector<int> st;
    while (qu.size()) {
        auto [i, j, k] = qu.front();
        qu.pop();

        bool ex = false;
        rep(dy, 2) {
            rep(dx, 2) {
                if (c[i + dy][j + dx] == -1) continue;

                assert(c[i + dy][j + dx] == k);
                ex = true;
                c[i + dy][j + dx] = -1;
            }
        }
        if (!ex) continue;

        ans.emplace_back(i, j, k);

        for (int ni = i - 1; ni <= i + 1; ni++) {
            for (int nj = j - 1; nj <= j + 1; nj++) {
                if (not in(ni, 0, h - 1) || not in(nj, 0, w - 1)) continue;
                if (used[ni][nj]) continue;

                st.clear();
                rep(dy, 2) {
                    rep(dx, 2) {
                        int col = c[ni + dy][nj + dx];
                        if (col != -1) st.push_back(col);
                    }
                }

                sort(all(st));
                UNIQUE(st);
                if (st.size() == 1) {
                    used[ni][nj] = true;
                    qu.push({ni, nj, st[0]});
                }
            }
        }
    }

    bool can = true;
    rep(i, h) {
        rep(j, w) {
            if (c[i][j] != -1) can = false;
        }
    }

    if (!can) {
        cout << -1 << endl;
    } else {
        reverse(all(ans));
        cout << ans.size() << endl;
        for (auto [i, j, k] : ans) {
            cout << i + 1 << " " << j + 1 << " " << k << '\n';
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