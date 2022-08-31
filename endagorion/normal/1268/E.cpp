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

struct TEdge {
    int from, to;
};

vector<TEdge> edges;
vi e[maxn];
int tin[maxn], up[maxn], vis[maxn];
int hapv[maxn], hape[maxn];
int part[maxn];
int n, m;

vi st;
int T = 0;

void dfs(int v, int p) {
    tin[v] = T++;
    up[v] = tin[v];
    vis[v] = 1;

    for (int ei: e[v]) {
        if (ei / 2 == p) continue;
        int u = edges[ei].to;
        if (vis[u] == 1) st.pb(ei), uin(up[v], tin[u]);
        else if (vis[u] == 0) {
            st.pb(ei);
            dfs(u, ei / 2);
            uin(up[v], up[u]);
            if (up[u] >= tin[v]) {
                vi C;
                while (1) {
                    C.pb(st.back());
                    st.pop_back();
                    if (C.back() == ei) break;
                }
                if (C.size() != 1) {
                    int x = min_element(all(C)) - C.begin();
                    int y = max_element(all(C)) - C.begin();
                    int ex = 0;
                    forn(i, C.size()) {
                        int u = C[i], v = C[(i + 1) % C.size()], w = C[(i + 2) % C.size()];
                        if ((v < u) == (v < w)) ++ex;
                    }
                    if (ex == 2) part[C[x] / 2] = C[y] / 2;
                }
            }
        }
    }
    vis[v] = 2;
}

void addEdge(int v, int u) {
    e[v].pb(edges.size());
    edges.pb({v, u});
    e[u].pb(edges.size());
    edges.pb({u, v});
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
        int u, v;
        cin >> u >> v;
        --u; --v;
        addEdge(u, v);
    }

    forn(i, m) part[i] = -1;
    dfs(0, -1);

    forn(i, n) hapv[i] = 1;
    ford(i, m) {
        int v = edges[2 * i].from, u = edges[2 * i].to;
        int s = hapv[v] + hapv[u];
        hape[i] = s;
        if (part[i] != -1) s -= hape[part[i]];
        hapv[v] = hapv[u] = s;
    }

    forn(i, n) cout << hapv[i] - 1 << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}