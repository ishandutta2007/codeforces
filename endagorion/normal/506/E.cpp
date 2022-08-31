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

const int P = 10007;
const int maxn = 201, maxk = 1311;
int dp[maxk][maxn][maxn];

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

vi64 norm(vi64 a) {
    while (!a.empty() && !a.back()) a.pop_back();
    return a;
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

vi64 operator-(const vi64 &a, const vi64 &b) {
    vi64 c(max(a.size(), b.size()));
    forn(i, c.size()) {
        if (i < (int)a.size()) add(c[i], a[i]);
        if (i < (int)b.size()) add(c[i], -b[i]);
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

vi64 operator/(vi64 a, vi64 b) {
    b = norm(b);
    a = norm(a);
    assert(!b.empty());
    i64 z = InvMod(b.back(), P);
    vi64 c;
    while (a.size() >= b.size()) {
        i64 t = a.back() * z % P;
        if (c.size() < a.size() - b.size() + 1) c.resize(a.size() - b.size() + 1);
        c[a.size() - b.size()] = t;
        forn(i, b.size()) add(a[a.size() - i - 1], -b[b.size() - i - 1] * t);
        a = norm(a);
    }
    return c;
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    string s;
    int k;
    cin >> s >> k;
    int n = s.size();

    dp[0][0][n] = 1;
    int N = 6 * n;
//    int N = 1000;
    forn(x, N + 1) ford(r, n + 1) forn(l, r + 1) {
        if (!dp[x][l][r]) continue;
//        cerr << x << ' ' << l << ' ' << r << ' ' << dp[x][l][r] << '\n';
        if (l == r) {
            (dp[x + 2][l][r] += 26 * dp[x][l][r]) %= P;
        } else if (r - l == 1) {
            (dp[x + 1][l + 1][r] += dp[x][l][r]) %= P;
            (dp[x + 2][l][r] += 25 * dp[x][l][r]) %= P;
        } else if (s[l] == s[r - 1]) {
            (dp[x][l + 1][r - 1] += dp[x][l][r]) %= P;
            (dp[x + 2][l][r] += 25 * dp[x][l][r]) %= P;            
        } else {
            (dp[x + 1][l][r - 1] += dp[x][l][r]) %= P;
            (dp[x + 1][l + 1][r] += dp[x][l][r]) %= P;
            (dp[x + 2][l][r] += 24 * dp[x][l][r]) %= P;            
        }
/*        forn(c, 26) {
            int nl = l, nr = r, nx = x + 2; 
            if (nl < nr && s[nl] - 'a' == c) ++nl, --nx;
            if (nl < nr && s[nr - 1] - 'a' == c) --nr, --nx;
//            cerr << x << ' ' << l << ' ' << r << ' ' << c << ": " << nx << ' ' << nl << ' ' << nr << '\n';
            (dp[nx][nl][nr] += dp[x][l][r]) %= P;
        }*/
    }

    vi64 vals;
    for (int s = 0; s <= N; ++s) {
        i64 ans = 0;
        forn(i, n + 1) {
            (ans += dp[s][i][i]) %= P;
            if (s) (ans += dp[s - 1][i][i] * 26) %= P;
        }
        forn(i, n) {
            (ans += dp[s][i][i + 1]) %= P;
        }
        vals.pb(ans);
    }

    vi64 rec = berlemessie(vals);
    reverse(all(rec));
    cerr << rec.size() << '\n';
    vi64 p = polyDegMod(vi64({0, 1}), k, rec);
//    cerr << p << '\n';
    i64 ans = 0;
    forn(i, p.size()) add(ans, p[i] * vals[i]);
    if (ans < 0) ans += P;
    cout << ans << '\n';

    if (k <= N) assert(ans == vals[k]);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}