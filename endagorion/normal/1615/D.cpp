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

const int maxn = 210000;
vector<pii> e[maxn], pe[maxn];
int par[maxn];

bool dfs(int v, int c) {
    if (par[v] == (c ^ 1)) return false;
    if (par[v] == c) return true;
    par[v] = c;
    for (auto [u, z]: pe[v]) if (!dfs(u, c ^ z)) return false;
    return true;
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
        int n, m;
        cin >> n >> m;
        forn(i, n) e[i].clear(), pe[i].clear();
        forn(i, n - 1) {
            int x, y, v;
            cin >> x >> y >> v;
            --x; --y;
            e[x].pb({y, v});
            e[y].pb({x, v});
            if (v >= 0) {
                int pc = __builtin_popcount(v) & 1;
                pe[x].pb({y, pc});
                pe[y].pb({x, pc});
            }
        }
        forn(i, m) {
            int u, v, z;
            cin >> u >> v >> z;
            --u; --v;
            pe[u].pb({v, z});
            pe[v].pb({u, z});
        }

        forn(i, n) par[i] = -1;
        bool ok = true;
        forn(i, n) if (par[i] == -1) ok &= dfs(i, 0);
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        forn(v, n) for (auto [u, z]: e[v]) {
            if (u < v) continue;
            if (z == -1) z = par[v] ^ par[u];
            cout << v + 1 << ' ' << u + 1 << ' ' << z << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}