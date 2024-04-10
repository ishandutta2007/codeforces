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

const int maxn = 210000;
int fenw[maxn];

int fmax(int i) {
    int ans = -1e9;
    for (; i >= 0; i &= i + 1, --i) uax(ans, fenw[i]);
    return ans;
}

void fupd(int i, int x) {
    for (; i < maxn; i |= i + 1) uax(fenw[i], x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, v;
    cin >> n >> v;
    vi64 t(n), x(n);
    forn(i, n) cin >> t[i];
    forn(i, n) cin >> x[i];

    vector<pi64> ps = {{0, 0}};
    forn(i, n) {
        i64 A = v * t[i] - x[i], B = v * t[i] + x[i];
        if (A < 0 || B < 0) continue;
//        cerr << A << ' ' << B << '\n';
        ps.pb({A, B});
    }

    vi64 xs;
    for (auto [x, y]: ps) xs.pb(y);
    sort(all(xs));
    xs.erase(unique(all(xs)), xs.end());
    auto index = [&](i64 x){return lower_bound(all(xs), x) - xs.begin();};

    sort(all(ps));

    forn(i, maxn) fenw[i] = -1e9;
    fupd(index(0), 0);
    for (auto [x, y]: ps) {
        if (x + y == 0) continue;
        int i = index(y);
        int s = fmax(i) + 1;
        fupd(i, s);
//        cerr << x << ' ' << y << ' ' << s << '\n';
    }

    cout << fmax(maxn - 1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}