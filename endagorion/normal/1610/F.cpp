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

const int maxn = 210000;
struct TEdge {
    int from, to, w;
};

vector<TEdge> edges;
vi e[maxn];
vi ew[3][maxn];
int dw[maxn], d[3][maxn];
int odd[maxn];
int dir[maxn];
vi rest;
int score[maxn];
int used[maxn];

int n, m;

void direct(int x) {
    int i = x / 2, d = x & 1;
    assert(dir[i] == -1 || dir[i] != d);
    if (dir[i] != -1 || i >= m) return;
    dir[i] = d;
    auto [u, v, w] = edges[x];
    score[u] += w;
    score[v] -= w;
}

void add_edge(int from, int to, int w) {
    int id = edges.size();
    dir[id / 2] = -1;
    dw[from] += w;
    dw[to] += w;
    edges.pb({from, to, w});
    e[from].pb(id);
    edges.pb({to, from, w});
    e[to].pb(id + 1);

    if (w == 1) {
        ew[1][from].pb(id), ew[1][to].pb(id + 1);
        ++d[1][from]; ++d[1][to];
    }
    
}

bool euler(int v, int w, int s, vi &es, bool odd) {
    if (odd && s != v && d[w][v] % 2 == 0) return true;
    while (!ew[w][v].empty()) {
        auto id = ew[w][v].back();
        ew[w][v].pop_back();
        if (used[id / 2]) continue;
        used[id / 2] = true;
        es.pb(id);
        auto u = edges[id].to;
        --d[w][v];
        --d[w][u];
//        cerr << v << ' ' << u << '\n';
        if (euler(u, w, s, es, odd)) return true;
        if (odd) break;
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

    cin >> n >> m;
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        add_edge(u, v, w);
    }

    int ans1 = 0;
    forn(i, n) {
        odd[i] = dw[i] & 1;
        ans1 += odd[i];
    }

    forn(i, m) dir[i] = -1;

    forn(i, m) {
        auto [u, v, w] = edges[2 * i];
        if (w == 2) {
            if (!odd[u] && !odd[v]) direct(2 * i);
            else if (odd[u] && odd[v]) {
                ++d[2][u]; ++d[2][v];
//                cerr << 2 << ' ' << u << ' ' << v << '\n';
                ew[2][u].pb(2 * i);
                ew[2][v].pb(2 * i + 1);
            } else rest.pb(i);
        }
    }

    vvi ps;
//    forn(i, n) cerr << d[2][i] << ' ' << ew[2][i].size() << '\n';
//    cerr << '\n';

    forn(i, n) {
        if (d[2][i] % 2 == 0) continue;
        vi es;
        euler(i, 2, i, es, true);
        assert(!es.empty());
        int j = edges[es.back()].to;
        ps.pb({es});
//        cerr << i << ' ' << j << ' ' << d[1][i] << ' ' << d[1][j] << '\n';
        assert(d[1][i] & d[1][j] & 1);
        add_edge(i, j, 1);
    }

//    forn(i, n) cerr << d[2][i] << ' ';
//    cerr << '\n';

    forn(i, n) {
//        cerr << i << ' ' << d[2][i] << ' ' << ew[2][i].size() << '\n';
        assert(d[2][i] % 2 == 0);
        vi es;
        euler(i, 2, i, es, false);
        for (int id: es) direct(id);
    }

//    forn(i, n) cerr << d[2][i] << ' ';
//    cerr << '\n';

    int v = -1;

    forn(i, n) {
        if (d[1][i] % 2 == 0) continue;
//        cerr << i << '\n';
        if (v == -1) v = i;
        else {
            add_edge(i, v, 1);
            v = -1;
        }
    }
    assert(v == -1);

    forn(i, n) {
        assert(d[1][i] % 2 == 0);
        vi es;
        euler(i, 1, i, es, false);
        for (int id: es) direct(id);
    }

/*    forn(i, n) cerr << score[i] << ' ';
    cerr << '\n';
    forn(i, m) cerr << dir[i] << ' ';
    cerr << '\n';*/

    for (auto p: ps) {
        int i = edges[p[0]].from;
        int j = edges[p.back()].to;
//        cerr << i << ' ' << j << '\n';
        assert(abs(score[i]) == 1 && score[j] == -score[i]);
        int rev(score[i] == 1);
        for (int id: p) direct(id ^ rev);
    }

    for (int id: rest) {
        auto [from, to, w] = edges[2 * id];
        direct((2 * id) ^ int(score[from] == 1 || score[to] == -1));
    }

    forn(i, m) assert(dir[i] != -1);
    int ans2 = 0;
    forn(i, n) ans2 += int(abs(score[i]) == 1);
    assert(ans1 == ans2);
    
    cout << ans1 << '\n';
    forn(i, m) cout << dir[i] + 1;
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}