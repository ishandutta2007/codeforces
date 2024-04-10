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

vector<pair<pii, int> > readv(int n, int z) {
    vector<pii> s(n);
    for (auto &[y, x]: s) cin >> x >> y, --x;
    sort(all(s), [](pii a, pii b){return mp(a.fi, -a.se) < mp(b.fi, -b.se);});
    int maxl = -1;
    vector<pair<pii, int> > res;
    for (auto [r, l]: s) {
        if (uax(maxl, l)) res.pb({{r, l}, z});
    }
    return res;
}

const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    x += y;
    x %= P;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
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

    int k, n, m;
    cin >> k >> n >> m;

    auto v0 = readv(n, 0);
    auto v1 = readv(m, 1);
    
    vector<pair<pii, int> > v(v0.size() + v1.size());
    merge(all(v0), all(v1), v.begin());
    int V = v.size();

    vvi ptr(2, vi(2));
    vvi64 pdp(2, vi64(V + 1)), pdp2(2, vi64(V + 1));

    i64 ans = 1;

    forn(i, V) {
        auto [p, z] = v[i];
        auto [r, l] = p;
        forn(x, 2) {
            int &pt = ptr[x][z];
            while (pt < i && (v[pt].se != x || v[pt].fi.fi <= l)) ++pt;
        }
        i64 dp = deg(2, l - r);
        add(dp, (pdp2[z][i] - pdp2[z][ptr[z][z]]) * deg(2, -r));
        forn(x, 2) add(dp, pdp[x][ptr[x][z]] * deg(2, l - r));
//        cerr << l << ' ' << r << ' ' << z << ' ' << dp * deg(2, r) % P << '\n';
//        forn(x, 2) cerr << ptr[x][z] << ' ' << pdp[x][ptr[x][z]] << ' ' << pdp2[x][ptr[x][z]] << '\n';


        add(ans, -dp);
        forn(x, 2) {
            pdp[x][i + 1] = pdp[x][i];
            pdp2[x][i + 1] = pdp2[x][i];
        }
        add(pdp[z][i + 1], -dp);
        add(pdp2[z][i + 1], -dp * deg(2, r));
    }   

    (ans *= deg(2, k)) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}