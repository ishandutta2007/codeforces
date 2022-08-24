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

string qtypes = "UMAZQ";

struct TQuery {
    int type;
    int x, y;

    void read() {
        char c;
        cin >> c;
        type = find(all(qtypes), c) - qtypes.begin();
        cin >> x;
        --x;
        if (type < 2) {
            cin >> y;
            --y;
        }
    }
};

const int maxn = 1100000;
int root[2][maxn];
vi e[2][maxn];
int par[2][maxn];
int tin[2][maxn], tout[2][maxn];
int V[2];

void unite(int z, int x, int y) {
    int nv = V[z]++;
    int rx = root[z][x], ry = root[z][y];
//    cerr << z << ' ' << nv << ' ' << rx << ' ' << ry << '\n';
    e[z][nv] = {rx, ry};
    par[z][rx] = par[z][ry] = par[z][nv] = nv;
    root[z][x] = root[z][nv] = nv;
    root[z][y] = -1;
}

int n, m;
int T;

void dfs(int z, int v) {
    tin[z][v] = T;
    if (v < n) ++T;
    for (int u: e[z][v]) dfs(z, u);
    tout[z][v] = T;
//    cerr << "T " << z << ' ' << v << ' ' << tin[z][v] << ' ' << tout[z][v] << '\n';
}

struct TVNode {
    int L, R;
    int l, r;
    int val;
};

TVNode tv[maxn];
int tvc = 0;

#define dvn TVNode &n = tv[node]

int build_vtree(int L, int R) {
    int node = tvc++;
    dvn;
    n = {L, R, -1, -1, -1};
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_vtree(L, M);
        n.r = build_vtree(M, R);
    }
    return node;
}

void vassign(int node, int L, int R, int x) {
    dvn;
    if (max(n.L, L) >= min(n.R, R)) return;
    if (L <= n.L && n.R <= R) {
        n.val = x;
        return;
    }
    vassign(n.l, L, R, x);
    vassign(n.r, L, R, x);
}

int vget(int node, int i) {
    dvn;
    int ans = -1;
    if (i < n.L || i >= n.R) return ans;
    ans = n.val;
    if (n.R - n.L > 1) {
        uax(ans, vget(n.l, i));
        uax(ans, vget(n.r, i));
    }
    return ans;
}

struct TUNode {
    int L, R;
    int l, r;
    vi ts;
    vi64 ps;
};

TUNode tu[maxn];
int tuc = 0;

#define dun TUNode &n = tu[node]

int build_utree(int L, int R) {
    int node = tuc++;
    dun;
    n = {L, R, -1, -1, {}, {0}};
//    cerr << "U " << node << ' ' << n.L << ' ' << n.R << '\n';
    if (R - L > 1) {
        int M = (L + R) / 2;
        n.l = build_utree(L, M);
        n.r = build_utree(M, R);
    }
    return node;
}

void uadd(int node, int L, int R, int t, int x) {
    dun;
//    cerr << "U+ " << node << ' ' << L << ' ' << R << ' ' << n.L << ' ' << n.R << ' ' << t << ' ' << x << '\n';
    if (max(n.L, L) >= min(n.R, R)) return;
    if (L <= n.L && n.R <= R) {
        n.ts.pb(t);
        n.ps.pb(n.ps.back() + x);
        return;
    }
    uadd(n.l, L, R, t, x);
    uadd(n.r, L, R, t, x);
}

i64 usum(int node, int i, int t) {
    dun;
    i64 ans = 0;
    if (i < n.L || i >= n.R) return 0;
    if (!n.ts.empty() && t < n.ts.back()) {
        if (t < n.ts[0]) ans = n.ps.back();
        else {
            int i = lower_bound(all(n.ts), t)- n.ts.begin();
            ans = n.ps.back() - n.ps[i];
        }
    }
//    cerr << "U? " << i << ' ' << t << ' ' << n.L << ' ' << n.R << ' ' << ans << '\n';
    ans += usum(n.l, i, t) + usum(n.r, i, t);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    
    vector<TQuery> qs(m);
    forn(i, m) qs[i].read();

    forn(z, 2) {
        forn(i, n) root[z][i] = i, par[z][i] = i;
        V[z] = n;
        for (auto q: qs) {
            if (q.type == z) unite(z, q.x, q.y);
        }
        T = 0;
        forn(v, V[z]) {
            if (v == par[z][v]) {
//                cerr << z << ' ' << v << '\n';
                dfs(z, v);
            }
        }
        assert(T == n);
    }

    int vroot = build_vtree(0, n);
    int uroot = build_utree(0, n);

    forn(z, 2) forn(v, n) root[z][v] = v;

    forn(i, m) {
        auto q = qs[i];
        if (q.type < 2) root[q.type][q.x] = par[q.type][root[q.type][q.x]];
        if (q.type == 2) {
            int R = root[0][q.x];
//            cerr << "U+ " << tin[0][R] << ' ' << tout[0][R] << ' ' << i << '\n';
            uadd(uroot, tin[0][R], tout[0][R], i, tout[0][R] - tin[0][R]);
        }
        if (q.type == 3) {
            int R = root[1][q.x];
            vassign(vroot, tin[1][R], tout[1][R], i);
        }
        if (q.type == 4) {
            int t = vget(vroot, tin[1][q.x]);
//            cerr << i << ' ' << q.x << ' ' << t << '\n';
            cout << usum(uroot, tin[0][q.x], t) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}