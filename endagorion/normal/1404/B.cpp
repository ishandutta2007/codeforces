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

int n;

pii dist(int v, int p, int s = -1) {
    pii res = s == -1 ? mp(0, v) : mp(-(int)1e9, -1);
    if (s == v) return mp(0, s);
    for (int u: e[v]) {
        if (u == p) continue;
        pii r = dist(u, v, s);
        ++r.fi;
        uax(res, r);
    }
//    cerr << v << ' ' << p << ' ' << s << ' ' << res.fi << '\n';
    return res;
}

int diam() {
    int v = dist(0, -1).se;
    return dist(v, -1).fi;
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
        int a, b, da, db;
        cin >> n >> a >> b >> da >> db;
        forn(i, n - 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            e[u].pb(v);
            e[v].pb(u);
        }
        --a; --b;
        int D = diam();
        uin(da, D);
        uin(db, D);
        bool winA = db <= 2 * da || dist(a, -1, b).fi <= da || D <= 2 * da;

        cout << (winA ? "Alice" : "Bob") << '\n';

        forn(i, n) e[i].clear();
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}