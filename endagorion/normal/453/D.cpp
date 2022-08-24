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
typedef __int128_t i128;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxk = 20;
i128 a[1 << 20], b[1 << 20];
i128 P;

i128 sum(i128 x, i128 y) {
    x += y;
    if (x >= P) x -= P;
    return x;
}

void transform(i128 *a, int l) {
    if (!l) return;
    int half = 1 << (l - 1);
    transform(a, l - 1);
    transform(a + half, l - 1);
    forn(j, half) {
        i128 x = a[j], y = a[j + half];
        a[j] = sum(x, y);
        a[j + half] = sum(x, P - y);
    }
}

i128 deg(i128 x, i64 d) {
    i128 y = 1;
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

    int m;
    i64 t, p;
    cin >> m >> t >> p;
    forn(i, 1 << m) {
        i64 x;
        cin >> x;
        a[i] = x;
    }
    P = p;
    P <<= m;
    vi64 bc(m + 1);
    forn(i, m + 1) cin >> bc[i];
    forn(i, 1 << m) b[i] = bc[__builtin_popcount(i)];

    forn(i, 1 << m) a[i] %= P, b[i] %= P;
    transform(a, m);
    transform(b, m);

    forn(i, 1 << m) a[i] = 1LL * a[i] * deg(b[i], t) % P;
    transform(a, m);

    forn(i, 1 << m) cout << i64(a[i] >> m) << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}