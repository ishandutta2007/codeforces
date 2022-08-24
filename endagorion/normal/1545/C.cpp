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

const int maxn = 501;
const i64 P = 998244353;
int a[2 * maxn][maxn];
int blockx[2 * maxn];
vi cnt[maxn][maxn];
int ans[2 * maxn];
int vis[2 * maxn];
vi e[2 * maxn];

void dfs(int v, int c) {
    if (vis[v]) return;
    if (!c) ans[v] = 1;
    vis[v] = 1;
    for (int u: e[v]) dfs(u, c ^ 1);
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
        forn(i, 2 * n) forn(j, n) cin >> a[i][j], --a[i][j];
        forn(i, 2 * n) blockx[i] = 0;
        forn(i, 2 * n) ans[i] = 0;
        while (1) {
            forn(i, n) forn(j, n) cnt[i][j].clear();
            forn(i, 2 * n) if (!blockx[i]) {
                forn(j, n) cnt[a[i][j]][j].pb(i);
            }
            int remI = -1;
            forn(i, n) forn(j, n) if (cnt[i][j].size() == 1) remI = cnt[i][j][0];
            if (remI == -1) break;
            ans[remI] = 1;
            forn(i, 2 * n) if (!blockx[i]) {
                forn(j, n) blockx[i] |= (a[i][j] == a[remI][j]);
            }
        }

        forn(i, 2 * n) e[i].clear();
        forn(i, n) forn(j, n) {
            auto &v = cnt[i][j];
            if (v.empty()) continue;
            assert(v.size() == 2);
            forn(z, 2) e[v[z]].pb(v[z ^ 1]);
        }

        forn(i, 2 * n) vis[i] = 0;
        i64 C = 1;
        forn(i, 2 * n) {
            if (blockx[i] || vis[i]) continue;
            (C *= 2) %= P;
            dfs(i, 0);
        }
        cout << C << '\n';
        forn(i, 2 * n) if (ans[i]) cout << i + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}