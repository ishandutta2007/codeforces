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

const int maxn = 210000, LOG = 20;
vi e[maxn];
int up[LOG + 1][maxn], pup[LOG + 1][maxn];
int tin[maxn], tout[maxn];
int mtinp[maxn];
int T = 0;
int h[maxn];

vi ord;

void dfs0(int v, int p) {
    up[0][v] = p;
    tin[v] = T++;
    ord.pb(v);
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs0(u, v);
    }
    tout[v] = T;
}

int jmp(int v, int h) {
    forn(j, LOG) {
        if (!((h >> j) & 1)) continue;
        v = up[j][v];
    }
    return v;
}

int lca(int v, int u) {
    if (h[v] < h[u]) swap(v, u);
    v = jmp(v, h[v] - h[u]);
    if (v == u) return v;
    ford(j, LOG) {
        int vv = up[j][v], uu = up[j][u];
        if (vv != uu) v = vv, u = uu;
    }
    return up[0][v];
}

struct TEvent {
    int x, y1, y2;
    int id;

    bool operator<(const TEvent &ev) const {
        if (x != ev.x) return x < ev.x;
        return id > ev.id;
    }
};

int pjmp(int &t, int tu) {
    int h = 0;
    ford(j, LOG) {
        int tt = pup[j][t];
        if (tt > tu) t = tt, h += 1 << j;
    }
    return h;
}

int fenw[maxn];

void fadd(int i, int x) {
    for (; i < maxn; i |= i + 1) fenw[i] += x;
}

int fsum(int i) {
    --i;
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) s += fenw[i];
    return s;
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
    for1(i, n - 1) {
        int p;
        cin >> p;
        --p;
        e[p].pb(i);
    }

    dfs0(0, 0);
    forn(j, LOG) forn(v, n) up[j + 1][v] = up[j][up[j][v]];

    forn(v, n) mtinp[v] = tin[v];
    vector<TEvent> evs;
    int m;
    cin >> m;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (tin[u] > tin[v]) swap(u, v);
        int w = lca(u, v);
//        cerr << u << ' ' << v << ' ' << w << '\n';
        uin(mtinp[u], tin[w]);
        uin(mtinp[v], tin[w]);
        evs.pb({tin[u], tin[v], -1, -1});
    }

    ford(v, n) {
        for (int u: e[v]) uin(mtinp[v], mtinp[u]);
        pup[0][tin[v]] = mtinp[v];
    }

//    forn(v, n) cerr << v << ' ' << tin[v] << ' ' << pup[0][tin[v]] << '\n';

    forn(j, LOG) forn(t, n) pup[j + 1][t] = pup[j][pup[j][t]];

    int q;
    cin >> q;
    vi ans(q);
    vi ins(q, 1000);
    forn(i, q) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (tin[u] > tin[v]) swap(u, v);
        int w = lca(u, v);
        u = tin[u]; v = tin[v]; w = tin[w];
//        cerr << u << ' ' << v << ' ' << w << '\n';
        if (u == w) {
            ans[i] = pjmp(v, w);
            if (pup[0][v] <= w) ++ans[i];
            else ans[i] = -1;
            continue;
        }
        ans[i] = pjmp(u, w);
        ans[i] += pjmp(v, w);
        if (pup[0][u] > w || pup[0][v] > w) {
            ans[i] = -1;
            continue;
        }
        ++ans[i];
        evs.pb({u, v, tout[ord[v]], 2 * i});
        evs.pb({tout[ord[u]], v, tout[ord[v]], 2 * i + 1});
        ins[i] = 0;
    }

    sort(all(evs));
    
    for (auto [x, y1, y2, id]: evs) {
//        cerr << x << ' ' << y1 << ' ' << y2 << ' ' << id << '\n';
        if (y2 == -1) fadd(y1, 1);
        else {
            ins[id / 2] += (fsum(y2) - fsum(y1)) * (id & 1 ? 1 : -1);
        }
    }

    forn(i, q) {
        if (!ins[i]) ++ans[i];
//        cout << ans[i] << ' ' << ins[i] << '\n';
        cout << ans[i] << '\n';
    }


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}