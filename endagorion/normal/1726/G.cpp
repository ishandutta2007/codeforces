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

const int maxn = 510000;
const i64 P = 998244353;
int cnt[2][maxn];
i64 fact[maxn], tcaf[maxn], inv[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    inv[1] = 1;
    fore(i, 2, maxn - 1) inv[i] = P - P / i * inv[P % i] % P;
    fact[0] = tcaf[0] = 1;
    for1(i, maxn - 1) {
        fact[i] = i * fact[i - 1] % P;
        tcaf[i] = inv[i] * tcaf[i - 1] % P;
    }

    int n;
    cin >> n;
    vi a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];

    forn(i, n) ++cnt[b[i]][a[i]];
    if (a == vi(n, a[0])) {
        cout << fact[n] << '\n';
        return 0;
    }

    int p = 0;
    while (p <= 2 * n && !cnt[1][p]) ++p;
    if (p > 2 * n) {
        cout << 0 << '\n';
        return 0;
    }
    int x = p + n - 1;

    int sz = 0;
    i64 ans = 1;
    ford(d, n) {
        int sz0 = cnt[0][x - d];
        if (sz0 && sz < d) {
            ans = 0;
            break;
        }
//        if (sz0) cerr << d << ' ' << 0 << ' ' << sz0 << ' '<< sz << '\n';
        (ans *= fact[sz0]) %= P;
        sz += sz0;

        if (!d) break;

        int sz1 = cnt[1][x - d];
//        if (sz1) cerr << d << ' ' << 1 << ' ' << sz1 << ' '<< sz << '\n';
        if (sz1 > 1 || (sz1 && sz < n - 1 - d)) {
            ans = 0;
            break;
        }
        sz += sz1;
    }

    int rest = cnt[1][x];
    cerr << rest << '\n';
    sz += rest;
    i64 cnk = fact[n] * tcaf[n - rest] % P;
    (ans *= cnk) %= P;

    if (sz != n) ans = 0;
    cout << ans << '\n';
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}