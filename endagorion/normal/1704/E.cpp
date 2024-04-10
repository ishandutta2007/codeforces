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

const int maxn = 1100;
const i64 P = 998244353;
i64 a[maxn];
vi e[maxn];
int vis[maxn];
i64 t[maxn];

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    if (e[v].empty()) {
        t[v] = 1;
        return;
    }
    t[v] = 0;
    for (int u: e[v]) {
        dfs(u);
        (t[v] += t[u]) %= P;
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

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        forn(i, n) cin >> a[i];
        forn(i, m) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
        }

        i64 ans = -1;
        forn(i, n) {
            vi nonz(n);
            forn(j, n) nonz[j] = int(a[j] > 0);
            if (!count(all(nonz), 1)) {
                ans = i;
                break;
            }
            forn(j, n) if (nonz[j]) {
                --a[j];
                for (int u: e[j]) ++a[u];
            }
        }

        if (ans == -1) {
            ans = n;
            forn(i, n) if (!vis[i]) dfs(i);
            forn(i, n) (ans += t[i] * a[i]) %= P;
        }

        cout << ans << '\n';
                                         
        forn(i, n) e[i].clear(), vis[i] = 0;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}