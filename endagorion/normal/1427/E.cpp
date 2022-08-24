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

#define clz __builtin_clzll

struct TOp {
    i64 a, b;
    bool plus;
};

vector<TOp> ops;

bool add(vi64 &v, i64 x) {
    vector<pi64> xs;
    for (i64 &y: v) {
        if (!x) break;
        if (clz(x) == clz(y)) {
            //ops.pb({x, y, 0});
            xs.pb({x, y});
            x ^= y;
            continue;
        }
        if (y < x) swap(x, y);
    }
    if (x) {
        v.pb(x);
        for (auto w: xs) ops.pb({w.fi, w.se, 0});
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    i64 x;
    cin >> x;
    vi64 v;
//    for (int x = 1; x <= 999999; x += 2) {
//        vi64 v;
    i64 y;
    vi muls;
    for (y = x; v.empty() || v.back() != 1; y += x) {
        if (add(v, y)) muls.pb(y / x);
    }

    vector<TOp> ops2;
    forn(i, 30) ops2.pb({x << i, x << i, 1});
    for (int mul: muls) {
        int have = 0;
        forn(b, 30) {
            if (!((mul >> b) & 1)) continue;
            if (have) ops2.pb({have * x, (x << b), 1});
            have += 1 << b;
        }
    }
    cout << ops2.size() + ops.size() << '\n';
    for (auto w: ops2) cout << w.a << " + " << w.b << '\n';
    for (auto w: ops) cout << w.a << " ^ " << w.b << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}