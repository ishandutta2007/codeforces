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

int n;
const int maxn = 1100;
vi e[maxn];
i64 a[maxn], b[maxn];
int vis[maxn];
int par[maxn];
i64 TB = 0;

pii dfs(int v, int p, i64 x) {
    if (!vis[v] && x <= a[v]) return mp(-1, -1);
    if (vis[v] || par[v] != -1) return mp(v, p);
    par[v] = p;
    x += b[v];
    for (int u: e[v]) {
        if (u == p) continue;
        auto res = dfs(u, v, x);
        if (res != mp(-1, -1)) return res;
    }
    return mp(-1, -1);
}

bool can(i64 x) {
    forn(i, n) vis[i] = 0;
    vis[0] = 1;
    i64 xt = x + TB;
    while (x < xt) {
        forn(i, n) par[i] = -1;
        auto p = mp(-1, -1);
        forn(i, n) {
            if (!vis[i]) continue;
            for (int j: e[i]) {
                if (p != mp(-1, -1)) break;
                if (!vis[j]) p = dfs(j, i, x);
            }
        }
        if (p == mp(-1, -1)) return false;
        for (int v: {p.fi, p.se}) {
            for (int u = v; u != -1; u = par[u]) {
                if (!vis[u]) {
                    vis[u] = 1;
                    x += b[u];
                }
            }
        }
    }
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
        int m;
        cin >> n >> m;
        forn(i, n) e[i].clear();
        for1(i, n - 1) cin >> a[i];
        TB = 0;
        for1(i, n - 1) cin >> b[i], TB += b[i];

        forn(i, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            e[v].pb(u);
        }

        i64 L = -1, R = 1e13;
        while (R - L > 1) {
            i64 M = (L + R) / 2;
            (can(M) ? R : L) = M;
        }
        cout << R << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}