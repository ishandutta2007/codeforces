#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

const int D = 1000, maxn = 110000;
int sex[maxn], f[maxn], par[maxn];
int spec[maxn], root[maxn], used[maxn];
int cnt[2][maxn];
i64 ans[maxn];
pii qs[maxn];
vi spec_qs[maxn], qs2[maxn];
vi e[maxn];

int dfs_spec(int v, int p) {
    par[v] = p;
    int h = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        uax(h, dfs_spec(u, v));
    }
    if (h > D) {
        h = 0;
        spec[v] = 1;
    }
    return h + 1;
}

void dfs_root(int v, int p) {
    if (spec[v]) root[v] = v;
    for (int u: e[v]) {
        if (u == p) continue;
        root[u] = root[v];
        dfs_root(u, v);
    }
}

i64 total = 0;

void change(int i, int delta) {
    total += delta * cnt[sex[i] ^ 1][f[i]];
    cnt[sex[i]][f[i]] += delta;
}

void dfs(int v, int p) {
    change(v, 1);
    ++used[v];
    for (int x: qs2[v]) {
        int y = qs[x].fi;
        int w = y;
        while (!used[w]) change(w, 1), w = par[w];
        w = par[w];
        while (w != par[root[y]]) change(w, -1), w = par[w];
        ans[x] = total;
        w = y;
        while (!used[w]) change(w, -1), w = par[w];
        w = par[w];
        while (w != par[root[y]]) change(w, 1), w = par[w];
    }
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
    }
    change(v, -1);
    --used[v];
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
    forn(i, n) cin >> sex[i];
    forn(i, n) cin >> f[i];
    forn(i, n - 1) {
        int x, y;
        cin >> x >> y;
//        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    vi vals(f, f + n);
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    forn(i, n) f[i] = lower_bound(all(vals), f[i]) - vals.begin();

    dfs_spec(0, -1);
    spec[0] = 1;
    dfs_root(0, -1);

    int q;
    cin >> q;
    forn(i, q) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        qs[i] = {x, y};
        spec_qs[root[x]].pb(i);
        ans[i] = -1;
    }

    cerr << "dfs\n";
    forn(i, n) if (spec[i]) {
        for (int x: spec_qs[i]) if (ans[x] == -1) {
            qs2[qs[x].se].pb(x);
        }
        dfs(i, -1);
        for (int x: spec_qs[i]) qs2[qs[x].se].clear();
    }

    forn(i, q) cout << ans[i] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}