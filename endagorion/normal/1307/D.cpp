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

int n, m, k;
    
vi bfs(int s) {
    vi d(n, 1e9);
    d[s] = 0;
    vi q = {s};
    forn(cur, q.size()) {
        int v = q[cur];
        for (int u: e[v]) {
            if (d[u] < 1e8) continue;
            d[u] = d[v] + 1;
            q.pb(u);
        }
    }
    return d;
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
    vi sp(k);
    forn(i, k) cin >> sp[i], --sp[i];
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    vi d1 = bfs(0);
    vi d2 = bfs(n - 1);

    int ans = -1;
    sort(all(sp), [&](int u, int v){return d2[u] - d1[u] > d2[v] - d1[v];});

    int maxd = -1e9;
    for (int v: sp) {
        uax(ans, d2[v] + maxd + 1);
        uax(maxd, d1[v]);
    }
    uin(ans, d1[n - 1]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}