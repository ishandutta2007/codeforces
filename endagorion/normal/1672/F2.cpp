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
int vis[maxn];

bool dfs(int v) {
    vis[v] = 1;
    for (int u: e[v]) {
        if (vis[u] == 1) return true;
        if (!vis[u] && dfs(u)) return true;
    }
    vis[v] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n), b(n);
        forn(i, n) cin >> a[i], --a[i];
        forn(i, n) cin >> b[i], --b[i];
        vi cnt(n);
        for (int x: a) ++cnt[x];
        int mx = max_element(all(cnt)) - cnt.begin();
        forn(i, n) e[i].clear();
        forn(i, n) if (a[i] != mx && b[i] != mx) e[a[i]].pb(b[i]);
        bool ok = true;
        forn(i, n) vis[i] = 0;
        forn(i, n) if (!vis[i] && dfs(i)) ok = false;
        cout << (ok ? "AC" : "WA") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}