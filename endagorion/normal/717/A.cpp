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

const i64 P = 1000000000 + 7;

void add(i64 &x, i64 y) {
    x += y;
    x %= P;
}

long long degMod(long long x, long long deg, long long P = ::P) {
    assert(deg >= 0);
    x %= P;
//    deg %= P - 1;
//    if (deg < 0) deg += P - 1;
    i64 res = 1;
    while (deg) {
        if (deg & 1) res *= x, res %= P;
        x *= x; x %= P;
        deg >>= 1;
    }
    return res % P;
}

i64 InvMod(i64 x, i64 P = ::P) {
    return degMod(x, P - 2, P);
}

vi64 operator+(const vi64 &a, const vi64 &b) {
    vi64 c(max(a.size(), b.size()));
    forn(i, c.size()) {
        if (i < (int)a.size()) add(c[i], a[i]);
        if (i < (int)b.size()) add(c[i], b[i]);
    }
//    while (!c.empty() && !c.back()) c.pop_back();
    return c;
}

vi64 operator*(const vi64 &a, const vi64 &b) {
    vi64 c(a.size() + b.size() - 1);
    forn(i, a.size()) forn(j, b.size()) add(c[i + j], a[i] * b[j]);
    return c;
}

vi64 operator*(vi64 a, i64 t) {
//    if (!t) return {};
    for (i64 &x: a) (x *= t) %= P;
    return a;
}


vi64 berlemessie(vi64 a) {
    vi64 p = {1}, delta = {0, 1};
    i64 deltav = 1;
    forn(i, a.size()) {
        i64 val = 0;
        forn(j, p.size()) add(val, p[j] * a[i - j]);
        if (val) {
            swap(p, delta);
            p = delta + p * (-val * InvMod(deltav, P) % P + P);
//            p = norm(p);
            deltav = val;
        }
//        cerr << i << '\n' << p << '\n' << delta << '\n';
        delta = delta * vi64({0, 1});
    }
    return p;
}

i64 CNKP(i64 A, i64 B, i64 P = ::P) {
    if (B == 0) return 1;
    if (A < 0) return 0;
    if (B < 0 || B > A) return 0;
    uin(B, A - B);
    i64 q = 1;
    for (int i = 0; i < B; ++i) {
        q *= (A - i) % P; q %= P;
        q *= InvMod(i + 1, P); q %= P;
    }
    return q;
}

vi64 norm(vi64 a) {
    while (!a.empty() && !a.back()) a.pop_back();
    return a;
}

vi64 operator%(vi64 a, vi64 b) {
    b = norm(b);
    a = norm(a);
    assert(!b.empty());
    i64 z = InvMod(b.back(), P);
    while (a.size() >= b.size()) {
        i64 t = a.back() * z % P;
        forn(i, b.size()) add(a[a.size() - i - 1], -b[b.size() - i - 1] * t);
        a = norm(a);
    }
    return a;
}

vi64 polyDegMod(vi64 a, i64 d, vi64 b) {
    a = a % b;
    vi64 c = {1};
    while (d) {
        if (d & 1) c = (c * a) % b;
        a = a * a % b;
        d /= 2;
    }
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

    int k;
    i64 L, R;
    cin >> k >> L >> R;
    int n = 4000;
    vi64 fib(n);
    fib[0] = 1;
    fib[1] = 2;
    fore(i, 2, n - 1) fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    vi64 a(n);
    forn(i, n) a[i] = (CNKP(fib[i], k) + (i ? a[i - 1] : 0LL)) % P;
    auto p = berlemessie(a);
    reverse(all(p));

    i64 ans = 0;
    forn(z, 2) {
        i64 x = z ? R : L - 1;
        auto v = polyDegMod(vi64({0, 1}), x, p);
        forn(i, v.size()) add(ans, v[i] * a[i] * (z ? 1 : -1));
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

/*    {
        i64 ans2 = a[R] - a[L - 1];
        if (ans2 < 0) ans2 += P;
        cout << ans2 << '\n';
    }*/

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}