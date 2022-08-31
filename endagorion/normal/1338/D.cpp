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

const int maxn = 110000;
vi e[maxn];
int dp[maxn][2];
int ans;

void dfs(int v, int p) {
    int ch = (int)e[v].size() - (p == -1 ? 0 : 1);
    int mx01 = 0, mx02 = 0;
    int mx11 = 0, mx12 = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        int v0 = dp[u][0], v1 = max(dp[u][0], dp[u][1]);
        if (v0 > mx01) swap(v0, mx01);
        if (v0 > mx02) swap(v0, mx02);
        if (v1 > mx11) swap(v1, mx11);
        if (v1 > mx12) swap(v1, mx12);
    }
    uax(ans, mx01 + mx02 + 1);
    uax(ans, mx11 + mx12 + max(0, (int)e[v].size() - 2));
    dp[v][0] = mx11 + max(0, ch - 1);
    dp[v][1] = mx01 + 1;
//    cerr << v << ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
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
    dfs(0, -1);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}