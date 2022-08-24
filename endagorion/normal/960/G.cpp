#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

int pa[maxn], pb[maxn], res[maxn];
int a[maxn], b[maxn], c[maxn];

void fft(int n, int *a, bool inv) {
    forn(i, n) {
        int j = bitrev(n, i);
        if (i < j) swap(a[i], a[j]);
    }
    for (int l = 1; l < n; l *= 2) {
        int w0 = deg(omega, maxn / l / 2);
        if (inv) w0 = deg(w0, -1);
        for (int i = 0; i < n; i += 2 * l) {
            int w = 1;
            forn(j, l) {
                int x = a[i + j], y = a[i + l + j];
                int z = 1LL * y * w % P;
                a[i + j] = (x + z) % P;
                a[i + l + j] = (x - z) % P;
                w = 1LL * w * w0 % P;
            }
        }
    }
    if (inv) {
        int z = deg(n, -1);
        forn(i, n) a[i] = 1LL * a[i] * z % P;
    }
}

void mul(int n, int *a, int m, int *b) {
    int N = 1;
    while (N < n + m) N *= 2;
    forn(i, N) pa[i] = i < n ? a[i] : 0;
    fft(N, pa, false);
    forn(i, N) pb[i] = i < m ? b[i] : 0;
    fft(N, pb, false);
    forn(i, N) pa[i] = 1LL * pa[i] * pb[i] % P;
    fft(N, pa, true);
    forn(i, N) res[i] = pa[i];
}

i64 fact[2 * maxn];

i64 cnk(int a, int b) {
    return fact[a + b] * deg(fact[a], -1) % P * deg(fact[b], -1) % P;
}

vi prod(int l, int r) {
    if (r == l) return {1};
    if (r - l == 1) return {l, 1};
    int M = (l + r) / 2;
    vi lh = prod(l, M), rh = prod(M, r);
    int n = lh.size(), m = rh.size();
    forn(i, n) a[i] = lh[i];
    forn(j, m) b[j] = rh[j];
    mul(n, a, m, b);
    vi c(res, res + n + m - 1);
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

    int n, a, b;
    cin >> n >> a >> b;
    if (!a || !b || a + b > n + 1) {
        cout << 0 << '\n';
        return 0;
    }

    fact[0] = 1;
    for1(i, 2 * maxn - 1) fact[i] = i * fact[i - 1] % P;
    forn(i, n + 1) ::a[i] = deg(fact[i], -1);

    int s = a + b - 2;

    vi res = prod(0, n - 1);
    i64 ans = res[s];
    (ans *= cnk(a - 1, b - 1)) %= P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}