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

struct Run {
    i64 l;
    i64 d0, d;
    i64 z0, dz;
};

i64 untilx(const vector<Run> &rs, i64 x) {
/*    cerr << x << '\n';
    for (auto r: rs) {
        cerr << r.l << ' ' << r.d0 << ' ' << r.d << ' ' << r.z0 << ' ' << r.dz << '\n';
    }*/
    if (!x) return 1e18;
    for (auto r: rs) {
        if (r.d0 - r.d * r.l > x) continue;
        if (r.d0 <= x) return r.z0;
        i64 k = (r.d0 - x - 1) / r.d + 1;
        return r.z0 + k * r.dz;
    }
    assert(false);
    return -1;
}

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
    for1(tc, T) {
//        cerr << tc << '\n';
        i64 a, n, p, h;
        cin >> a >> n >> p >> h;
        a %= p;
        if (a <= h) {
            cout << "YES" << '\n';
            continue;
        }
        i64 L = a, R = p - a;
        i64 Lz = 1, Rz = 1;
        vector<Run> ls = {{0, L, 0, 1, 0}}, rs = {{0, R, 0, 1, 0}};
        while (max(L, R) > 1) {
//            cerr << L << ' ' << Lz << ' ' << R << ' ' << Rz << '\n';
            if (L > R) {
                i64 len = L / R;
                ls.pb({len, L, R, Lz, Rz});
                Lz += Rz * len;
                L %= R;
            } else {
                i64 len = R / L;
                rs.pb({len, R, L, Rz, Lz});
                Rz += Lz * len;
                R %= L;
            }
        }
        i64 LC = untilx(ls, h);
        i64 RC = untilx(rs, h);
//        cerr << LC << ' ' << RC << '\n';
        cout << (n < LC + RC - 1 ? "NO" : "YES") << '\n';
//        cout << (n < LC + RC - 1 ? "NO" : "YES") << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}