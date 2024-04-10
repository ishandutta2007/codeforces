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

const int maxn = 110000;
int fenw[maxn];

void addf(int i, int x) {
    for (; i < maxn; i |= i + 1) uax(fenw[i], x);
}

int maxf(int i) {
    int res = -1e9;
    for (; i >= 0; i &= i + 1, --i) uax(res, fenw[i]);
    return res;
}

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
    char trash;
    i64 a, b, c, d;
    cin >> a >> trash >> b >> c >> trash >> d;
//    cerr << a << ' ' << b << ' ' << c << ' ' << d << '\n';

    vector<pi64> p(n);
    vi64 xs(n), ys(n);
    forn(i, n) {
        i64 x, y;
        cin >> x >> y;
        i64 u = x * c - y * d;
        i64 v = b * y - a * x;
//        cerr << x << ' ' << y << ' ' << u << ' ' << v << '\n';
        p[i] = {u, v};
        xs[i] = u;
        ys[i] = v;
    }
    xs.pb(0);
    ys.pb(0);
    sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
    sort(all(ys)); ys.erase(unique(all(ys)), ys.end());
    assert(is_sorted(all(xs))); assert(is_sorted(all(ys)));

    auto index = [&](vi64 &v, i64 x){return lower_bound(all(v), x) - v.begin();};
    for (auto &[x, y]: p) {
//        cerr << x << ' ' << y << ' ';
        x = index(xs, x);
        y = -index(ys, y);
//        cerr << x << ' ' << y << '\n';
    }
    int x0 = index(xs, 0), y0 = index(ys, 0);
//    cerr << "XY0 " << x0 << ' ' << y0 << '\n';
    sort(all(p));

    forn(i, maxn) fenw[i] = -1e9;
    addf(y0, 0);
    for (auto [x, y]: p) if (x > x0) {
//        cerr << x << ' ' << -y << '\n';
        addf(-y, maxf(-y - 1) + 1);
    }
    cout << maxf(maxn - 1) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}