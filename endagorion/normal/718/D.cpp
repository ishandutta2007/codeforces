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
int w[maxn];
vi e[maxn];

void dfsw(int v, int p) {
    w[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsw(u, v);
        w[v] += w[u];
    }
}

map<vi, int> cl;

int getcl(vi v) {
    sort(all(v));
    if (cl.count(v)) return cl[v];
    int z = cl.size();
    cl[v] = z;
    return z;
}

int id[maxn];

void dfs_cl(int v, int p) {
    vi ch;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_cl(u, v);
        ch.pb(id[u]);
    }
    id[v] = getcl(ch);
}

int ans = 0;

void dfs_count(int v, int p) {
    if (e[v].size() < 4) ++ans;
    set<int> vis;
    for (int u: e[v]) {
        if (u == p) continue;
        if (vis.count(id[u])) continue;
        vis.insert(id[u]);
        dfs_count(u, v);
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


    dfsw(0, -1);

    vi cs;
    forn(v, n) {
        bool isC = 2 * (n - w[v]) <= n;
        for (int u: e[v]) {
            if (w[u] > w[v]) continue;
            isC &= 2 * w[u] <= n;
        }
        if (isC) cs.pb(v);
    }

    assert(!cs.empty());

    if (cs.size() == 1) {
        dfs_cl(cs[0], -1);
        dfs_count(cs[0], -1);
    } else {
        forn(z, 2) dfs_cl(cs[z], cs[z ^ 1]);
        dfs_count(cs[0], cs[1]);
        if (id[cs[0]] != id[cs[1]]) dfs_count(cs[1], cs[0]);
    }

    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}