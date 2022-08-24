#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int index(const vi &xs, int x) {
    return lower_bound(all(xs), x) - xs.begin();
}

vi xv, yv1, yv2;
vi yv, xv1, xv2;
const int maxv = 10000;
vi e[maxv];
int match[maxv], mm[maxv];
int vis[maxv], vis2[maxv];

bool kuhn(int v) {
    if (vis[v]) return false;
    vis[v] = 1;
    for (int u: e[v]) {
        if (match[u] == -1 || kuhn(match[u])) {
            match[u] = v;
            mm[v] = u;
            return true;
        }
    }
    return false;
}

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) {
        if (u == mm[v]) continue;
        vis2[u] = 1;
        if (match[u] != -1) dfs(match[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    vi x(n), y(n);
    forn(i, n) cin >> x[i] >> y[i];
    vi xs = x, ys = y;
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    sort(all(ys));
    ys.erase(unique(all(ys)), ys.end());

    forn(i, n) x[i] = index(xs, x[i]);
    forn(i, n) y[i] = index(ys, y[i]);

    int A = xs.size(), B = ys.size();
    vi ly(A, 1e9), ry(A, -1e9), lx(B, 1e9), rx(B, -1e9);
    vvi M(A, vi(B));
    forn(i, n) {
        M[x[i]][y[i]] = 1;
        uin(ly[x[i]], y[i]);
        uax(ry[x[i]], y[i]);
        uin(lx[y[i]], x[i]);
        uax(rx[y[i]], x[i]);
    }

    vvi xn(A, vi(B, -1)), yn(A, vi(B, -1));
    forn(i, A) {
        int jj = ly[i];
        fore(j, ly[i] + 1, ry[i]) {
            if (!M[i][j]) {
                xn[i][j] = xv.size();
                continue;
            }
            if (jj != -1 && j > jj + 1) {
                xv.pb(i);
                yv1.pb(jj + 1);
                yv2.pb(j);
            }
            jj = j;
        }
    }

    forn(j, B) {
        int ii = lx[j];
        fore(i, lx[j] + 1, rx[j]) {
            if (!M[i][j]) {
                yn[i][j] = yv.size();
                continue;
            }
            if (ii != -1 && i > ii + 1) {
                yv.pb(j);
                xv1.pb(ii + 1);
                xv2.pb(i);
            }
            ii = i;
        }
    }

    int K = xv.size(), L = yv.size();
    forn(i, A) forn(j, B) {
        if (xn[i][j] == -1 || yn[i][j] == -1) continue;
        e[xn[i][j]].pb(yn[i][j]);
    }

    forn(i, K) mm[i] = -1;
    forn(i, L) match[i] = -1;
    forn(i, K) {
        forn(j, K) vis[j] = 0;
        kuhn(i);
    }

    forn(j, K) vis[j] = 0;
    forn(i, K) if (mm[i] == -1) dfs(i);
    vector<tuple<int, int, int> > xans, yans;
    forn(i, A) {
        int jj = -1;
        fore(j, ly[i], ry[i]) {
            if (!M[i][j] && !vis[xn[i][j]]) {
                if (jj != -1) xans.pb({i, jj, j - 1});
                jj = -1;
                continue;
            }
            if (jj == -1) jj = j;
        }
        xans.pb({i, jj, ry[i]});
    }
    forn(j, B) {
        int ii = -1;
        fore(i, lx[j], rx[j]) {
            if (!M[i][j] && vis2[yn[i][j]]) {
                if (ii != -1) yans.pb({j, ii, i - 1});
                ii = -1;
                continue;
            }
            if (ii == -1) ii = i;
        }
        yans.pb({j, ii, rx[j]});
    }

    cout << yans.size() << '\n';
    for (auto w: yans) {
        int y, x1, x2;
        tie(y, x1, x2) = w;
        cout << xs[x1] << ' ' << ys[y] << ' ' << xs[x2] << ' ' << ys[y] << '\n';
    }
    cout << xans.size() << '\n';
    for (auto w: xans) {
        int x, y1, y2;
        tie(x, y1, y2) = w;
        cout << xs[x] << ' ' << ys[y1] << ' ' << xs[x] << ' ' << ys[y2] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}