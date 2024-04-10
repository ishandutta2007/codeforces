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

struct Seg {
    i64 L, R, x;
};

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
    vi64 x(n + 2), d(n + 2);
    forn(i, n + 2) cin >> x[i];
    i64 X = x.back();
    for1(i, n) cin >> d[i];
    d[0] = d[n + 1] = 1e9;

    vector<vector<Seg> > segs(2);
    i64 ans = X;
    forn(z, 2) {
        vi st = {0};
        vi64 R(n + 2, -1e9);
        R[0] = X;
        i64 px = 1;
        for1(i, n + 1) {
            while (R[st.back()] < x[i]) {
                i64 nx = min(X, R[st.back()]);
                if (px <= nx) segs[z].pb({px, nx, x[st.back()]}), px = nx + 1;
                st.pop_back();
            }
            if (i == n + 1) break;
            if (px <= x[i]) segs[z].pb({px, x[i], x[st.back()]}), px = x[i] + 1;
            R[i] = 2 * d[i] + x[st.back()];
            if (R[i] >= X) ans = 0;
            if (x[i] <= R[i]) st.pb(i);
        }
        if (px < X - 1) segs[z].pb({px, X - 1, x[st.back()]});

        reverse(all(x));
        for (auto &v: x) v = X - v;
        reverse(all(d));
    }

    reverse(all(segs[1]));
    for (auto &s: segs[1]) {
        s = {X - s.R, X - s.L, X - s.x};
    }

/*    forn(z, 2) {
        for (auto [L, R, x]: segs[z]) cerr << z << ' ' << L << ' ' << R << ' ' << x << '\n';
    }*/

    vi ptr(2);
    while (ptr[0] < segs[0].size()) {
        auto s0 = segs[0][ptr[0]], s1 = segs[1][ptr[1]];
        i64 x = min(s0.R, s1.R);
        vi64 mx = {s0.x, s1.x};
//        if (ptr[0] + 1 < segs[0].size() && segs[0][ptr[0]].R == x) uax(mx[0], segs[0][ptr[0] + 1].x);
//        if (ptr[1] + 1 < segs[1].size() && segs[1][ptr[1]].R == x) uin(mx[1], segs[1][ptr[1] + 1].x);
        if (max(s0.L, s1.L) <= x) {
//            cerr << x << ' ' << mx[1] - mx[0] << '\n';
            uin(ans, mx[1] - mx[0]);
        }
        forn(z, 2) if (segs[z][ptr[z]].R == x) ++ptr[z];
    }

    cout << 0.5 * ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}