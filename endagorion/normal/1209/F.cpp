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

const int maxn = 1100000;
const i64 P = 1000000000 + 7;
vector<pii> e[maxn];
int cl[maxn];
i64 ans[maxn];
pii dist[maxn];
int V;

void add_edge(int v, int u, vi &digs) {
    int lv = v;
    forn(i, digs.size() - 1) {
        int nv = V++;
        e[lv].pb({nv, digs[i]});
        lv = nv;
    }
    e[lv].pb({u, digs.back()});
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
    V = n;
    for1(i, m) {
        int v, u;
        cin >> v >> u;
        --v; --u;
        vi digs;
        for (int ii = i; ii; ii /= 10) digs.pb(ii % 10);
        reverse(all(digs));
        add_edge(v, u, digs);
        add_edge(u, v, digs);
    }
    
    forn(i, V) cl[i] = -1, dist[i] = {1e9, -1};
    cl[0] = 0;
    vi L = {0};
    int C = 1;
    while (!L.empty()) {
        vi NL;
        for (int v: L) {
            for (auto w: e[v]) {
                int u = w.fi, d = w.se;
                if (cl[u] != -1) continue;
                if (dist[u].fi > 1e8) NL.pb(u);
                uin(dist[u], {cl[v], d});
            }
        }
        sort(all(NL), [&](int v, int u){return dist[v] < dist[u];});
//        for (int v: NL) cerr << v << ' '; 
//        cerr << '\n';
        int l = 0;
        while (l < NL.size()) {
            int v = NL[l];
            pii p = dist[v];
            ans[C] = (ans[p.fi] * 10 + p.se) % P;
            int r = l;
            while (r < NL.size() && dist[NL[l]] == dist[NL[r]]) {
                cl[NL[r]] = C;
                ++r;
            }
            l = r;
            ++C;
        }
        L = NL;
    }
    for1(i, n - 1) cout << ans[cl[i]] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}