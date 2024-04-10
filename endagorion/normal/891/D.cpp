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
int dp[maxn][2], w[maxn];
vi e[maxn];

void dfs_down(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_down(u, v);
        w[v] += w[u];
    }
    int C = 0;
    vi goodc(2);
    for (int u: e[v]) {
        if (u == p) continue;
        ++C;
        bool good = dp[u][0];
        if (good) ++goodc[w[u] & 1];
    }
    if (goodc[0] + goodc[1] == C && goodc[1] < 2) {
        dp[v][0] = 1;
    }
    for (int u: e[v]) {
        if (u == p) continue;
        bool good = dp[u][0];
        int p = w[u] & 1;
        if (good) --goodc[p];
        ++goodc[p ^ 1];

        if (goodc[0] + goodc[1] == C && goodc[1] < 2) {
            dp[v][1] += dp[u][1];
        }

        --goodc[p ^ 1];
        if (good) ++goodc[p];
    }

    if (w[v] & 1) dp[v][1] += dp[v][0];

//    cerr << v << ' ' << w[v] << ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
}

i64 ans = 0;

void dfs_up(int v, int p, int uw, vi udp) {
//    cerr << v << ' ' << p << ' ' << uw << ' ' << udp[0] << ' ' << udp[1] << '\n';
//    cerr << w[v] << ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
    if (!(w[v] & 1)) {
        if (dp[v][0] && udp[0]) ans += 1LL * w[v] * uw;
    } else {
        ans += 1LL * dp[v][1] * udp[1];
    }
    int C = 1;
    vi goodc(2);
    if (udp[0]) ++goodc[uw & 1];
    vvi sdp1(2, vi(2));
    sdp1[udp[0]][uw & 1] += udp[1];
    ++uw;
    for (int u: e[v]) {
        if (u == p) continue;
        ++C;
        uw += w[u];
        if (dp[u][0]) ++goodc[w[u] & 1];
        sdp1[dp[u][0]][w[u] & 1] += dp[u][1];
    }


    for (int u: e[v]) {
        if (u == p) continue;
        bool good = dp[u][0];
        int p = w[u] & 1;
        if (good) --goodc[p];
        ++goodc[0];
        uw -= w[u];
        sdp1[dp[u][0]][w[u] & 1] -= dp[u][1];

        vi ndp(2);
        if (goodc[0] + goodc[1] == C && goodc[1] < 2) {
            ndp[0] = 1;
        }

/*        cerr << v << ' ' << u << '\n';
        forn(x, 2) forn(y, 2) cerr << sdp1[x][y] << ' ';
        cerr << '\n';*/

        forn(g, 2) forn(p, 2) {
            if (g) --goodc[p];
            ++goodc[p ^ 1];

            if (goodc[0] + goodc[1] == C && goodc[1] < 2) {
                ndp[1] += sdp1[g][p];
            }

            --goodc[p ^ 1];
            if (g) ++goodc[p];
        }
        if (uw & 1) ndp[1] += ndp[0];
        dfs_up(u, v, uw, ndp);
        
        sdp1[dp[u][0]][w[u] & 1] += dp[u][1];
        uw += w[u];
        --goodc[0];
        if (good) ++goodc[p];
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
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs_down(0, -1);
    if (!(n & 1)) dfs_up(0, -1, 0, {1, 0});
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}