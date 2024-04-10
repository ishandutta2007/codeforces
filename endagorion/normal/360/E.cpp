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

struct TEdge {
    int from, to, id;
    int l, r;
};

const int maxn = 11000;
vector<TEdge> e[maxn];
vector<TEdge> edges;

i64 d2r[maxn];
pii prv[maxn];

bool banned[maxn];

int n, m, k;

void dijkstra(int s, bool onlyr, i64 *d, pii *prv) {
    forn(i, n) d[i] = 1e18;
    d[s] = 0;
    set<pii> q = {{0, s}};
    while (!q.empty()) {
        int v = q.begin()->se;
        q.erase(q.begin());
        for (auto &edge: e[v]) {
            int u = edge.to;
            i64 cost;
            if (onlyr || banned[edge.id]) cost = edge.r;
            else cost = edge.l;
            i64 nd = d[v] + cost;
            if (nd < d[u]) {
                q.erase(mp(d[u], u));
                prv[u] = mp(v, edge.id);
                d[u] = nd;
                q.insert(mp(d[u], u));
            }
        }
    }
}

vi set2l;

i64 d1[maxn];

bool can_win(int s1, int f, int p) {
    forn(i, m + k) banned[i] = false;
    while (1) {
        dijkstra(s1, false, d1, prv);
        if (d1[f] > d2r[f] + p) return false;
        bool ok = true;
        vi cset2l(k);
        for (int w = f; w != s1; w = prv[w].fi) {
            int id = prv[w].se;
            int u = prv[w].fi;
            if (id >= m) {
                cset2l[id - m] = 1;
                if (d1[u] > d2r[u] + p) {
                    banned[id] = true;
                    ok = false;
                }
            }
        }
        if (ok) {
            set2l = cset2l;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> k;
    int s1, s2, f;
    cin >> s1 >> s2 >> f;
    --s1; --s2; --f;
    forn(i, m + k) {
        TEdge edge;
        cin >> edge.from >> edge.to >> edge.l;
        --edge.from; --edge.to;
        edge.id = i;
        if (i < m) edge.r = edge.l;
        else cin >> edge.r;
        e[edge.from].pb(edge);
        edges.pb(edge);
    }

    dijkstra(s2, true, d2r, prv);

    if (can_win(s1, f, -1)) cout << "WIN\n";
    else if (can_win(s1, f, 0)) cout << "DRAW\n";
    else {
        cout << "LOSE\n";
        return 0;
    }

    forn(i, k) cout << (set2l[i] ? edges[m + i].l : edges[m + i].r) << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}