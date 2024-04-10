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

vvi64 operator*(const vvi64 &a, const vvi64 &b) {
    vvi64 c(a.size(), vi64(b[0].size(), 1e18));
    forn(i, a.size()) forn(j, a[0].size()) forn(k, b[0].size()) uin(c[i][k], a[i][j] + b[j][k]);
    return c;
}

vvi64 deg(vvi64 a, i64 d) {
    int n = a.size();
    vvi64 c(n, vi64(n, 1e18));
    forn(i, n) c[i][i] = 0;
    while (d) {
        if (d & 1) c = c * a;
        d /= 2;
        a = a * a;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int x, k, n, q;
    cin >> x >> k >> n >> q;
    vi64 c(k);
    forn(i, k) cin >> c[i];

    vector<pi64> op(q);
    forn(i, q) cin >> op[i].fi >> op[i].se, --op[i].fi;
    sort(all(op));

    vi masks;
    vi men(1 << k);
    forn(mask, 1 << k) {
        if (__builtin_popcount(mask) != x) continue;
        men[mask] = masks.size();
        masks.pb(mask);
    }

    int V = masks.size();
    vvi64 M(V, vi64(V, 1e18));
    forn(i, masks.size()) {
        int m = masks[i];
        if (!(m & 1)) {
            M[i][men[m >> 1]] = 0;
            continue;
        }
        for1(j, k) {
            if ((m >> j) & 1) continue;
            int nm = m ^ 1 ^ (1 << j);
            uin(M[i][men[nm >> 1]], c[j - 1]);
        }
    }
    vector<vvi64> M2;
    M2.pb(M);
    forn(i, 30) M2.pb(M2[i] * M2[i]);

    int p = 0, ptr = 0;
    vvi64 dv(1, vi64(V, 1e18));
    dv[0][0] = 0;
    while (p < n - x) {
        i64 np = n - x;
        if (ptr < q) uin(np, op[ptr].fi);
        int d = np - p;
        forn(i, 30) if ((d >> i) & 1) dv = dv * M2[i];
        if (ptr < q && np == op[ptr].fi) {
            forn(v, V) if (masks[v] & 1) dv[0][v] += op[ptr].se;
            ++ptr;
        }
        p = np;
    }
    i64 ans = dv[0][0];
    while (ptr < q) ans += op[ptr++].se;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}