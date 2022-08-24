#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <ctime>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const i64 P = 1000000000 + 7;

typedef complex<double> base;
const double PI = atan2(0, -1);

void fft (vector<base> & a, bool invert) {
    int n = (int) a.size();
 
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
 
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

vi64 mul(vi64 a, vi64 b) {
    int n = 1;
    while (n < a.size() + b.size()) n *= 2;
    vector<vector<base> > ap(3, vector<base>(n)), bp(3, vector<base>(n));
    i64 s = cbrt(P);
    forn(i, a.size()) forn(j, 3) ap[j][i] = a[i] % s, a[i] /= s;
    forn(i, b.size()) forn(j, 3) bp[j][i] = b[i] % s, b[i] /= s;
    forn(i, 3) fft(ap[i], 0);
    forn(i, 3) fft(bp[i], 0);
    vi64 res(a.size());
    forn(i, 3) forn(j, 3) {
        vector<base> c(n);
        forn(k, n) c[k] = ap[i][k] * bp[j][k];
        fft(c, true);
        forn(k, a.size()) {
            i64 z = c[k].real() + 0.5; z %= P;
            forn(l, i + j) z *= s, z %= P;
            res[k] += z; res[k] %= P;
        }
    }
    return res;
}

i64 deg(i64 x, i64 d) {
    i64 y = 1;
    d %= P - 1;
    if (d < 0) d += P - 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

const int maxk = 50000;
i64 fact[maxk];

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

    i64 n, k;
    cin >> n >> k;
    if (n > k) {
        cout << 0 << '\n';
        return 0;
    }
    vi64 ex(k + 1);
    vvi64 exs(20, vi64(k + 1));
    for1(i, k) exs[0][i] = deg(fact[i], -1);
    forn(j, 19) {
        vi64 nex(k + 1);
        forn(i, k + 1) nex[i] = exs[j][i] * deg(2, 1LL * i * (1 << j)) % P;
        exs[j + 1] = mul(exs[j], nex);
    }
    vi64 p(k + 1);
    forn(i, k + 1) p[i] = deg(fact[i], -1);
    //p[0] = 1;
    int shift = 0;
    ford(i, 20) {
        if (n >= (1 << i)) {
            vi64 nex(k + 1);
            forn(j, k + 1) nex[j] = exs[i][j] * deg(2, 1LL * j * shift) % P;
            shift += 1 << i;
            n -= 1 << i;
            p = mul(p, nex);
        }
    }
    i64 ans = p[k] * fact[k] % P;
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}