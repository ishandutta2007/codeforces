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

const int maxn = 6;
int cost[maxn][maxn];

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
    vi a(n), b(m);
    forn(i, n) cin >> a[i];
    forn(j, m) cin >> b[j];

    forn(i, n) forn(j, m) cin >> cost[i][j];
    map<vi, int> dp;
    dp[b] = 0;
    forn(i, n) {
        vector<map<vi, int> > vdp(a[i] + 1);
        vdp[a[i]] = dp;

        forn(j, m) {
            vector<map<vi, int> > nvdp(a[i] + 1);
            forn(x, a[i] + 1) for (auto [v, c]: vdp[x]) forn(k, min(x, v[j]) + 1) {
                vi u = v;
                u[j] -= k;
                if (!nvdp[x - k].count(u)) nvdp[x - k][u] = 1e9;
                uin(nvdp[x - k][u], c + cost[i][j] * int(k > 0));
            }
            vdp = nvdp;
        }
        dp = vdp[0];
    }

    int ans = 2e9;
    for (auto [v, c]: dp) uin(ans, c);
    if (ans > 1e9) ans = -1;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}