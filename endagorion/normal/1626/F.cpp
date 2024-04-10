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

const i64 P = 998244353;

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

i64 GCD(i64 x, i64 y) {
    while (y) {
        x %= y;
        swap(x, y);
    }
    return x;
}

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

pii operator+(pii a, const pii &b) {
    add(a.fi, b.fi);
    add(a.se, b.se);
    return a;
}

pii operator*(const pii &a, i64 t) {
    return {a.fi * t % P, a.se * t % P};
}

vector<pii> conv(const vector<pii> &a, i64 p, i64 q, int k) {
    int ns = a.size() * k / GCD(a.size(), k);
    vector<pii> b(ns);
    int pi = 0;
    forn(i, b.size()) {
        if (i % k == 0) pi = i;
        auto v = a[pi % a.size()], u = a[i % a.size()];
        add(v.se, P - 1LL * (i % k) * v.fi % P);
        b[i] = v * p + u * q;
        add(b[i].fi, p);
    }
    return b;
}

i64 p, q;

vector<pii> cs[18];

pii get_cs(int i, int j) {
    j %= cs[i].size();
    assert(j >= 0);
    if (cs[i][j].fi == -1) {
        auto v = get_cs(i + 1, j - j % (i + 1)), u = get_cs(i + 1, j);
        add(v.se, P - 1LL * (j % (i + 1)) * v.fi % P);
        cs[i][j] = v * p + u * q;
        add(cs[i][j].fi, p);
    }
    return cs[i][j];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    i64 A, x, y, M;
    cin >> n >> A >> x >> y >> k >> M;

    cs[k] = {{0, 0}};

/*    ford(i, k) {
        int ns = 0 && i + 1 == k ? 1LL : (i + 1) * cs[i + 1].size() / GCD(i + 1, cs[i + 1].size());
        cs[i].resize(ns, pi64(-1, -1));
//        cerr << i << ' ' << cs[i].size() << '\n';
    }*/

    vector<pii> c = {{0, 0}};
    p = deg(n, -1), q = (P + 1 - p) % P;
    for (int i = k; i >= 1; --i) {
        c = conv(c, p, q, i == k ? 1 : i);
//        for (auto [x, y]: c) cerr << x << ' ' << y << ' ';
//        cerr << '\n';
    }

    i64 ans = 0;
    forn(i, n) {
//        if (i % 1000000 == 0) cerr << i << '\n';
//        auto v = get_cs(0, A);
        auto v = c[A % c.size()];
        (ans += v.fi * A + v.se) %= P;
        
        A = (A * x + y) % M;
    }

    (ans *= deg(n, k)) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}