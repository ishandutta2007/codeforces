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

void add(i64 &a, i64 b) {
    a += b; a %= P;
}

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

inline long long InvMod(long long N, long long P = ::P) {
//    cerr << N  << ' ' << P << '\n';
    N %= P;
    if (N < 0) N += P;
    long long X, Y;
    assert(Euclid(N, P, X, Y) == 1);
    return (X % P + P) % P;
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

typedef vector< vector<long long> > TMatrix;

TMatrix Identity(int N) {
    TMatrix E(N, vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) {
        E[i][i] = 1;
    }
    return E;
}

TMatrix matrixMul(const TMatrix &A, const TMatrix &B) {
    int N = A.size();
    TMatrix C(N, vector<long long>(N));
    for (int i = 0; i < N; ++i) {
        for (int k = 0; k < N; ++k) {
            if (!A[i][k]) continue;
            for (int j = 0; j < N; ++j) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % P;
            }
        }
    }

    return C;
}

TMatrix operator+(TMatrix a, const TMatrix &b) {
    forn(i, a.size()) forn(j, a[i].size()) add(a[i][j], b[i][j]);
    return a;
}

TMatrix operator-(TMatrix a, const TMatrix &b) {
    forn(i, a.size()) forn(j, a[i].size()) add(a[i][j], P - b[i][j]);
    return a;
}

TMatrix operator*(const TMatrix &a, const TMatrix &b) {
    return matrixMul(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

/*    {
        auto v = berlemessie({1, 1, 2, 3, 5, 8, 13});
        for (auto x: v) cerr << x << ' ';
        return 0;
    }*/

    int n, m, k;
    cin >> n >> m >> k;
    TMatrix A(n, vi64(n)), D(n, vi64(n));
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        A[x][y] = A[y][x] = 1;
        --D[x][x]; --D[y][y];
    }

    vector<TMatrix> ms(6 * n + 1);
    ms[0] = Identity(n);
    ms[1] = A;
    fore(i, 2, ms.size() - 1) {
        ms[i] = A * ms[i - 1] + (i == 2 ? D : D + Identity(n)) * ms[i - 2];
    }

    vi64 seq(ms.size());
    forn(i, seq.size()) forn(j, n) add(seq[i], ms[i][j][j]);

    auto rec = berlemessie(seq);
/*    cerr << rec.size() << '\n';
    for (auto x: rec) cerr << x << ' ';
    cerr << '\n';*/

    while (seq.size() <= k) {
//        cerr << seq.size() << '\n';
        i64 V = 0;
        for1(i, rec.size() - 1) add(V, -seq.end()[-i] * rec[i]);
        seq.pb(V);
    }

    auto ans = seq[k];
    ans %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}