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
int p[maxn], h[maxn], s[maxn], a[maxn];

void dfs0(int v) {
    for (int u: e[v]) {
        h[u] = h[v] + 1;
        dfs0(u);
    }
}

void dfs(int v) {
    if (s[v] == -1) {
        int top = s[p[v]], mx = 2e9;
        for (int u: e[v]) uin(mx, s[u]);
        if (e[v].empty()) mx = top;
        a[v] = mx - top;
        for (int u: e[v]) a[u] = s[u] - mx;
    }

    for (int u: e[v]) dfs(u);
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
    for1(i, n - 1) {
        int par;
        cin >> par;
        --par;
        p[i] = par;
        e[par].pb(i);
    }
    dfs0(0);
    forn(i, n) cin >> s[i];
    bool ok = true;
    forn(i, n) ok &= (s[i] == -1) == (h[i] % 2 == 1);
    a[0] = s[0];
    if (ok) {
        dfs(0);
        forn(i, n) ok &= a[i] >= 0;
    }

    if (!ok) cout << -1 << '\n';
    else {
        i64 total = 0;
        forn(i, n) total += a[i];
        cout << total << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}