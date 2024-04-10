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

long long Euclid(long long A, long long B, long long &X, long long &Y) {
    if (B == 0) {
        X = 1;
        Y = 0;
        return A;
    }
    long long res = Euclid(B, A % B, X, Y);
    long long nX = Y;
    long long nY = X - Y * (A / B);
    X = nX; Y = nY;
    return res;
}

inline long long InvMod(long long N, long long P) {
//    cerr << N  << ' ' << P << '\n';
    N %= P;
    if (N < 0) N += P;
    long long X, Y;
    assert(Euclid(N, P, X, Y) == 1);
    return (X % P + P) % P;
}

long long CombMods(long long A, long long B, long long P, long long Q) {
/*    if (A == 0 && B == 0) {
        return 0;
    }*/
    long long X, Y;
    Euclid(P, Q, X, Y);
    assert(P * X + Q * Y == 1);
    long long R = P * Q;
    X = (X % Q + Q) % Q;
    Y = (Y % P + P) % P;
    long long T = ((Y * A) % P * Q + (X * B) % Q * P) % R;
    T = (T + R) % R;
//    cerr << A << ' ' << B << ' ' << P << ' ' << Q << ' ' << T << '\n';
    assert(T % P == A);
    assert(T % Q == B);
    return T;
}

i64 p, q;

struct TModN {
    i64 n, dp;

    TModN(i64 N = 0) {
        if (!N) {
            n = 0;
            dp = 0;
            return;
        }
        dp = 0;
        while (N % p == 0) N /= p, ++dp;
        n = N;
    }

    TModN operator*(const TModN& r) const {
        TModN res;
        res.n = n * r.n % q;
        res.dp = dp + r.dp;
        if (!res.n) res.dp = 0;
        return res;
    }

    TModN inv() const {
        assert(n);
        TModN res;
        res.n = InvMod(n, q);
        res.dp = -dp;
        return res;
    }

    i64 eval() const {
        i64 x = n;
        assert(dp >= 0);
        forn(i, dp) {
            (x *= p) %= q;
            if (!x) break;
        }
        return x;
    }
};

const int maxn = 110000;
TModN fact[maxn];

void init_fact() {
    fact[0] = TModN(1);
    for1(i, maxn - 1) fact[i] = fact[i - 1] * TModN(i);
}

i64 CNK(int n, int k) {
    return (fact[n] * (fact[k] * fact[n - k]).inv()).eval();
}

i64 f(int n, int l) {
    i64 ans = 0;
    forn(a, n + 1) {
        if (l + 2 * a > n) break;
        (ans += CNK(n, l + 2 * a) * CNK(l + 2 * a, a)) %= q;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, l, r;
    cin >> n >> m >> l >> r;

    i64 ans = 0, M = 1;
    vector<pi64> ps;
    for (i64 p = 2; p * p <= m; ++p) {
        if (m % p) continue;
        i64 q = 1;
        while (m % p == 0) m /= p, q *= p;
        ps.pb({p, q});
    }
    if (m > 1) ps.pb({m, m});
    for (auto [p, q]: ps) {
        ::p = p;
        ::q = q;
        init_fact();
        i64 res = f(n, l) + f(n, l + 1) - f(n, r + 1) - f(n, r + 2);
        res %= q;
        if (res < 0) res += q;
        ans = CombMods(ans, res, M, q);
        M *= q;
        cerr << ans << ' ' << M << '\n';
    }
    if (ans < 0) ans += M;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}