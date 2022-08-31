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
const int BL = 400, BC = maxn / BL + 1;

i64 s[maxn], m[maxn], r[maxn], cap[maxn];
i64 lt[maxn];
int bord[BC];
vi64 ts[BC], a[BC], b[BC];
int full[BC];
i64 fullt[BC];

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
    forn(i, n) cin >> s[i] >> m[i] >> r[i];

    int B = 0;
    while (bord[B] < n) {
        ++B;
        bord[B] = min(n, bord[B - 1] + BL);
    }

    forn(i, B) {
        i64 sr = 0;
        vi ord;
        fore(j, bord[i], bord[i + 1] - 1) {
            if (!r[j]) continue;
            ord.pb(j);
            sr += r[j];
            cap[j] = (m[j] + r[j] - 1) / r[j];
        }
        sort(all(ord), [&](int i, int j){return cap[i] < cap[j];});
        ts[i].pb(0);
        a[i].pb(sr);
        b[i].pb(0);
        for (int j: ord) {
            int nt = cap[j];
            if (nt != ts[i].back()) {
                ts[i].pb(nt);
                i64 la = a[i].back();
                i64 lb = b[i].back();
                a[i].pb(la);
                b[i].pb(lb);
            }
            a[i].back() -= r[j];
            b[i].back() += m[j];
        }
        ts[i].pb(1e18);
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int t, L, R;
        cin >> t >> L >> R;
        --L;
//        cerr << t << ' ' << L << ' ' << R << '\n';
        int lb = L / BL, rb = (R - 1) / BL;
        i64 ans = 0;
        fore(bi, lb, rb) {
            bool fast = L <= bord[bi] && bord[bi + 1] <= R && full[bi];
            if (fast) {
                i64 dt = t - fullt[bi];
                if (dt < 0) {
                    cerr << bi << ' ' << t << ' ' << fullt[bi] << '\n';
                    assert(false);
                }
                int di = upper_bound(all(ts[bi]), dt) - ts[bi].begin() - 1;
                assert(di >= 0);
                ans += a[bi][di] * dt + b[bi][di];
            } else {
                int lj = max(bord[bi], L), rj = min(bord[bi + 1], R);
                if (full[bi]) {
                    fore(j, bord[bi], bord[bi + 1] - 1) lt[j] = fullt[bi];
                    full[bi] = 0;
                }
                fore(j, lj, rj - 1) {
                    i64 dt = t - lt[j];
                    i64 v = min(s[j] + dt * r[j], m[j]);
                    ans += v;
                    s[j] = 0;
                    lt[j] = t;
                }
            }
            if (L <= bord[bi] && bord[bi + 1] <= R) {
                full[bi] = 1;
                fullt[bi] = t;
            } else full[bi] = 0;
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}