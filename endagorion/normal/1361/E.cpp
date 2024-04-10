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
int vis[maxn], lnk[maxn], good[maxn];
vi e[maxn], reup[maxn];

pii operator+(pii p, int v) {
    return {p.fi + 1, p.se ^ v};
}

pii operator+(pii p, pii q) {
    return {p.fi + q.fi, p.se ^ q.se};
}

pii operator-(pii p, int v) {
    return {p.fi - 1, p.se ^ v};
}

bool dfs0(int v) {
    vis[v] = 1;
    for (int u: e[v]) {
        if (vis[u] == 0) {
            if (!dfs0(u)) return false;
        } else if (vis[u] == 1) reup[u].pb(u);
        else return false;
    }
    vis[v] = 2;
    return true;
}

pii dfs1(int v) {
    pii res = {0, 0};
    vis[v] = 1;
    for (int u: e[v]) {
        if (vis[u] == 2) continue;
        if (vis[u] == 1) {
            res = res + u;
            continue;
        }
        res = res + dfs1(u);
    }
    for (int u: reup[v]) res = res - u;
//    cerr << v << ' ' << res.fi << ' ' << res.se << '\n';
    if (res.fi == 1) lnk[v] = res.se;
    else lnk[v] = -1;
    vis[v] = 2;
    return res;
}

void dfs2(int v) {
    vis[v] = 1;
    if (!good[v] && lnk[v] != -1) good[v] = good[lnk[v]];
    for (int u: e[v]) if (!vis[u]) dfs2(u);
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
        forn(i, n) e[i].clear();
        forn(i, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
        }

        int tries = 100;
        int v = -1;
        while (tries--) {
            int u = 0;
            forn(z, 30) u = (2 * u + rand() % 2) % n;
            forn(i, n) vis[i] = 0, reup[i].clear();
            if (dfs0(u)) {
                v = u;
                break;
            }
        }
//        cerr << "v=" << v << '\n';

        vi ans;
        if (v != -1) {
            forn(i, n) vis[i] = 0;
            dfs1(v);
            forn(i, n) good[i] = vis[i] = 0;
            good[v] = 1;
            dfs2(v);
            forn(i, n) if (good[i]) ans.pb(i);
        }
        if (v == -1 || 5 * ans.size() < n) cout << -1;
        else for (int x: ans) cout << x + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}