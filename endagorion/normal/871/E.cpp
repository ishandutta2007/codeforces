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

const int maxn = 50000;
int root[maxn], droot[maxn];
vi e[maxn];

void dfsD(int v, int p, int d, vi &D) {
    D[v] = d;
    for (int u: e[v]) {
        if (u == p) continue;
        dfsD(u, v, d + 1, D);
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

    int n, k;
    cin >> n >> k;
    vvi dist(k, vi(n));
    forn(i, k) forn(j, n) cin >> dist[i][j];

    vi vs(k);
    bool ok = true;
    forn(i, k) {
        ok &= count(all(dist[i]), 0) == 1;
        if (!ok) break;
        vs[i] = find(all(dist[i]), 0) - dist[i].begin();
    }

    vector<pii> es;

    if (ok) forn(i, k) {
//        cerr << i << '\n';
//        forn(v, n) cerr << v << ' ' << root[v] << ' ' << droot[v] << '\n';
        if (i == 0) {
            forn(v, n) {
                root[v] = vs[0];
                droot[v] = dist[0][v];
            }
            continue;
        }

        if (!ok) break;

        int v = vs[i];
        vi &D = dist[i];
        int to = root[v], dto = droot[v];
        vvi repr(dto + 1);
        forn(u, n) {
            if (root[u] != to) continue;
            if (D[u] + droot[u] == dto) repr[droot[u]].pb(u);
        }
        forn(i, dto + 1) if (repr[i].size() != 1) ok = false;
        if (!ok) break;
        forn(i, dto) es.pb(mp(repr[i][0], repr[i + 1][0]));
        forn(u, n) {
            if (root[u] != to) continue;
            int dd = (D[u] + droot[u] - dto);
            if (dd < 0 || dd & 1 || dd / 2 > droot[u]) {
                ok = false;
                break;
            }
            dd /= 2;
//            cerr << u << ": " << root[u] << ' ' << droot[u] << " -> ";
            root[u] = repr[droot[u] - dd][0];
            droot[u] = dd;
//            cerr << root[u] << ' ' << droot[u] << "\n";
        }
    }

    if (ok) {
        map<pii, int> repr;
        forn(v, n) repr[mp(root[v], droot[v])] = v;
        forn(v, n) if (droot[v]) {
            pii p = mp(root[v], droot[v]);
            --p.se;
            if (repr.count(p)) es.pb(mp(v, repr[p]));
        }
    }

//    for (auto [x, y]: es) cerr << x << ' ' << y << '\n';

    ok &= es.size() == n - 1;
    if (ok) {
        for (auto [x, y]: es) {
            e[x].pb(y);
            e[y].pb(x);
        }
        forn(i, k) {
            vi D(n);
            dfsD(vs[i], -1, 0,  D);
            ok &= D == dist[i];
        }
    }

    if (ok) for (auto [x, y]: es) cout << x + 1 << ' ' << y + 1 << '\n';
    else cout << -1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}