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

const int maxn = 2100;
const i64 P  = 1000000000 + 7;
vector<pii> e[maxn];
i64 d[2][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, q;
    cin >> n >> m >> q;
    int maxW = 0;
    forn(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        e[u].pb({v, w});
        e[v].pb({u, w});
        uax(maxW, w);
    }

    forn(i, n) d[0][i] = -1e18;
    d[0][0] = 0;

    vi64 ans = {0};
    int cons = 0;
    while (q && ans.size() < 3 * n) {
        forn(j, n) d[1][j] = -1e18;
        forn(v, n) for (auto [u, w]: e[v]) uax(d[1][u], d[0][v] + w);
        forn(v, n) swap(d[0][v], d[1][v]);
        i64 res = *max_element(d[0], d[0] + n);
        if (ans.size() >= 2) {
            if (res == ans.end()[-2] + 2 * maxW) ++cons;
            else cons = 0;
        }
        ans.pb(res);
        --q;
    }

    i64 sum = 0;
    for (auto x: ans) (sum += x) %= P;

    vector<pi64> sl(n);
    forn(i, n) {
        int mw = 0;
        for (auto [j, w]: e[i]) uax(mw, w);
        i64 D = max(d[0][i], d[1][i] + mw) + mw;
        sl[i] = {mw, D};
//        cerr << sl[i].fi << ' ' << sl[i].se << '\n';
    }

    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j){return sl[i] < sl[j];});
    vector<pi64> st = {};
    
    for (int i: ord) {
        while (!st.empty()) {
            int j = st.back().se;
            i64 x = st.back().fi;
            if (sl[i].fi * x + sl[i].se >= sl[j].fi * x + sl[j].se) st.pop_back();
            else break;
        }
        i64 x = 0;
        if (!st.empty()) {
            int j = st.back().se;
            i64 A = sl[i].fi - sl[j].fi, B = sl[j].se - sl[i].se;
            if (A) {
                i64 x = (B - 1) / A + 1;
                if (x < q) st.pb(mp(x, i));
            }
        } else st.pb(mp(0, i));
    }

    st.pb(mp(q, -1));
    forn(i, st.size() - 1) {
        i64 L = st[i].fi, R = st[i + 1].fi - 1;
        int p = st[i].se;
        i64 A = sl[p].fi % P, B = sl[p].se % P;
//        cerr << L << ' ' << R << ' ' << A << ' ' << B << '\n';
        (sum += B * (R - L + 1)) %= P;
        (sum += (R + L) * (R - L + 1) / 2 % P * A) %= P;
//        fore(x, L, R) (sum += B + A * x) %= P;
    }

    cout << sum << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}