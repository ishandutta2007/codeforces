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
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    cerr.precision(10);
    cerr << fixed;

#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    i64 t;
    cin >> n >> t;
    i64 t0 = t;
    vi a(n + 1), b(n + 1);
    vector<ld> p(n + 1);
    for1(i, n) cin >> a[i] >> b[i] >> p[i];

    ld X = 0.0;
    for1(i, n) uax(X, p[i] * b[i]);
    vector<ld> A(n + 1), B(n + 1);
    A[0] = 1.0;
    B[0] = 1e9;
    for1(i, n) {
        A[i] = 1 - p[i];
        B[i] = X - p[i] * a[i];
    }

    vector<pair<ld, int> > st = {{0.0, 0}};
    vi ord(n);
    iota(all(ord), 1);
    sort(all(ord), [&](int i, int j){return mp(A[i], B[i]) > mp(A[j], B[j]);});

    for (int i: ord) {
        while (!st.empty()) {
            auto p = st.back();
            if (A[i] * p.fi + B[i] < A[p.se] * p.fi + B[p.se]) st.pop_back();
            else break;
        }
        if (!st.empty() && fabs(A[i] - A[st.back().se]) < 1e-10) continue;
        ld x = 0.0;
        if (!st.empty()) {
            auto p = st.back();
            x = -(B[i] - B[p.se]) / (A[i] - A[p.se]);
        }
        if (st.empty() || x > st.back().fi) st.pb(mp(x, i));
    }

//    for (auto [x, i]: st) cerr << x << ' ' << A[i] << ' ' << B[i] << '\n';

    ld x = 0.0;
    const int LOG = 40;
    forn(i, st.size()) {
        int j = st[i].se;
        ld xr = (i + 1 == (int)st.size() ? 1e18 : st[i + 1].fi);
        if (x > xr) continue;
        vector<ld> ak(LOG + 1), bk(LOG + 1);
        ak[0] = A[j], bk[0] = B[j];
        forn(j, LOG) {
            ak[j + 1] = ak[j] * ak[j];
            bk[j + 1] = bk[j] * (1 + ak[j]);
        }

        ford(j, LOG) {
            if ((1LL << j) > t) continue;
            ld nx = x * ak[j] + bk[j];
            if (nx < xr) t -= (1LL << j), x = nx;
//            cerr << t << ' ' << i << ' ' << x << '\n';
        }
        if (t) x = A[j] * x + B[j], --t;
    }

//    cerr << t << '\n';

    cout << X * t0 - x << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}