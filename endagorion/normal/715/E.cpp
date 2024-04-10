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

const i64 P = 998244353;
const int maxn = 250;

vi64 operator*(const vi64 &a, const vi64 &b) {
    vi64 c(a.size() + b.size() - 1);
    forn(i, a.size()) forn(j, b.size()) (c[i + j] += a[i] * b[j]) %= P;
    return c;
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
    vvi e(2 * n);
    forn(i, n) {
        int x;
        cin >> x;
        --x;
        if (x >= 0) e[i].pb(x + n);
    }
    forn(i, n) {
        int x;
        cin >> x;
        --x;
        if (x >= 0) e[x + n].pb(i);
    }

    vi ind(2 * n);
    forn(i, 2 * n) for (int v: e[i]) ++ind[v];
    vi vis(2 * n);
    vvi ctype(2, vi(2));
    forn(i, 2 * n) {
        if (ind[i]) continue;
        int v;
        for (v = i; !e[v].empty(); v = e[v][0]) vis[v] = 1;
        vis[v] = 1;
        ++ctype[i / n][v / n];
    }

    int cycles = 0;
    forn(i, 2 * n) {
        if (vis[i]) continue;
        ++cycles;
        for (int v = i; !vis[v]; v = e[v][0]) vis[v] = 1;
    }

    vi64 ans = {1};
    int p = ctype[0][0];
//    cerr << p << '\n';
    for (int hs: {ctype[0][1], ctype[1][0]}) {
        for1(i, hs) ans = ans * vi64({p + i - 1, 1});
    }

    for1(i, p) ans = ans * vi64({i * (i - 1), i});
    vi64 res(n);
    forn(i, ans.size()) if (ans[i]) res[n - i - cycles] = ans[i];
    forn(i, n) cout << res[i] << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}