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
i64 P;
int n;
vi e[maxn];
i64 dp[maxn][maxn];


void dfs(int v, int p) {
    vi ch;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        ch.pb(u);
    }
    int C = ch.size();
    vvi64 ps(C + 1, vi64(n + 1)), ss(C + 1, vi64(n + 1));
    ps[0] = ss[0] = vi64(n + 1, 1);

    forn(i, C) {
        int u = ch[i];
        i64 sum = 0;
        forn(j, n + 1) {
            (sum += dp[u][j]) %= P;
            ps[i + 1][j] = ps[i][j] * sum % P;
        }
    }
    forn(i, C) {
        int u = ch[C - i - 1];
        i64 sum = 0;
        forn(j, n + 1) {
            (sum += dp[u][j]) %= P;
            ss[i + 1][j] = ss[i][j] * sum % P;
        }
    }

    if (!v) {
        i64 sum = 0;
        forn(j, n + 1) {
            dp[v][j] = sum;
            (sum = ps[C][j]) %= P;
        }
        return;
    }

    i64 sum = 0;
    forn(j, n + 1) {
        (sum = ps[C][j]) %= P;
        dp[v][j] = sum;
    }
    forn(i, C) {
        i64 sum = 0;
        int u = ch[i];
        forn(j, n + 1) {
            (dp[v][j] += sum * dp[u][j]) %= P;
            (sum += ps[i][j] * ss[C - i - 1][j]) %= P;
        }
    }

/*    cerr << v << ": ";
    forn(j, n + 1) cerr << dp[v][j] << ' ';
    cerr << '\n';*/
}

i64 cnk[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> P;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(0, -1);

    cnk[0][0] = 1;
    forn(i, n) forn(j, i + 1) forn(k, 2) (cnk[i + 1][j + k] += cnk[i][j]) %= P;

//    forn(j, n + 1) cout << dp[0][j] << ' ';
//    cout << '\n';

    for1(i, n) fore(j, i + 1, n) (dp[0][j] += P - dp[0][i] * cnk[j][i] % P) %= P;

    for1(j, n - 1) cout << dp[0][j] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}