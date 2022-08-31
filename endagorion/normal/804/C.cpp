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

const int maxn = 510000;
vi c[maxn], e[maxn];
int col[maxn];
int fr[maxn];
int ans = 1;

void dfs(int v, int p) {
    int K = c[v].size();
    uax(ans, K);
    forn(i, K) fr[i] = 1;
    for (int x: c[v]) {
        if (col[x] != -1) fr[col[x]] = 0;
    }

    int z = 0;
    for (int x: c[v]) {
        if (col[x] != -1) continue;
        while (!fr[z]) ++z;
        col[x] = z++;
    }

    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
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

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        int x;
        cin >> x;
        c[i].resize(x);
        forn(j, x) cin >> c[i][j], --c[i][j];
    }

    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    forn(i, m) col[i] = -1;
    dfs(0, -1);

    cout << ans << '\n';
    forn(i, m) {
        if (col[i] == -1) col[i] = 0;
        cout << col[i] + 1 << " \n"[i + 1 == m];
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}