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
const i64 P = 998244353;
pi64 dp[maxn][2][2];

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

pi64 operator+(pi64 a, pi64 b) {
    add(a.fi, b.fi);
    add(a.se, b.se);
    return a;
}

pi64 operator*(pi64 a, pi64 b) {
    return {(a.fi * b.se + a.se * b.fi) % P, a.se * b.se % P};
}

vi e[maxn];

pi64 buf[2][2];

void dfs(int v, int p) {
    dp[v][0][1] = {0, 1};
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        forn(x, 2) forn(y, 2) buf[x][y] = {0, 0};
        forn(self, 2) forn(par, 2) forn(uself, 2) forn(upar, 2) {
            pi64 V = dp[v][self][par] * dp[u][uself][upar];
            buf[self][par] = buf[self][par] + V;
            {
                int nself = self | upar;
                int npar = par & uself;
                if (par && !uself) add(V.fi, V.se);
                if (upar && !self) add(V.fi, V.se);
                buf[nself][npar] = buf[nself][npar] + V;
            }
        }
        forn(x, 2) forn(y, 2) dp[v][x][y] = buf[x][y];
    }

/*    cerr << v << '\n';
    forn(x, 2) forn(y, 2) {
        auto [sr, s1] = dp[v][x][y];
        cerr << sr << ' ' << s1 << '\n';
    }*/
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

    dfs(0, 0);
    i64 ans = 0;
    forn(x, 2) forn(y, 2) add(ans, dp[0][x][y].fi);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}