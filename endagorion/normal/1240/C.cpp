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

const int maxn = 510000;
i64 dp[maxn][2];
vector<pii> e[maxn];
int n, k;

void dfs(int v, int p) {
    i64 base = 0;
    vi64 difs;
    for (auto w: e[v]) {
        int u = w.fi, c = w.se;
        if (u == p) continue;
        dfs(u, v);
        base += dp[u][1];
        difs.pb(dp[u][0] + c - dp[u][1]);
    }
    sort(rall(difs));
    dp[v][0] = dp[v][1] = base;
    forn(i, difs.size()) {
        if (i >= k) break;
        base += difs[i];
        if (i < k - 1) uax(dp[v][0], base);
        if (i < k) uax(dp[v][1], base);
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

    int q;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        forn(i, n) e[i].clear();
        forn(i, n - 1) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            e[v].pb({u, w});
            e[u].pb({v, w});
        }
        forn(i, n) forn(j, 2) dp[i][j] = 0;
        dfs(0, -1);
        cout << dp[0][1] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}