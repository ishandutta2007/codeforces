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

const int maxp = 4100000;
int mind[maxp + 1];
int omega[maxp + 1];

i64 deg(i64 x, i64 d, i64 p) {
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= p;
        d /= 2;
        (x *= x) %= p;
    }
    return y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    vi ps;
    forn(i, maxp + 1) mind[i] = i;
    fore(i, 2, maxp) {
        if (mind[i] == i) ps.pb(i);
        for (int p: ps) {
            if (p > mind[i]) break;
            if (1LL * p * i > maxp) break;
            mind[i * p] = p;
        }
    }
//    cerr << ps.size() << '\n';

    for (int p: ps) {
        vi pd;
        for (int x = p - 1; x > 1; x /= mind[x]) pd.pb(x);
        pd.erase(unique(all(pd)), pd.end());
        int x = 1;
        while (1) {
            assert(x < p);
            bool is_prim = true;
            for (int d: pd) is_prim &= deg(x, (p - 1) / d, p) != 1;
            if (is_prim) {
                omega[p] = x;
//                if (x > 5) cerr << p << ' ' << x << '\n';
                break;
            }
            ++x;
        }
    }

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    for (int ord = 3; ; ++ord) {
        cerr << ord << '\n';
        vi64 dm(ord);
        forn(i, n) dm[i % ord] += int(s[i]) - int(t[i]);
        for (int p: ps) {
            if (p < m) continue;
            if (p % ord != 1) continue;
            i64 x = deg(omega[p], (p - 1) / ord, p);
            i64 y = x;
            for1(i, ord - 1) {
                i64 s = 0;
                i64 z = 1;
                if (y == 1 && y == p - 1) {
//                    cerr << p << ' ' << omega[p] << ' ' << x << ' ' << i << ' ' << y << '\n';
                    assert(false);
                }
                forn(i, ord) {
                    (s += dm[i] * z) %= p;
                    (z *= y) %= p;
                }
                if (s == 0) {
                    cout << p << ' ' << y << '\n';
                    return 0;
                }
                (y *= x) %= p;
            }
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}