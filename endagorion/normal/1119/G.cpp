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

const int maxn = 2100000;
vi e[maxn];
int sz[maxn], lid[maxn];
int V = 1;

void dfs_leaves(int v, vi &leaves) {
    if (e[v].empty()) {
        lid[v] = leaves.size();
        leaves.pb(v);
        return;
    }
    for (int u: e[v]) dfs_leaves(u, leaves);
}

void dfs_attack(int v, int i, int c, vvi &ans) {
    if (e[v].empty()) {
        forn(j, c) ans[lid[v]].pb(i);
        return;
    }
    for (int u: e[v]) dfs_attack(u, i, c, ans);
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
    vi a(m);
    forn(i, m) cin >> a[i];
    int S = accumulate(all(a), 0);
    if (S % n) {
        int extra = n - S % n;
        a[0] += extra;
        S += extra;
    }

    int T = S / n;
    sz[0] = n;
    vector<pii> gr = {{0, T}};

    vector<vpi> grs(m);

    forn(i, m) {
        auto &ngr = grs[i];
        int x = a[i];
        while (x) {
            auto p = gr.back();
            gr.pop_back();
            if (sz[p.fi] * p.se <= x) {
                x -= sz[p.fi] * p.se;
                ngr.pb(p);
                continue;
            } else {
                int rem = x % sz[p.fi];
                int full = x / sz[p.fi];
                if (!rem) {
                    if (full) ngr.pb({p.fi, full});
                    p.se -= full;
                    if (p.se) gr.pb(p);
                } else {
                    int n1 = V++;
                    int n2 = V++;
                    e[p.fi] = {n1, n2};
                    sz[n1] = rem;
                    sz[n2] = sz[p.fi] - rem;
                    ngr.pb({n1, full + 1});
                    if (full) ngr.pb({n2, full});
                    if (full + 1 < p.se) gr.pb({n1, p.se - full - 1});
                    if (full < p.se) gr.pb({n2, p.se - full});
                }
                x = 0;
                break;
            }
        }
    }

    vi leaves;
    dfs_leaves(0, leaves);
//    cerr << leaves.size() << '\n';
    assert(leaves.size() <= m);
    vi lsz(m);
    forn(i, leaves.size()) lsz[i] = sz[leaves[i]];

    vvi ans(m);
    forn(i, m) {
        for (auto [v, cnt]: grs[i]) dfs_attack(v, i, cnt, ans);
    }

    forn(i, m) {
//        cerr << lsz[i] << '\n';
//        for (int x: ans[i]) cerr << x << ' ';
//        cerr << '\n';
        assert(ans[i].size() <= T);
        ans[i].resize(T, 0);
    }

//    return 0;

    cout << T << '\n';
    for (int x: lsz) cout << x << ' ';
    cout << '\n';
    forn(i, T) {
        forn(j, m) cout << ans[j][i] + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}