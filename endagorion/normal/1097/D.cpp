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

const int maxk = 11000;
const i64 P = 1000000000 + 7;

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    d %= P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
    }
    return y;
}

i64 inv[200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 n;
    int k;
    cin >> n >> k;
    vector<pi64> factor;
    for (i64 p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            int d = 0;
            while (n % p == 0) {
                n /= p;
                ++d;
            }
            factor.pb({p, d});
        }
    }

    if (n > 1) factor.pb({n, 1});

    for1(i, 100) inv[i] = deg(i, -1);

    i64 ans = 1;
    for (auto w: factor) {
        i64 p = w.fi, d = w.se;
        vi64 probs(d + 1);
        probs[d] = 1;
        forn(i, k) {
            vi64 nprobs(d + 1);
            forn(i, d + 1) forn(j, i + 1) (nprobs[j] += probs[i] * inv[i + 1]) %= P;
            probs = nprobs;
        }

        i64 res = 0;
        forn(i, d + 1) (res += probs[i] * deg(p, i)) %= P;
        (ans *= res) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}