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
typedef unsigned long long ui64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

ui64 fh(ui64 x) {
    return x ^ (x << 13) ^ (x >> 7) ^ (x >> 23) ^ (13 * x + 31074) ^ 1202937199ULL;
}

const int maxn = 110000;
ui64 subt[maxn];
vi e[maxn];

void dfs_down(int v, int p) {
    ui64 s = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_down(u, v);
        s += subt[u];
    }
    subt[v] = fh(s);
}

int bv = -1, bd = -1;

void change(map<ui64, int> &m, ui64 x, int d) {
    m[x] += d;
    if (!m[x]) m.erase(x);
}

void dfs_up(int v, int p, ui64 up, map<ui64, int> &m) {
//    cerr << v << ' ' << m.size() << '\n';
    if (uax(bd, (int)m.size())) bv = v;
    for (int u: e[v]) {
        if (u == p) continue;
        up += subt[u];
    }
    for (int u: e[v]) {
        if (u == p) continue;
        change(m, subt[u], -1);
        ui64 nup = fh(up - subt[u]);
        change(m, nup, 1);
        dfs_up(u, v, nup, m);
        change(m, subt[u], 1);
        change(m, nup, -1);
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

    int n;
    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs_down(0, -1);

    map<ui64, int> m;
    for1(v, n - 1) ++m[subt[v]];
    dfs_up(0, -1, 0, m);
    cout << bv + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}