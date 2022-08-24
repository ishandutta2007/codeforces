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

const int maxn = 310000;
vi e[maxn];
int x[maxn], gr[maxn], par[maxn];
int xgr;

void dfs(int v, int p) {
    par[v] = p;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        x[v] ^= x[u] + 1;
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

    int n;
    cin >> n;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(0, -1);
    gr[0] = 1;
    xgr = x[0];

    vi ans(n);
    ans[0] = xgr ? 1 : 2;
    for1(i, n - 1) {
        vi path;
        for (int v = i; !gr[v]; v = par[v]) path.pb(v);
        reverse(all(path));
        for (int v: path) {
            gr[v] = 1;
            xgr ^= (x[v] + 1) ^ x[v] ^ 1;
        }
        ans[i] = (xgr ? 1 : 2);
    }
    for (int x: ans) cout << x;
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}