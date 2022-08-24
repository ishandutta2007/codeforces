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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 n, m, l, r;
    cin >> n >> m >> l >> r;
    vvi64 ans(n + 1);
    i64 missl = 0;
    for1(x, n) for1(d, n / x) {
        if (!ans[x * d].empty()) continue;
        i64 cl = d + 1, rl = (l - 1) / (d * x) + 1;
        i64 cr = n / x, rr = min(m, r / d / x);
        i64 dd = -1, y = -1;
        forn(zl, 2) forn(zr, 2) {
            if (dd != -1) break;
            i64 ly = 1, ry = m;
            if (zl) uin(ry, rl / cl);
            else uax(ly, rl / cl + 1);
            if (zr) uax(ly, rr / cr + 1);
            else uin(ry, rr / cr);
            if (ly > ry) continue;
            if (!zl && !zr && cl <= cr) {
                y = ly;
                dd = cl;
            }
            if (zl && !zr && (rl - 1) / ry + 1 <= cr) {
                y = ry;
                dd = cr;
            }
            if (zr && !zl && cl <= rr / ly) {
                y = ly;
                dd = cl;
            }
            if (zl && zr && rl <= rr) {
//                cerr << x << ' ' << d << ' ' << ly << ' ' << ry << ' ' << rl << ' ' << rr << '\n';
//                cerr << cl << ' ' << rl << ' ' << cr << ' ' << rr << '\n';
                fore(yy, ly, ry) {
                    i64 cd = rr / yy;
                    if (yy * cd >= rl) {
//                        cerr << "! " << yy << ' ' << cd << '\n';
                        dd = cd;
                        y = yy;
                        break;
                    }
                }
            }
        }
        if (dd != -1) {
            ans[d * x] = {d * x, dd * y, dd * x, d * y};
        }
    }
    cerr << missl << '\n';

    for1(x, n) {
        if (ans[x].empty()) cout << -1 << '\n';
        else {
            for (auto y: ans[x]) cout << y << ' ';
            cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}