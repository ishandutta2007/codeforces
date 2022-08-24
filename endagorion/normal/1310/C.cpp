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

const int maxn = 1100, maxv = maxn * maxn / 2;
int tr[maxv][26];
int h[maxv];
vi ls[maxv];
int cpos[maxn][maxn], lrepr[maxv], len[maxv];
int tc = 2;

string s;
int n, m;
i64 k;

int T = 0;

void dfs(int v) {
    if (!v) return;
    if (h[v]) {
        for (int l: ls[v]) cpos[l][l + h[v]] = T;
        lrepr[T] = ls[v][0];
        len[T] = h[v];
        ++T;
    }
    forn(t, 26) dfs(tr[v][t]);
}

i64 dp[maxn][maxn], pdp[maxn][maxn];

void add(i64 &x, i64 y) {
    x += y;
    uin(x, k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> k >> s;
    forn(l, n) {
        int v = 1;
        fore(i, l, n - 1) {
            int &u = tr[v][s[i] - 'a'];
            if (!u) {
                u = tc++;
                h[u] = h[v] + 1;
            }
            ls[u].pb(l);
            v = u;
        }
    }

    dfs(1);
    int L = 0, R = T + 1;
    while (R - L > 1) {
        int M = (L + R) / 2;
        dp[n][0] = pdp[n][0] = 1;
        ford(i, n) {
            int p = i + 1;
            while (p <= n && cpos[i][p] < M) ++p;
            dp[i][0] = 0;
            if (p <= n) {
                for1(j, m) dp[i][j] = pdp[p][j - 1];
            } else for1(j, m) dp[i][j] = 0;
            forn(j, m + 1) {
                pdp[i][j] = dp[i][j];
                add(pdp[i][j], pdp[i + 1][j]);
            }
        }
        (dp[0][m] >= k ? L : R) = M;
    }

    cout << string(s.begin() + lrepr[L], s.begin() + lrepr[L] + len[L]) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}