#include <bits/stdc++.h>

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

const int maxn = 11;
int vis[maxn];
vi e[maxn];
int d3[maxn];

int get_trit(int v, int i) {
    return v / d3[i] % 3;
}

i64 dp[60000][maxn];
map<i64, i64> buf[maxn][maxn][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    d3[0] = 1;
    forn(i, maxn - 1) d3[i + 1] = d3[i] * 3;

    int n, m, k;
    cin >> n >> m >> k;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    
    dp[1][0] = 1;
    forn(mask, d3[n]) {
        int v = 0;
        while (v < n && get_trit(mask, v) != 1) ++v;
        if (v == n) continue;
        forn(i, e[v].size() + 1) forn(j, n) forn(z, 3) buf[i][j][z].clear();
        int d0 = (mask == 1 ? 0 : 1);
        forn(s, n) if (dp[mask][s]) buf[0][s][d0][mask] = dp[mask][s];
        forn(i, e[v].size()) forn(ss, n) forn(dd, 3) for (auto [mask, z]: buf[i][ss][dd]) {
            int u = e[v][i];
            buf[i + 1][ss][dd][mask] += z;
            if (get_trit(mask, u) == 0) {
                buf[i + 1][ss][min(dd + 1, 2)][mask + d3[u]] += z;
            }
        }
        forn(ss, n) for1(dd, 2) for (auto [mask, z]: buf[e[v].size()][ss][dd]) {
            int nmask = mask + d3[v];
            int ns = ss + int(dd == 1);
            dp[nmask][ns] += z;
        }
    }

    cout << dp[d3[n] - 1][k] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}