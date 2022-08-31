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

const int maxn = 1010000;

int ans[maxn];
vi d[maxn];
vvi ev[maxn];
int h[maxn];
int bar[maxn];
vi ds[maxn];
vi e[maxn];

void add_ds(int v, int u) {
    for (int &x: ds[v]) if (u > x) swap(u, x);
    if (ds[v].size() < 2) ds[v].pb(u);
}

int max_exc(int v, int h) {
    for (int x: ds[v]) {
        if (x == h) h = -1;
        else return x;
    }
    return 0;
}

void dfs0(int v, int p) {
    for (int u: e[v]) {
        if (u == p) continue;
        dfs0(u, v);
        add_ds(v, h[u] + 1);
        uax(h[v], h[u] + 1);
    }
}

int n;

void dfs(int v, int p, int up) {
    for (int u: e[v]) if (u != p) d[v].pb(h[u] + 1);
    uax(ans[1], (int)e[v].size() + 1);
    sort(all(d[v]));
    if (p != -1) {
        forn(i, d[v].size()) {
            int x = d[v][i];
            int j = upper_bound(all(d[p]), x) - d[p].begin();
            int cnt = d[v].size() - i;
            uax(ans[2 * x], cnt + (int)d[p].size() - j - (bar[p] >= j ? 1 : 0));
//            cerr << "+ " << v << ' ' << x << ' ' << j << ' ' << d[p].size() << ' ' << bar[p] << ' ' << cnt << ' ' << ans[2 * x] << '\n';
            if (bar[p] < j) {
                ev[p][0].pb(cnt - 1);
                ev[p][bar[p]].pb(-(cnt - 1));
                ev[p][bar[p] + 1].pb(cnt);
                ev[p][j].pb(-cnt);
            } else {
                ev[p][0].pb(cnt - 1);
                ev[p][j].pb(-(cnt - 1));
            }
        }
    }

    if (up) d[v].pb(up);
    sort(all(d[v]));
    forn(i, d[v].size()) {
        int x = d[v][i];
        uax(ans[2 * x], (int)d[v].size() - i);
        uax(ans[2 * x - 1], (int)d[v].size() - i);
        if (i + 1 < d[v].size() && d[v][i + 1] > d[v][i]) uax(ans[2 * x + 1], (int)d[v].size() - i);
        if (i && d[v][i - 1] == d[v][i] - 1) uax(ans[2 * x - 1], (int)d[v].size() - i + 1);
    }

/*    cerr << v << ' ';
    for1(i, n) cerr << ans[i] << ' ';
    cerr << '\n';*/

    ev[v].resize(d[v].size() + 1);
    for (int u: e[v]) {
        if (u == p) continue;
        bar[v] = lower_bound(all(d[v]), h[u] + 1) - d[v].begin();
        dfs(u, v, max(up + 1, max_exc(v, h[u] + 1) + 1));
    }

    multiset<int> hs = {0};
    forn(i, d[v].size()) {
        sort(rall(ev[v][i]));
        for (int x: ev[v][i]) {
            if (!x) continue;
            if (x > 0) hs.insert(x);
            else hs.erase(hs.find(-x));
        }
        uax(ans[2 * d[v][i]], *hs.rbegin() + (int)d[v].size() - i);
    }

/*    cerr << v << ' ';
    for1(i, n) cerr << ans[i] << ' ';
    cerr << '\n';*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs0(0, -1);
    dfs(0, -1, 0);

    forn(i, n + 1) uax(ans[i], 1);
    for (int x = n; x >= 2; --x) uax(ans[x - 2], ans[x]);
    for1(i, n) cout << ans[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}