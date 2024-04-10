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
vi e[maxn];
i64 h[maxn];
i64 down[maxn], sdown[maxn], maxh[maxn];

void dfs_down(int v, int p) {
    for (int u: e[v]) {
        if (u == p) continue;
        dfs_down(u, v);
        sdown[v] += down[u];
        uax(maxh[v], maxh[u]);
    }
    down[v] = sdown[v];
    if (h[v] > maxh[v]) {
        down[v] += h[v] - maxh[v];
        maxh[v] = h[v];
    }
//    cerr << "D " << v << ' ' << maxh[v] << ' ' << down[v] << '\n';
}

i64 ans = 1e18;
i64 H;

void dfs_up(int v, int p, i64 uh, i64 udp) {
    i64 S = udp + sdown[v];
//    cerr << v << ' ' << uh << ' ' << udp << ' ' << S << '\n';
    vi64 mxh(2, -1e9);
    mxh[0] = uh;
    for (int u: e[v]) {
        if (u == p) continue;
        i64 h = maxh[u];
        forn(z, 2) if (h > mxh[z]) swap(h, mxh[z]);
    }
    uin(ans, S + H + H - mxh[0]);


    for (int u: e[v]) {
        if (u == p) continue;
        i64 nuh = mxh[maxh[u] == mxh[0]];
        i64 nudp = S - down[u];
        if (h[v] > nuh) {
            nudp += h[v] - nuh;
            nuh = h[v];
        }
        dfs_up(u, v, nuh, nudp);
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
    forn(i, n) cin >> h[i];
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs_down(0, -1);
    H = maxh[0];
    dfs_up(0, -1, 0, 0);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}