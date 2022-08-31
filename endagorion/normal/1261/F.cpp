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

const int LOG = 61;
vi64 full[2][LOG], part[2][LOG];

void add_seg(int z, i64 L, i64 R, i64 sl, int b) {
    i64 sr = sl + (1LL << b);
    if (max(L, sl) >= min(R, sr)) return;
    if (L <= sl && sr <= R) {
//        cerr << z << ' ' << L << ' ' << R << ' ' << sl << ' ' << b << " F\n";
        full[z][b].pb(sl);
        return;
    }
    part[z][b].pb(sl);
//    cerr << z << ' ' << L << ' ' << R << ' ' << sl << ' ' << b << " P\n";
    i64 sm = (sl + sr) / 2;
    add_seg(z, L, R, sl, b - 1);
    add_seg(z, L, R, sm, b - 1);
}

const i64 P = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(z, 2) {
        int n;
        cin >> n;
        forn(i, n) {
            i64 l, r;
            cin >> l >> r;
            ++r;
            add_seg(z, l, r, 0, LOG - 1);
        }
    }

    vector<pi64> evs;
    forn(k, LOG) {
        forn(f1, 2) forn(f2, 2) {
            if (!f1 && !f2) continue;
            auto &v1 = (f1 ? full : part)[0][k], &v2 = (f2 ? full : part)[1][k];
            for (auto x: v1) for (auto y: v2) {
                i64 z = x ^ y;
//                cerr << "S " << x << ' ' << k << '\n';
                evs.pb(mp(z, 1));
                evs.pb(mp(z + (1LL << k), -1));
            }
        }
    }

    sort(all(evs));
    i64 ans = 0;
    int b = 0;
    i64 px = -1;
    for (auto [x, db]: evs) {
        if (b) {
//            if (px < x) cerr << px << ' ' << x << '\n';
            i64 len = x - px, sum = x + px - 1;
            len %= P; sum %= P;
            (ans += len * sum) %= P;
        }
        px = x;
        b += db;
    }
    (ans *= (P + 1) / 2) %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}