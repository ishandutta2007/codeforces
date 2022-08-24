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

const int maxn = 43;
i64 e[maxn];
int vis[maxn];

int n;

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    forn(i, n) if ((e[v] >> i) & 1) dfs(i);
}

int components() {
    forn(i, n) vis[i] = 0;
    int C = 0;
    forn(i, n) {
        if (vis[i]) continue;
        ++C;
        dfs(i);
    }
    cerr << "Comps " << C << '\n';
    return C;
}

bool color(int v, int c) {
    if (vis[v] != -1) return vis[v] == c;
    vis[v] = c;
    forn(i, n) {
        if (((e[v] >> i) & 1) && !color(i, c ^ 1)) return false;
    }
    return true;
}

i64 bicolorings() {
    forn(i, n) vis[i] = -1;
    i64 ans = 1;
    forn(i, n) {
        if (vis[i] != -1) continue;
        if (!color(i, 0)) return 0;
        ans *= 2;
    }
    cerr << "Bicolor " << ans << '\n';
    return ans;
}

i64 sos[1 << (maxn / 2)];

i64 dom_sets() {
    int ls = n / 2, rs = n - n / 2;
    forn(mask, 1 << ls) {
        bool ok = true;
        forn(v, ls) {
            if (!((mask >> v) & 1)) ok &= !(e[v] & ~mask & ((1 << ls) - 1));
        }
        if (ok) {
            int rmask = 0;
            forn(v, ls) if (!((mask >> v) & 1)) rmask |= e[v] >> ls;
            ++sos[rmask];
        }
    }
    forn(i, rs) forn(mask, 1 << rs) if (!((mask >> i) & 1)) sos[mask | (1 << i)] += sos[mask];

    i64 ans = 0;
    forn(mask, 1 << rs) {
        bool ok = true;
        forn(v, rs) {
            if (!((mask >> v) & 1)) ok &= !((e[v + ls] >> ls) & ~mask & ((1 << rs) - 1));
        }
        if (ok) ans += sos[mask];
    }
    cerr << "Dom " << ans << '\n';
    return ans;
}

i64 dom_sets_stupid() {
    i64 ans = 0;
    forn(mask, 1 << n) {
        bool ok = true;
        forn(v, n) {
            if (!((mask >> v) & 1)) ok &= !(e[v] & ~mask);
        }
        if (ok) ++ans;
    }
    cerr << "Dom2 " << ans << '\n';
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int m;
    cin >> n >> m;
    if (m == 0) {
        cout << 0 << '\n';
        return 0;
    }
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u] |= 1LL << v;
        e[v] |= 1LL << u;
    }

    i64 ans = 1LL << n;
    ans -= 2 * dom_sets();
//    dom_sets_stupid();
    ans -= 1LL << components();
    int isol = 0;
    forn(i, n) if (!e[i]) ++isol;
    ans += 2LL << isol;
    ans += bicolorings();
    cout << ans << '\n'; 

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}