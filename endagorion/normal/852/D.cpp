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

const int maxn = 601;
int d[maxn][maxn];
int st[maxn], vis[maxn], match[maxn];
vi w[maxn];

bool dfs(int v) {
    if (vis[v]) return false;
    vis[v] = 1;
    for (int u: w[v]) {
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int v, e, n, k;
    cin >> v >> e >> n >> k;
    forn(i, v) forn(j, v) d[i][j] = 1e9;
    forn(i, v) d[i][i] = 0;
    forn(i, n) cin >> st[i], --st[i];
    forn(i, e) {
        int x, y, t;
        cin >> x >> y >> t;
        --x; --y;
        uin(d[x][y], t);
        uin(d[y][x], t);
    }

    forn(k, v) forn(i, v) forn(j, v) uin(d[i][j], d[i][k] + d[k][j]);
    int L = -1, R = 1e9;
    while (R - L > 1) {
        int M = (L + R) / 2;
        forn(i, n) w[i].clear();
        forn(i, n) forn(j, v) if (d[st[i]][j] <= M) w[i].pb(j);
        forn(j, v) match[j] = -1;
        int res = 0;
        forn(i, n) {
            forn(j, n) vis[j] = 0;
            res += int(dfs(i));
        }
//        cerr << M << ' ' << res << '\n';
        (res >= k ? R : L) = M;
    }
    if (R > 1e8) R = -1;
    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}