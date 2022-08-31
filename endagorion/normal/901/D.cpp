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
i64 c[maxn], rc[maxn];
i64 ec[maxn];
int h[maxn], vis[maxn];
pii par[maxn];
vector<pii> e[maxn];

void dfs(int v, int p) {
    vis[v] = 1;
    for (auto [u, id]: e[v]) {
        if (u == p) continue;
        if (vis[u]) continue;
        h[u] = h[v] + 1;
        par[u] = {v, id};
        dfs(u, v);
        i64 delta = c[u] - rc[u];
        ec[id] = delta;
        rc[u] += delta;
        rc[v] += delta;
    }
}

void pathflip(int v, i64 x) {
    while (v) {
        auto [u, id] = par[v];
        ec[id] += x;
        rc[v] += x;
        rc[u] += x;
        v = u;
        x = -x;
    }
}

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
    forn(i, n) cin >> c[i];
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb({v, i});
        e[v].pb({u, i});
    }
    dfs(0, -1);
    forn(v, n) for (auto [u, id]: e[v]) {
        if (c[0] == rc[0]) break;
        if (h[v] < h[u]) continue;
        if (h[v] % 2 != h[u] % 2) continue;
        i64 x = (c[0] - rc[0]) / 2 * (h[u] % 2 ? -1 : 1);
//        cerr << v << ' ' << u << ' ' << x << '\n';
        ec[id] += x;
        rc[v] += x;
        rc[u] += x;
        pathflip(v, -x);
        pathflip(u, -x);
    }

    bool ok = true;
    forn(v, n) {
//        cerr << v << ' ' << c[v] << ' ' << rc[v] << '\n';
        ok &= c[v] == rc[v];
    }
    if (ok) {
        cout << "YES\n";
        forn(i, m) cout << ec[i] << '\n';
    } else cout << "NO\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}