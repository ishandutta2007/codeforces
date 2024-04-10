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
vi e[maxn];
int eid[maxn], pari[maxn];
int par[maxn];
int tin[maxn], tout[maxn];
int T = 0;

void dfs0(int v, int p) {
    tin[v] = T++;
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) {
            pari[v] = 1 + i;
            continue;
        }
        eid[u] = 1 + i;
        par[u] = v;
        dfs0(u, v);
    }
    tout[v] = T;
}

bool ok = true;
vi nxt[maxn], prv[maxn], vis[maxn];
int D[maxn];

bool is_ancestor(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

void prepend_path(int v, int u, vi &path) {
    path.pb(v);
    if (is_ancestor(v, u)) return;
    prepend_path(par[v], u, path);
}

void append_path(int v, int u, vi &path) {
    if (is_ancestor(v, u)) return;
    append_path(par[v], u, path);
    path.pb(v);
}

int get_id(int from, int to) {
    if (to == par[from]) return pari[from];
    return eid[to];
}

void setc(int v, int i1, int i2) {
    if (nxt[v][i1] != -1 || prv[v][i2] != -1) {
        ok = false;
        return;
    }
    nxt[v][i1] = i2;
    prv[v][i2] = i1;
    --D[v];
}

void path(int from, int to) {
    if (from == to) {
        ok = false;
        return;
    }
    vi p;
    prepend_path(from, to, p);
    append_path(to, from, p);

    forn(i, p.size()) {
        if (!ok) break;
        int v = p[i];
        int i1 = i ? get_id(v, p[i - 1]) : 0;
        int i2 = i + 1 < (int)p.size() ? get_id(v, p[i + 1]) : nxt[v].size() - 1;
        setc(v, i1, i2);
    }
}

i64 fact[maxn];
const i64 P = 1000000000 + 7;

void traverse(int v, int i) {
    if (i == -1) return;
    vis[v][i] = 1;
    traverse(v, nxt[v][i]);
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
    fact[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P;

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs0(0, -1);
    pari[0] = -1;

    vi perm(n);
    forn(i, n) cin >> perm[i], --perm[i];

    forn(i, n) {
        nxt[i].resize(e[i].size() + 2, -1);
        prv[i].resize(e[i].size() + 2, -1);
        D[i] = e[i].size();
    }

    forn(i, n) if (ok && perm[i] != -1) path(perm[i], i);

    i64 ans = 1;
    forn(i, n) {
        vis[i].resize(nxt[i].size());
        traverse(i, 0);
        ok &= !vis[i].back() || *min_element(all(vis[i])) == 1;
        for1(j, vis[i].size() - 1) if (!vis[i][j] && prv[i][j] == -1) traverse(i, j);
        forn(j, vis[i].size()) if (!vis[i][j]) ok = false;
        (ans *= fact[max(D[i], 0)]) %= P;
    }
    if (!ok) ans = 0;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}