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

const int maxn = 110000;
const i64 P = 998244353;
int b[maxn], c[maxn];
i64 pw[2][2][maxn];

void conv(vi64 &a, int i, int b) {
    if (!b) return;
    --b;
    forn(j, 1 << b) {
        i64 x = a[i + j], y = a[i + j + (1 << b)];
        a[i + j] = (x + y) % P;
        a[i + j + (1 << b)] = (x - y) % P;
    }
    conv(a, i, b);
    conv(a, i + (1 << b), b);
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
    cin >> n >> k;
    int a0 = 0;
    i64 x, y, z;
    cin >> x >> y >> z;
    forn(i, n) {
        int a;
        cin >> a >> b[i] >> c[i];
        a0 ^= a;
        b[i] ^= a;
        c[i] ^= a;
    }

    vi64 vb(1 << k), vc(1 << k), vbc(1 << k);
    forn(i, n) ++vb[b[i]], ++vc[c[i]], ++vbc[b[i] ^ c[i]];
    conv(vb, 0, k);
    conv(vc, 0, k);
    conv(vbc, 0, k);

    forn(i, 2) forn(j, 2) {
        i64 w = x + y * (i ? -1 : 1) + z * (j ? -1 : 1);
//        cerr << i << ' ' << j << ' ' << w << '\n';
        pw[i][j][0] = 1;
        forn(k, n) pw[i][j][k + 1] = pw[i][j][k] * w % P;
    }

    vi64 res(1 << k);
    forn(t, 1 << k) {
//        int mask = t ^ a0;
        i64 x = (n + vb[t]) / 2, y = (n + vc[t]) / 2, z = (n + vbc[t]) / 2;
        i64 A = x + y + z - n;
        assert(A % 2 == 0);
        A /= 2;
        assert(A <= x && A <= y && A <= z);
//        cerr << A << ' ' << x << ' ' << y << ' ' << z << '\n';
        res[t] = pw[0][0][A] * pw[0][1][x - A] % P * pw[1][0][y - A] % P * pw[1][1][z - A] % P;
//        if (ans < 0) ans += P;
//        cout << ans << ' ';
    }
    conv(res, 0, k);
    i64 t = 1;
    forn(i, k) (t *= (P + 1) / 2) %= P;
    forn(i, 1 << k) {
        i64 w = res[a0 ^ i];
//        if (__builtin_popcount(i) & 1) w = -w;
        w *= t;
        w %= P;
        if (w < 0) w += P;
//        cerr << i << ' ' << w << '\n';
        cout << w << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}