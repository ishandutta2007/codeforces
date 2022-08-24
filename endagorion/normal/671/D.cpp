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

struct DSet {
    map<int, i64> dp;
    i64 lazy;

    int size() const {
        return dp.size();
    }

    void swap(DSet &ds) {
        dp.swap(ds.dp);
        ::swap(lazy, ds.lazy);
    }

    void clear() {
        dp.clear();
        lazy = 0;
    }

    void relax() {
        for (auto &[x, y]: dp) y += lazy;
        lazy = 0;
    }

    void cutoff(int h) {
        while (!dp.empty() && prev(dp.end())->fi > h) {
            dp.erase(prev(dp.end()));
        }
    }

    void insert(int h, i64 y) {
        y -= lazy;
        auto it = dp.upper_bound(h);
        if (it != dp.begin()) {
            auto it2 = prev(it);
            if (it2->se <= y) return;
        }
        dp[h] = y;
        while (it != dp.end()) {
            if (it->se >= y) {
                dp.erase(it);
                it = dp.upper_bound(h);
            } else break;
        }
    }

    i64 last() const {
        assert(!dp.empty());
        return dp.rbegin()->se + lazy;
    }

    void merge(DSet ds) {
        if (!size()) {
            swap(ds);
            return;
        }
        if (!ds.size()) return;
        ds.relax();
        i64 low = last(), olow = ds.last();
        lazy += olow;

        for (auto [x, y]: ds.dp) insert(x, y + low);
    }
};

const int maxn = 310000;
vi e[maxn];
int dth[maxn];
vector<pi64> qs[maxn];

void dfs0(int v, int p) {
    for (int u: e[v]) {
        if (u == p) continue;
        dth[u] = dth[v] + 1;
        dfs0(u, v);
    }
}

void dmerge(DSet &a, DSet &b) {
    if (a.size() < b.size()) a.swap(b);
    a.merge(b);
}

DSet dfs(int v, int p) {
    DSet ds;
    ds.insert(dth[v], 0);
    for (auto [u, c]: qs[v]) {
        ds.insert(dth[u], c);
/*        cerr << v << " + " << dth[u] << ' ' << c << ": ";
        for (auto [x, y]: ds.dp) cerr << x << ": " << y + ds.lazy << ", ";
        cerr << '\n';*/
    }
    for (int u: e[v]) {
        if (u == p) continue;
        auto rds = dfs(u, v);
        rds.cutoff(dth[v]);
        if (!rds.size()) {
//            cerr << v << ' ' << u << ": die\n";
            ds.clear();
            break;
        }
        dmerge(ds, rds);
/*        cerr << v << ' ' << u << ": ";
        for (auto [x, y]: ds.dp) cerr << x << ": " << y + ds.lazy << ", ";
        cerr << '\n';*/
    }
/*    cerr << v << ": ";
    for (auto [x, y]: ds.dp) cerr << x << ": " << y + ds.lazy << ", ";
    cerr << '\n';*/
    return ds;
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
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs0(0, -1);

    while (m--) {
        int u, v;
        i64 c;
        cin >> u >> v >> c;
        --u; --v;
        if (dth[u] < dth[v]) swap(u, v);
        qs[u].pb({v, c});
    }
    auto res = dfs(0, -1);
    if (!res.size()) cout << -1 << '\n';
    else cout << res.last() << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}