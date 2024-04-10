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

const int maxn = 3001;
int len[maxn];
vi e[maxn];
int h[maxn];
int vis[maxn];
int clen;

bool dfs0(int v, int p) {
    vis[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        if (!vis[u]) {
            h[u] = h[v] + 1;
            if (dfs0(u, v)) return true;
        } else {
            clen = h[v] - h[u] + 1;
            cerr << "clen = " << clen << '\n';
            return true;
        }
    }
    return false;
}

double ans = 0.0;

int s;
void dfs1(int v, int p, int d) {
//    cerr << s << ' ' << v << ' ' << d << '\n';
    ans += 1.0 / d;
    if (len[v] == -1) len[v] = d;
    else {
        ans -= 2.0 / (d + len[v] + clen - 2);
    }
    vis[v] = 1;
    for (int u: e[v]) if (!vis[u]) dfs1(u, v, d + 1);
    vis[v] = 0;
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
    forn(i, n) {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs0(0, -1);
    forn(i, n) {
        forn(v, n) vis[v] = 0, len[v] = -1;
        s = i;
        dfs1(i, -1, 1);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}