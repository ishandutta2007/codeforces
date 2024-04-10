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
const int maxk = 1100000;
i64 fact[maxk], tcaf[maxk];

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

i64 A(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * tcaf[n - k] % P;
}

i64 k, w;

i64 f(i64 l, i64 a) {
    if (a > k) return 0;
    if (a > l) return 0;
    if (a == l) return A(k, l);
    if (2 * a <= l) return deg(A(k, a), 2) * deg(k, l - 2 * a) % P;
    i64 com = 2 * a - l, edge = a - com;
    i64 remk = k - com;
    return A(k, com) * deg(A(remk, edge), 2) % P;
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
    for1(i, maxk - 1) fact[i] = fact[i - 1] * i % P;
    forn(i, maxk) tcaf[i] = deg(fact[i], -1);

    cin >> k >> w;
    i64 ans = 0;
    for1(a, k) {
        i64 l = w + a;
        (ans += f(l, a) - f(l, a + 1)) %= P;
//        cerr << a << ' ' << l << ' ' << f(l, a) << ' ' << f(l, a + 1) << '\n';
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}