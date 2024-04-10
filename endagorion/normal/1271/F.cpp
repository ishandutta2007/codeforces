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

int a[3], b[3];
int d[8], x[8];
int L[3], R[3], l[3], r[3], sl[3], sr[3];

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
        ford(i, 3) cin >> a[i], R[i] = a[i];
        ford(i, 3) cin >> b[i];
        for1(i, 7) cin >> d[8 - i];
        bool ok = true;
        forn(i, 3) {
            L[i] = -b[i];
            for1(j, 7) if ((j >> i) & 1) L[i] += d[j];
            ok &= max(L[i], 0) <= R[i];
            L[i] -= d[1 << i];
            uax(L[i], 0);
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

/*        for1(i, 7) cerr << d[i] << ' ';;
        cerr << '\n';
        forn(i, 3) cerr << L[i] << ' ' << R[i] << '\n';*/

        bool done = false;
        forn(x7, d[7] + 1) {
            x[7] = x7;
            forn(i, 3) l[i] = L[i] - x7, r[i] = R[i] - x7;
            bool ok = true;
            forn(i, 3) uax(l[i], 0);
            uin(r[0], d[3] + d[5]);
            uin(r[1], d[3] + d[6]);
            uin(r[2], d[5] + d[6]);
//            cerr << x7 << '\n';
//            forn(i, 3) cerr << l[i] << ' ' << r[i] << '\n';
//            uax(l[2], l[0] + l[1]);
//            uin(r[2], r[0] + r[1]);
            forn(i, 3) ok &= l[i] <= r[i];
            if (!ok) continue;
            int ls = -1, rs = 1e9;
            forn(i, 3) uax(ls, l[i]), uin(rs, d[7 ^ (1 << i)] + r[i] + 1);
            if (ls >= rs) continue;
            while (rs - ls > 1) {
                int ms = (ls + rs) / 2;
                int lb = max(0, ms - r[0]) + max(0, ms - r[1]) + max(0, ms - r[2]);
                (ms >= lb ? ls : rs) = ms;
            }
            int lb = max(0, ls - r[2]) + max(0, ls - r[1]) + max(0, ls - r[0]);
            int rb = min(d[3], ls - l[2]) + min(d[5], ls - l[1]) + min(d[6], ls - l[0]);
            if (ls > rb || ls < lb) continue;
//            cerr << lb << ' ' << ls << ' ' << rb << '\n';
            x[3] = max(0, ls - r[2]);
            x[5] = max(0, ls - r[1]);
            x[6] = max(0, ls - r[0]);
//            cerr << ls << ' ' << x[3] << ' ' << x[5] << ' ' << x[6] << ' ' << x[7] << '\n';
            assert(x[3] <= min(d[3], ls - l[2]));
            assert(x[5] <= min(d[5], ls - l[1]));
            assert(x[6] <= min(d[6], ls - l[0]));
            int s = x[3] + x[5] + x[6];
            int lft = ls - s;
            forn(i, 3) {
                int p = 7 ^ (1 << i);
                int rb = min(d[p], ls - l[i]);
//                cerr << i << ' ' << x[p] << ' ' << rb << '\n';
                int delta = rb - x[p];
                uin(delta, lft);
                x[p] += delta;
                s += delta;
                lft -= delta;
            }
//            cerr << ls << ' ' << x[3] << ' ' << x[5] << ' ' << x[6] << ' ' << x[7] << '\n';
//            forn(i, 3) cerr << l[i] << ' ' << r[i] << '\n';
            assert(x[3] <= d[3]);
            assert(x[5] <= d[5]);
            assert(x[6] <= d[6]);
            assert(x[3] + x[5] >= l[0]);
            assert(x[3] + x[5] <= r[0]);
            assert(x[3] + x[6] >= l[1]);
            assert(x[3] + x[6] <= r[1]);
            assert(x[5] + x[6] >= l[2]);
            assert(x[5] + x[6] <= r[2]);
            done = true;
            forn(i, 3) {
                x[1 << i] = -b[i] + d[1 << i];
                for1(j, 7) if (j != (1 << i) && ((j >> i) & 1)) x[1 << i] += d[j] - x[j];
                uax(x[1 << i], 0);
//                cerr << x[1 << i] << ' ' << d[1 << i] << '\n';
                assert(x[1 << i] <= d[1 << i]);
            }
            for (int i = 7; i >= 1; --i) cout << x[i] << ' ';
            cout << '\n';
            break;
        }
        if (!done) cout << -1 << '\n';
    }
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}