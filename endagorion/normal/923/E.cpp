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
const int maxn = 1 << 18;
const int BUBEN = 300;

void add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

i64 deg(i64 x, i64 d) {
    d %= P - 1;
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

int bitrev(int n, int i) {
    for (int l = 1, r = n / 2; l < r; l <<= 1, r >>= 1) {
        if (((i / l) & 1) != ((i / r) & 1)) i ^= l | r;
    }
    return i;
}

i64 omega = 0;
i64 r[20][2 * maxn];

void fft(int n, int *a, bool inv) {
    forn(i, n) {
        int j = bitrev(n, i);
        if (i < j) swap(a[i], a[j]);
    }
    for (int l = 1, q = 0; l < n; l *= 2, ++q) {
//        int w0 = deg(omega, maxn / l / 2);
//        if (inv) w0 = deg(w0, -1);
        for (int i = 0; i < n; i += 2 * l) {
//            int w = 1;
            forn(j, l) {
                int x = a[i + j], y = a[i + l + j];
                int z = 1LL * y * r[q][inv ? (2 << q) - j : j] % P;
                a[i + j] = (x + z) % P;
                a[i + l + j] = (x - z) % P;
//                w = 1LL * w * w0 % P;
            }
        }
    }
    if (inv) {
        int z = deg(n, -1);
        forn(i, n) a[i] = 1LL * a[i] * z % P;
    }
}

int pa[maxn], pb[maxn], res[maxn];

vi sum(const vi &a, const vi &b) {
    int n = max(a.size(), b.size());
    vi c(n);
    forn(i, n) {
        if (i < a.size()) add(c[i], a[i]);
        if (i < b.size()) add(c[i], b[i]);
    }
    return c;
}

vi prod(const vi &a, const vi &b) {
    if (a.empty() || b.empty()) {
        return {};
    }
    int n = a.size(), m = b.size();
    vi c(n + m - 1);
    int N = 1;
    while (N < n + m) N *= 2;
    forn(i, N) pa[i] = i < n ? a[i] : 0;
    fft(N, pa, false);
    forn(i, N) pb[i] = i < m ? b[i] : 0;
    fft(N, pb, false);
    forn(i, N) pa[i] = 1LL * pa[i] * pb[i] % P;
    fft(N, pa, true);
    forn(i, n + m - 1) if ((c[i] = pa[i]) < 0) c[i] += P;
    return c;
}

i64 fact[maxn], tcaf[maxn];

vi shift(vi a, int x) {
    forn(i, a.size()) a[i] = 1LL * a[i] * fact[i] % P;
    reverse(all(a));
    vi b(a.size());
    int xp = 1;
    forn(i, b.size()) {
        b[i] = 1LL * xp * tcaf[i] % P;
        xp = 1LL * xp * x % P;
    }
    vi c = prod(a, b);
    c.resize(a.size());
    reverse(all(c));
    forn(i, c.size()) c[i] = 1LL * c[i] * tcaf[i] % P;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    while (1) {
        if (deg(omega, maxn) == 1 && deg(omega, maxn / 2) != 1) break;
        ++omega;
    }

    forn(i, 18) {
        r[i][0] = 1;
        i64 w0 = deg(omega, maxn >> (i + 1));
        forn(j, 1 << (i + 1)) r[i][j + 1] = 1LL * r[i][j] * w0 % P;
    }

    fact[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P;
    tcaf[maxn - 1] = deg(fact[maxn - 1], -1);
    ford(i, maxn - 1) tcaf[i] = (i + 1) * tcaf[i + 1] % P;

    int n;
    i64 m;
    cin >> n >> m;
    vi a(n + 1);
    forn(i, n + 1) cin >> a[i];
    a = shift(a, 1);
    forn(i, n + 1) a[i] = 1LL * a[i] * deg(i + 1, -m) % P;
    a = shift(a, -1);
    for (int x: a) {
        if (x < 0) x += P;
        cout << x << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}