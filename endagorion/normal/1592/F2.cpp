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
int a[maxn][maxn];
vi e[maxn];
int vis[maxn], rm[maxn];

bool kuhn(int v) {
    if (v == -1) return true;
    if (vis[v]) return false;
    vis[v] = 1;
    for (int u: e[v]) if (kuhn(rm[u])) {
        rm[u] = v;
        return true;
    }
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

    int n, m;
    cin >> n >> m;
    forn(i, n) {
        string s;
        cin >> s;
        forn(j, m) {
            int x = s[j] == 'W' ? 0 : 1;
            forn(di, 2) forn(dj, 2) if (i >= di && j >= dj) a[i - di][j - dj] ^= x;
        }
    }

/*    forn(i, n) {
        forn(j, m) cerr << a[i][j];
        cerr << '\n';
    }*/

    int ans = 0, bc = 0;
    forn(i, n) forn(j, m) {
        ans += a[i][j];
        if (i && j && a[n - 1][j - 1] && a[i - 1][m - 1] && a[i - 1][j - 1]) e[i].pb(j);
    }

    int M = 0;
    forn(j, m) rm[j] = -1;
    forn(i, n) {
        forn(v, n) vis[v] = 0;
        if (kuhn(i)) ++M;
    }
//    cerr << ans << ' ' << M << ' ' << a[n - 1][m - 1] << '\n';
    ans -= M;
    ans -= a[n - 1][m - 1];
    ans += a[n - 1][m - 1] ^ (M & 1);

    cout << ans + bc << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}