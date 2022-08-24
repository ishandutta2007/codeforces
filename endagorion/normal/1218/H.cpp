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
int a[maxn], vis[maxn], onc[maxn], cpos[maxn], comp[maxn], h[maxn];
int tin[maxn], tout[maxn];
int clen[maxn];
vi re[maxn];
vi byh[maxn], cbyh[maxn];
int T;

void dfs_re(int v, int p, int cid, vi &cbyh) {
    vis[v] = 1;
    comp[v] = cid;
    tin[v] = T++;
    byh[h[v]].pb(tin[v]);
    if (h[v] >= cbyh.size()) cbyh.resize(h[v] + 1);
    ++cbyh[h[v]];
    for (int u: re[v]) {
        if (vis[u]) {
//            cerr << cid << ' ' << u << '\n';
            onc[v] = 1;
            cpos[v] = 1;
            clen[cid] = 1;
            continue;
        }
        h[u] = h[v] + 1;
        dfs_re(u, v, cid, cbyh);
        if (onc[u]) {
            onc[v] = 1;
            cpos[v] = p == -1 ? 0 : cpos[u] + 1;
            ++clen[cid];
        }
    }
    tout[v] = T;
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
        cin >> a[i]; --a[i];
        re[a[i]].pb(i);
    }

    forn(i, n) {
        if (vis[i]) continue;
        vi path;
        int j = i;
        for (; !vis[j]; vis[j] = 1, j = a[j]) path.pb(j);
        for (int x: path) vis[x] = 0;
//        cerr << j << '\n';
        dfs_re(j, -1, j, cbyh[j]);
        forn(z, cbyh[j].size() - clen[j]) cbyh[j][z + clen[j]] += cbyh[j][z];
    }

    int Q;
    cin >> Q;
    while (Q--) {
        i64 m;
        int v;
        cin >> m >> v;
        --v;

        int j = comp[v];
//        cerr << v << ' ' << j << ' ' << clen[j] << ' ' << onc[v] << ' ' << cpos[v] << '\n';
        i64 uh = h[v] + m;
        int ans1 = 0, ans2 = 0;
        if (uh < n) ans1 = lower_bound(all(byh[uh]), tout[v]) - lower_bound(all(byh[uh]), tin[v]);
//        cerr << ans << '\n';

        if (onc[v]) {
            i64 crem = m - cpos[v];
            if (crem >= (i64)cbyh[j].size()) crem -= ((crem - cbyh[j].size()) / clen[j] + 1) * clen[j];
            if (crem >= 0) ans2 = cbyh[j][crem];
            if (uh <= crem) ans1 = 0;
        }
        cout << ans1 + ans2 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}