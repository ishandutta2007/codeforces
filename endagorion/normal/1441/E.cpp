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

int a[maxn][maxn], isSp[maxn];
vi e[maxn];
int vis[maxn];
int busy[1 << 20];
int smask[maxn];
vi ord;

int n, m, t;

void dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    forn(i, n) if (a[v][i]) dfs(i);
    ord.pb(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> t;
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        a[u][v] = 1;
    }

    forn(v, n) dfs(v);
    int K = min(n, 20);
    vector<pair<char, pii> > ch;
    vi sp(ord.begin(), ord.begin() + K);
    for (int v: sp) isSp[v] = 1;
    forn(i, K) forn(j, i) if (!a[sp[i]][sp[j]]) {
        ch.pb({'+', mp(sp[i], sp[j])});
    }

    forn(i, n) if (!isSp[i]) ch.pb({'+', {i, i}});
    vvi masksByPC(K + 1);
    forn(mask, 1 << K) masksByPC[__builtin_popcount(mask)].pb(mask);

    vi cands;
    forn(i, K + 1) for (int mask: masksByPC[i]) if (cands.size() < n) cands.pb(mask);
    forn(i, 1 << K) busy[i] = -1;

    forn(i, n) {
        if (isSp[i]) continue;
        int mask0 = 0;
        forn(j, K) if (a[i][sp[j]]) mask0 |= 1 << j;
        int acm;
        for (int cm: cands) {
            int nmask = mask0 ^ cm;
            if (busy[nmask] != -1) continue;
            acm = cm;
            break;
        }
        int nmask = mask0 ^ acm;
//        cerr << i << ' ' << acm << ' ' << nmask << '\n';
        busy[nmask] = i;
        smask[i] = nmask;
        forn(j, K) {
            if (!((acm >> j) & 1)) continue;
            ch.pb({a[i][sp[j]] ? '-' : '+', {i, sp[j]}});
        }
    }

    cout << ch.size() << '\n';
    for (auto w: ch) {
        auto p = w.se;
        cout << w.fi << ' ' << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }
    cout.flush();

    while (t--) {
        int mask = 0;
        int spl = -1;
        forn(i, K) {
            cout << "? 1 " << sp[i] + 1 << endl;
            string res;
            cin >> res;
            if (res == "Lose") spl = i;
            else if (res == "Win") mask |= 1 << i;
        }
        int ans;
        if (spl != -1) ans = sp[spl];
        else {
            assert(busy[mask] != -1);
            ans = busy[mask];
        }
        cout << "! " << ans + 1 << endl;
        string verd;
        cin >> verd;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}