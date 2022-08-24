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

const int maxn = 3100;
vi e[maxn];
int n, m;
pi64 dp[maxn][maxn];
pi64 buf[maxn];
int w[maxn];
i64 b[maxn];

pi64 operator+(pi64 a, pi64 b) {
    return {a.fi + b.fi, a.se + b.se};
}

pi64 cut(pi64 a) {
    if (a.se > 0) ++a.fi;
    a.se = 0;
    return a;
}

void dfs(int v, int p) {
    w[v] = 1;
    dp[v][1] = {0, b[v]};
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        int lv = min(w[v], m), lu = min(w[u], m);
        forn(i, m + 1) buf[i] = {-1e18, 0};
        for1(sv, lv) for1(su, lu) {
            if (sv + su - 1 > m) break;
            uax(buf[sv + su - 1], dp[v][sv] + dp[u][su]);
            if (sv + su <= m) uax(buf[sv + su], dp[v][sv] + cut(dp[u][su]));
        }
        w[v] += w[u];
        forn(i, n + 1) dp[v][i] = buf[i];
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

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        forn(i, n) {
            i64 x;
            cin >> x;
            b[i] = -x;
        }
        forn(i, n) {
            i64 x;
            cin >> x;
            b[i] += x;
        }
        forn(i, n) e[i].clear();
        forn(i, n - 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            e[v].pb(u);
        }
        dfs(0, -1);
        cout << cut(dp[0][m]).fi << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}