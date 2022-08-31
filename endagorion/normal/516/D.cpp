#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 110000;
vector<pii> e[MAXN], hd[MAXN];
vi hdd[MAXN];
i64 dists[MAXN];

void farthest(int v, int p, i64 d, int &bv, i64 &bd) {
    if (d > bd) {
        bd = d;
        bv = v;
    }
    for (pii pp: e[v]) {
        int u = pp.fi;
        if (u == p) continue;
        farthest(u, v, d + pp.se, bv, bd);
    }
}

bool hang_dfs(int v, int p, int t, i64 D, vi &path, vi64 &ds) {
    if (v == t) {
        path.pb(v);
        ds.pb(D);
        return true;
    }
    bool ok = false;
    for (pii pp: e[v]) {
        int u = pp.fi;
        if (u == p) continue;
        if (hang_dfs(u, v, t, D + pp.se, path, ds)) ok = true;
        else hd[v].pb(pp);
    }
    if (ok) {
        path.pb(v);
        ds.pb(D);
    }
    return ok;
}

void set_dists(int v, i64 D) {
    dists[v] = D;
    for (pii pp: hd[v]) {
        set_dists(pp.fi, D + pp.se);
    }
}

int par[MAXN];

void set_p(int v, int p) {
    par[v] = p;
    for (pii pp: e[v]) {
        if (pp.fi == p) continue;
        hdd[v].pb(pp.fi);
        set_p(pp.fi, v);
    }
}

int dp[MAXN], cs[MAXN];

int get_dp(int v) {
    if (dp[v] == v) return v;
    return dp[v] = get_dp(dp[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    forn(i, N - 1) {
        int x, y, v;
        cin >> x >> y >> v;
        --x; --y;
        e[x].pb(mp(y, v));
        e[y].pb(mp(x, v));
    }
    int S = -1;
    i64 D = -1;
    farthest(0, -1, 0, S, D);
    int T = -1;
    D = -1;
    farthest(S, -1, 0, T, D);

    vi path;
    vi64 ds, mds;
    hang_dfs(S, -1, T, 0, path, ds);
    i64 MD = ds[0];
    mds = ds;
    forn(i, ds.size()) {
        mds[i] = max(mds[i], MD - mds[i]);
        set_dists(path[i], mds[i]);
    }
    int minv = path[min_element(all(mds)) - mds.begin()];
    set_p(minv, -1);
    vector<pair<i64, int> > q(N);
    forn(i, N) q[i] = mp(dists[i], i);
    sort(rall(q));
//    forn(i, N) cout << q[i].fi << ' ' << q[i].se << '\n';

    int K;
    cin >> K;
    forn(k, K) {
        i64 L;
        cin >> L;
        forn(i, N) dp[i] = i, cs[i] = 1;
        int i1 = 0, i2 = 0;
        int ans = 0;
        while (i1 < N) {
            if (q[i1].fi + L >= q[i2].fi) {
                int v = q[i1++].se;
                for (int u: hdd[v]) {
                    dp[u] = v;
                    cs[v] += cs[u];
                }
                ans = max(ans, cs[v]);
            } else {
                int v = q[i2++].se;
                --cs[get_dp(v)];
            }
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}