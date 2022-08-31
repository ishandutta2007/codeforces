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

const int maxn = 401;
int dist[maxn][maxn];
vi byDist[maxn][maxn];
vi e[maxn];

ld p[maxn], md[maxn];

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
    forn(i, n) forn(j, n) dist[i][j] = 1e9;
    forn(i, n) dist[i][i] = 0;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        dist[u][v] = dist[v][u] = 1;
        e[u].pb(v);
        e[v].pb(u);
    }

    forn(k, n) forn(i, n) forn(j, n) uin(dist[i][j], dist[i][k] + dist[k][j]);

    forn(i, n) forn(j, n) byDist[i][dist[i][j]].pb(j);

    ld ans = 0.0;
    forn(v0, n) {
        ld res0 = 0.0;
        forn(d, n) {
            if (byDist[v0][d].empty()) continue;
            ld res0d = 1.0 / n;

            forn(i, n) p[i] = 0.0;
            for (int x: byDist[v0][d]) for (int y: e[x]) p[y] += 1.0 / e[x].size();

            vi cand;
            fore(dd, max(0, d - 1), d + 1) for (int x: byDist[v0][dd]) cand.pb(x);

            forn(u, n) {
                ld res1 = 0.0;
                for (int x: cand) {
                    int d = dist[u][x];
                    res1 -= md[d];
                    uax(md[d], p[x]);
                    res1 += md[d];
                }
                uax(res0d, res1 / n);
                for (int x: cand) md[dist[u][x]] = 0.0;
            }
            res0 += res0d;
        }
        uax(ans, res0);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}