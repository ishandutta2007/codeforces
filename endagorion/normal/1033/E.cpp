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

int n;

int query(vi v) {
    if (v.size() <= 1) return 0;
    cout << "? " << v.size();
    for (int x: v) cout << ' ' << x + 1;
    cout << endl;
    int ans;
    cin >> ans;
    return ans;
}

int queryv(int v, vi us) {
    int ans1 = query(us);
    us.pb(v);
    return query(us) - ans1;
}

int any_edge(int v, vi us) {
    if (!queryv(v, us)) return -1;
    int L = 0, R = us.size();
    while (R - L > 1) {
        int M = (L + R) / 2;
        (queryv(v, vi(us.begin(), us.begin() + M)) ? R : L) = M;
    }
    return us[L];
}

const int maxn = 601;
int par[maxn];
int vis[maxn], col[maxn];

vi unvis() {
    vi res;
    forn(i, n) if (!vis[i]) res.pb(i);
    return res;
}

vi oddpar(int v) {
    vi pars;
    for (int u = v, h = 0; u != -1; u = par[u], ++h) if (h > 1 && !(h % 2)) pars.pb(u);
/*    cerr << v << ": ";
    for (int u: pars) cerr << u << ' ';
    cerr << '\n';*/
    return pars;
}

vi get_cycle(int v, int u) {
    vi cycle;
    for (; v != u; v = par[v]) cycle.pb(v);
    cycle.pb(u);
    return cycle;
}

pii ans;

bool dfs(int v) {
    if (vis[v]) return false;
    vis[v] = 1;
    {
        int u = any_edge(v, oddpar(v));
        if (u != -1) {
            ans = {v, u};
            return true;
        }
    }
    while (1) {
        int u = any_edge(v, unvis());
        if (u == -1) break;
        par[u] = v;
        col[u] = col[v] ^ 1;
        if (dfs(u)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n) par[i] = -1;
    if (dfs(0)) {
        auto [v, u] = ans;
        auto cycle = get_cycle(v, u);
        cout << " N " << cycle.size() << '\n';
        for (int v: cycle) cout << v + 1 << ' '; 
        cout << '\n';
    } else {
        int c0 = count(col, col + n, 0);
        cout << "Y " << c0 << '\n';
        forn(i, n) if (!col[i]) cout << i + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}