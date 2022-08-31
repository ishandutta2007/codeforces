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

const int maxn = 110000;
int par[maxn];

int root(int v) {
    return v == par[v] ? v : par[v] = root(par[v]);
}

vi te[maxn], de[maxn];
int tin[maxn], tout[maxn];
int T;

void dfs0(int v, int p = -1) {
    tin[v] = T++;
    for (int u: te[v]) {
        if (u == p) continue;
        de[v].pb(u);
        dfs0(u, v);
    }
    tout[v] = T;
}

vector<pii> re;

int delta[maxn];

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
    forn(i, n) par[i] = i;
    
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (root(u) == root(v)) {
            re.pb({u, v});
        } else {
            te[u].pb(v);
            te[v].pb(u);
            par[root(u)] = root(v);
        }
    }

    dfs0(0, -1);
    for (auto [u, v]: re) {
        if (tin[u] > tin[v]) swap(u, v);
        ++delta[tin[v]];
        --delta[tout[v]];
//        cerr << tin[u] << ' ' << tout[u] << ' ' << tin[v] << ' ' << tout[v] << '\n';
        if (tout[u] <= tin[v]) {
            ++delta[tin[u]];
            --delta[tout[u]];
        } else {
            int L = 0, R = de[u].size();
            while (R - L > 1) {
                int M = (L + R) / 2;
                (tin[de[u][M]] <= tin[v] ? L : R) = M;
            }
            ++delta[0];
            --delta[n];
//            cerr << tin[de[u][L]] << ' ' << tout[de[u][L]] << '\n';
            --delta[tin[de[u][L]]];
            ++delta[tout[de[u][L]]];
        }
    }

    forn(i, n) delta[i + 1] += delta[i];
    forn(i, n) cout << (delta[tin[i]] == (int)re.size() ? 1 : 0);
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}