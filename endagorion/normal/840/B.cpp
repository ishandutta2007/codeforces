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

const int maxn = 310000;
vector<pii> e[maxn];
int d[maxn], vis[maxn];
vi ans;

int dfs(int v) {
    if (vis[v]) return 0;
    vis[v] = 1;
    int par = d[v];
    for (pii w: e[v]) {
        int u = w.fi, id = w.se;
        if (dfs(u)) {
            ans.pb(id);
            par ^= 1;
        }
    }
    return par;
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
    forn(i, n) cin >> d[i];
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb({y, i + 1});
        e[y].pb({x, i + 1});
    }

    int n_odd = 0, n_no = 0;
    forn(i, n) {
        if (d[i] == 1) ++n_odd;
        if (d[i] == -1) ++n_no;
    }
    if (n_odd % 2 && !n_no) {
        cout << -1 << '\n';
        return 0;
    }
    int f = n_odd % 2;
    forn(i, n) if (d[i] == -1) d[i] = f, f = 0;

    dfs(0);
    cout << ans.size() << '\n';
    sort(all(ans));
    for (int x: ans) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}