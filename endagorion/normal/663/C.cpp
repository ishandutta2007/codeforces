#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
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

const int maxn = 110000;
vector<pii> e[maxn];
int col[maxn];

int z;

bool dfs(int v, int c, vi &l0, vi &l1) {
    if (col[v] != -1) return col[v] == c;
    col[v] = c;
    (c ? l1 : l0).pb(v);
    for (auto w: e[v]) {
        int u = w.fi, y = w.se;
        if (!dfs(u, c ^ y ^ z, l0, l1)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, m) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        --x; --y;
        e[x].pb(mp(y, c == 'B'));
        e[y].pb(mp(x, c == 'B'));
    }
    int ansSize = 1e9;
    vi ans;
    for (z = 0; z < 2; ++z) {
        forn(i, n) col[i] = -1;
        vi res;
        bool ok = true;
        forn(i, n) {
            if (col[i] != -1) continue;
            vi l0, l1;
            if (!dfs(i, 0, l0, l1)) {
                ok = false;
                break;
            }
            if (l0.size() > l1.size()) swap(l0, l1);
            for (int x: l0) res.pb(x);
        }
        if (!ok) continue;
        if (uin(ansSize, (int)res.size())) {
            ans = res;
        }
    }
    if (ansSize > n) {
        cout << -1 << '\n';
    } else {
        cout << ansSize << '\n';
        for (int x: ans) cout << x + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}