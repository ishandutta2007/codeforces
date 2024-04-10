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

const int maxn = 1100;
string f[maxn];
int dist[maxn][maxn][4];
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, n) cin >> f[i];
    forn(i, n) forn(j, m) forn(d, 4) dist[i][j][d] = 1e9;
    int sx, sy, tx, ty;
    forn(i, n) forn(j, m) {
        if (f[i][j] == 'S') sx = i, sy = j;
        if (f[i][j] == 'T') tx = i, ty = j;
    }

    deque< tuple<int, int, int> > q;
    forn(d, 4) {
        dist[sx][sy][d] = 0;
        q.pb(mt(sx, sy, d));
    }
    while (!q.empty()) {
        int x, y, d;
        tie(x, y, d) = q.front();
        q.pop_front();
        forn(dd, 4) {
            int xx = x + dx[dd], yy = y + dy[dd];
            if (min(xx, yy) < 0 || min(n - xx, m - yy) <= 0 || f[xx][yy] == '*') continue;
            int nd = dist[x][y][d] + int(d != dd);
            if (nd >= dist[xx][yy][dd]) continue;
            uin(dist[xx][yy][dd], nd);
            if (d == dd) q.push_front(mt(xx, yy, dd));
            else q.pb(mt(xx, yy, dd));
        }
    }

    int ans = 1e9;
    forn(d, 4) uin(ans, dist[tx][ty][d]);
    cout << (ans <= 2 ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}