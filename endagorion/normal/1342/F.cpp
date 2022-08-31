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

const int maxn = 15;
int minL[maxn + 1][maxn + 1][1 << maxn];
pii prv[maxn + 1][maxn + 1][1 << maxn];
int pc[1 << maxn], sum[1 << maxn];
int cl[maxn][1 << maxn];
int a[maxn];

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
    forn(i, 1 << maxn) pc[i] = __builtin_popcount(i);
    forn(i, maxn) forn(mask, 1 << maxn) {
        int &j = cl[i][mask] = i;
        while (!((mask >> j) & 1) && j < maxn) ++j;
    }
    while (T--) {
        int n;
        cin >> n;
        int allB = (1 << n) - 1;
        forn(i, n) cin >> a[i];
        forn(mask, 1 << n) {
            sum[mask] = 0;
            forn(i, n) if ((mask >> i) & 1) sum[mask] += a[i];
        }
        forn(i, n + 1) forn(ans, n + 1) forn(mask, 1 << n) minL[i][ans][mask] = 1e9;
        minL[0][0][0] = 0;
        forn(i, n) forn(ans, n) forn(mask, 1 << n) {
            int v = minL[i][ans][mask];
            if (v > 1e8) continue;
            int rmask = allB ^ mask;
            for (int tmask = rmask; tmask > 0; --tmask, tmask &= rmask) {
                if (sum[tmask] <= v) continue;
                int j = cl[i][tmask];
                if (j == maxn) continue;
                if (uin(minL[j][ans + 1][mask | tmask], sum[tmask])) {
                    prv[j][ans + 1][mask | tmask] = mp(tmask, i);
                }
            }
        }

//        cerr << "here\n";
        int bi = -1, bans;
        ford(ans, n + 1) forn(i, n) {
            if (bi != -1) break;
            if (minL[i][ans][allB] < 1e8) {
                bi = i, bans = ans;
            }
        }
        assert(bi != -1);
//        cerr << bi << ' ' << bans << '\n';
        vector<pii> ops;
        int mask = allB;
        while (mask) {
            pii back = prv[bi][bans][mask];
//            cerr << bi << ' ' << bans back.fi << ' ' << back.se << '\n';
            int tmask = back.fi;
//            cerr << sum[tmask] << ' ';
            bans -= 1;
            int j = bi;
            bi = back.se;
            forn(k, n) {
                if (((tmask >> k) & 1) && k != j) ops.pb(mp(k, j));
            }
            mask ^= tmask;
        }
        cout << ops.size() << '\n';
        ford(i, ops.size()) {
//            cerr << ops[i].fi << ' ' << ops[i].se << ' ';
            int x = ops[i].fi, y = ops[i].se;
            forn(j, i) {
                if (ops[j].fi < x) --ops[i].fi;
                if (ops[j].fi < y) --ops[i].se;
            }
        }
        for (auto [x, y]: ops) cout << x + 1 << ' ' << y + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}