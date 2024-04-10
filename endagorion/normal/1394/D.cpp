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
const i64 INF = 1e13;
int h[maxn];
i64 c[maxn];
vi e[maxn];

struct TRes {
    int v;
    i64 inc, dec, eq;

    TRes(int v)
        : v(v)
        , inc(INF)
        , dec(INF)
        , eq(INF)
    {
    }

    void norm() {
        uin(inc, eq);
        uin(dec, eq);
    }

    void extend(int p) {
        norm();
        if (h[p] < h[v]) {
            uin(dec, inc + c[v]);
            dec = eq = INF;
        }
        if (h[p] > h[v]) {
            uin(dec, inc + c[v]);
            inc = eq = INF;
        }
        norm();
    }

    i64 dif() const {
        return inc - dec;
    }

    bool operator<(const TRes &r) const {
        return dif() < r.dif();
    }
};

TRes dfs(int v, int p) {
    vector<TRes> ch;
    for (int u: e[v]) {
        if (u == p) continue;
        TRes res = dfs(u, v);
        res.extend(v);
//        cerr << u << ' ' << res.inc << ' ' << res.dec << ' ' << res.eq << '\n';
        ch.pb(res);
    }

    sort(all(ch));
/*    cerr << v << ": ";
    for (auto w: ch) cerr << w.v << ' ';
    cerr << '\n';*/

    TRes ans(v);
    int K = ch.size();
    vi64 psum(K + 1), ssum(K + 1);
    vvi64 pbd(3, vi64(K + 1, INF)), sbd(3, vi64(K + 1, INF));
    forn(i, K) {
        TRes res = ch[i];
        psum[i + 1] = psum[i] + res.inc;
//        uin(psum[i + 1], INF);
        pbd[0][i + 1] = min(pbd[0][i], res.inc - res.inc);
        pbd[1][i + 1] = min(pbd[1][i], res.dec - res.inc);
        pbd[2][i + 1] = min(pbd[2][i], res.eq - res.inc);
    }
    forn(i, K) {
        TRes res = ch[K - i - 1];
        ssum[i + 1] = ssum[i] + res.dec;
//        uin(ssum[i + 1], INF);
        sbd[0][i + 1] = min(sbd[0][i], res.inc - res.dec);
        sbd[1][i + 1] = min(sbd[1][i], res.dec - res.dec);
        sbd[2][i + 1] = min(sbd[2][i], res.eq - res.dec);
    }

    forn(i, K + 1) {
        uin(ans.eq, psum[i] + ssum[K - i] + (max(i, K - i) + (v == 0 ? 0 : 1)) * c[v]);
        uin(ans.inc, psum[i] + ssum[K - i] + pbd[0][i] + (max(i - 1, K - i) + 1) * c[v]);
        uin(ans.inc, psum[i] + ssum[K - i] + sbd[0][K - i] + (max(i, K - i - 1) + 1) * c[v]);
        uin(ans.dec, psum[i] + ssum[K - i] + pbd[1][i] + (max(i - 1, K - i) + 1) * c[v]);
        uin(ans.dec, psum[i] + ssum[K - i] + sbd[1][K - i] + (max(i, K - i - 1) + 1) * c[v]);
        uin(ans.eq, psum[i] + ssum[K - i] + pbd[2][i] + (max(i - 1, K - i) + 1) * c[v]);
        uin(ans.eq, psum[i] + ssum[K - i] + sbd[2][K - i] + (max(i, K - i - 1) + 1) * c[v]);
    }
    ans.norm();
//    cerr << ans.v << ' ' << ans.inc << ' ' << ans.dec << ' ' << ans.eq << '\n';
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

    int n;
    cin >> n;
    forn(i, n) cin >> c[i];
    forn(i, n) cin >> h[i];
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    auto ans = dfs(0, -1);
    ans.norm();
    cout << min({ans.inc, ans.dec, ans.eq}) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}