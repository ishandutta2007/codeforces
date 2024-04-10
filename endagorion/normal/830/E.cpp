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
vi e[maxn];
int ans[maxn];
int vis[maxn];
int unt = -1;

bool dfs(int v, int p) {
    vis[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        if (vis[u] == 1) {
            unt = u;
            ans[v] = 1;
            return true;
        }
        if (vis[u] == 2) continue;
        if (dfs(u, v)) {
            if (unt != -1) ans[v] = 1;
            if (v == unt) unt = -1;
            return true;
        }
    }
    vis[v] = 2;
    return false;
}

bool dfs3(int v, int p) {
    if (p == -1) {
        for (int u: e[v]) {
            if (dfs3(u, v)) {
                ans[v] = 2;
                for (int w: e[v]) if (w != u) ans[w] = 1;
                return true;
            }
        }
        return false;
    }
    if (e[v].size() >= 3) {
        ans[v] = 2;
        for (int u: e[v]) if (u != p) ans[u] = 1;
        return true;
    }
    if (e[v].size() <= 1) return false;
    for (int u: e[v]) {
        if (u == p) continue;
        if (dfs3(u, v)) {
            ans[v] = 2;
            return true;
        }
    }
    return false;
}

int dfs_len(int v, int p) {
    assert(e[v].size() <= 2);
    if (e[v].size() == 1) return 1;
    for (int u: e[v]) if (u != p) return dfs_len(u, v) + 1;
    assert(false);
    return -1;
}

void dfs_set(int v, int p, i64 V, i64 D) {
    if (V <= 0) return;
    ans[v] = V;
    for (int u: e[v]) if (u != p) dfs_set(u, v, V - D, D);
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
        int n, m;
        cin >> n >> m;
        forn(i, n) e[i].clear();
        forn(i, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            e[v].pb(u);
        }
        forn(i, n) ans[i] = 0;
        forn(i, n) vis[i] = 0;
        bool ok = false;
        forn(i, n) {
            if (vis[i]) continue;
            if (dfs(i, -1)) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            forn(v, n) if (e[v].size() >= 4) {
                ans[v] = 2;
                for (int u: e[v]) {
                    ans[u] = 1;
                }
                ok = true;
                break;
            }
        }

        if (!ok) {
            forn(i, n) vis[i] = 0;
            forn(v, n) if (e[v].size() >= 3 && dfs3(v, -1)) {
                ok = true;
                break;
            }
        }

        if (!ok) {
            forn(i, n) vis[i] = 0;
            forn(v, n) {
                if (e[v].size() < 3) continue;
                vi l;
                for (int u: e[v]) l.pb(min(dfs_len(u, v) + 1, 100));
                i64 Q = 1;
                for (auto x: l) Q *= x;
                i64 sum = 0;
                for (auto x: l) sum += x * (x - 1) / 2 * (Q / x) * (Q / x);
                if (sum < Q * Q) continue;
//                for (int x: l) cerr << x << ' ';
//                cerr << '\n';
//                cerr << Q * Q << ' ' << sum << '\n';
                ok = true;
                ans[v] = Q;
                forn(j, 3) dfs_set(e[v][j], v, Q - Q / l[j], Q / l[j]);
                break;
            }
        }

        if (ok) {
            cout << "YES\n";
            forn(i, n) cout << ans[i] << ' ';
            cout << '\n';
        } else cout << "NO\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}