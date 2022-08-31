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

void add(i64 &x, i64 y) {
    x += y;
    x %= P;
}

void norm(vi64 &a) {
    while (!a.empty() && !a.back()) a.pop_back();
}

void norm(vvi64 &a) {
    for (vi64 &x: a) norm(x);
    while (!a.empty() && a.back().empty()) a.pop_back();
}

vi64 operator*(const vi64 &a, const vi64 &b) {
    if (a.empty() || b.empty()) return {};
    vi64 c(a.size() + b.size() - 1);
    forn(i, a.size()) forn(j, b.size()) add(c[i + j], a[i] * b[j]);
    norm(c);
    return c;
}

vi64 operator+(const vi64 &a, const vi64 &b) {
    vi64 c(max(a.size(), b.size()));
    forn(i, c.size()) {
        if (i < a.size()) add(c[i], a[i]);
        if (i < b.size()) add(c[i], b[i]);
    }
    norm(c);
    return c;
}

vvi64 operator*(const vvi64 &a, const vvi64 &b) {
    if (a.empty() || b.empty()) return {};
    vvi64 c(a.size() + b.size() - 1);
    forn(i, a.size()) forn(j, b.size()) c[i + j] = c[i + j] + a[i] * b[j];
    norm(c);
    return c;
}

const int maxn = 2100;
i64 fact[maxn], tcaf[maxn];

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

int L, k;

vvi64 polyy(int l) {
    if (l <= k) return {{1}};
    int s = l / k;
    vvi64 p(2, vi64(s + 1));
    i64 iL = deg(L, -1);
    p[0][0] = 1;
    for1(i, s) {
        i64 rat = (l - k * i) * iL % P;
        i64 drat = deg(-rat, i - 1);
        p[0][i] = deg(-rat, i) * tcaf[i] % P;
        p[1][i] = -deg(-rat, i - 1) * tcaf[i - 1] % P;
    }
    norm(p);
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

    fact[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P;
    forn(i, maxn) tcaf[i] = deg(fact[i], -1);

    int n;
    cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    L = accumulate(all(a), 0);
    vvi64 Q = {{1}};
    for (int l: a) Q = Q * polyy(l);

/*    for (auto v: Q) {
        for (i64 x: v) cerr << x << ' ';
        cerr << '\n';
    }*/

    i64 ans = 0;
    i64 iL = deg(L, -1);

    forn(i, Q.size()) {
        forn(j, Q[i].size()) {
            if (!i && !j) continue;
            if (!Q[i][j]) continue;
            assert(j >= i);
            int d = j - i;
            add(ans, -Q[i][j] * fact[d] % P * deg(k * j * iL % P, -(d + 1)));
        }
    }

    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}