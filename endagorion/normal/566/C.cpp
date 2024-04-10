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
ld w[maxn];
int sz[maxn];
int ban[maxn];

vector<pii> e[maxn];

ld ans = 1e36;
int bv = -1;

vi subt;

void dfs_sz(int v, int p) {
    if (ban[v]) {
        sz[v] = 0;
        return;
    }
    subt.pb(v);
    sz[v] = 1;
    for (auto [u, l]: e[v]) {
        if (u == p) continue;
        dfs_sz(u, v);
        sz[v] += sz[u];
    }
}

ld dfs_ans(int v, int p, ld D) {
    ld ans = w[v] * D * sqrtl(D);
    for (auto [u, l]: e[v]) {
        if (u == p) continue;
        ans += dfs_ans(u, v, D + l);
    }
    return ans;
}

void try_ans(int v) {
    ld res = dfs_ans(v, -1, 0);
    if (uin(ans, res)) bv = v;
}

ld dfs_deriv(int v, int p, int D) {
    ld deriv = w[v] * sqrtl(D);
    for (auto [u, l]: e[v]) {
        if (u == p) continue;
        deriv += dfs_deriv(u, v, D + l);
    }
    return deriv;
}

void dfs_centr(int v) {
    if (ban[v]) return;
    subt.clear();
    dfs_sz(v, -1);
//    if (subt.size() == 1) return;
    int C = -1;
    for (int u: subt) {
        bool is_centr = 2 * (sz[v] - sz[u]) <= sz[v];
        for (auto [w, l]: e[u]) {
            if (sz[w] < sz[u]) is_centr &= 2 * sz[w] <= sz[v];
        }
        if (is_centr) C = u;
    }

    try_ans(C);

    ld max_deriv = -1e18;
    int bu = -1;
    for (auto [u, l]: e[C]) {
        ld deriv = dfs_deriv(u, C, l);
//        cerr << C << ' ' << u << ' ' << deriv << '\n';
        if (uax(max_deriv, deriv)) bu = u;
    }

    ban[C] = 1;
    if (bu != -1) dfs_centr(bu);
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
    forn(i, n) cin >> w[i];
    forn(i, n - 1) {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        e[u].pb({v, l});
        e[v].pb({u, l});
    }

    dfs_centr(0);

    cout << bv + 1 << ' ' << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}