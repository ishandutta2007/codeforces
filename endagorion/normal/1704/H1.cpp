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

const int maxn = 5100;
i64 P;
int cnk[maxn][maxn];
int deg[maxn][maxn];
i64 dp[maxn];
i64 fact[maxn];

/*i64 deg(i64 x, i64 d) {
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n >> P;
    cnk[0][0] = 1;
    forn(i, n) forn(j, i + 1) forn(k, 2) (cnk[i + 1][j + k] += cnk[i][j]) %= P;
    fact[0] = 1;
    for1(i, n) fact[i] = i * fact[i - 1] % P;
    forn(x, n) {
        deg[x][0] = 1;
        for1(y, n) deg[x][y] = 1LL * deg[x][y - 1] * x % P;
    }

    i64 ans = 0;
    forn(s, n + 1) for1(p, n) {
        if (s + 2 * p > n) continue;
        i64 res = cnk[n][s];
        (res *= cnk[n - s][p]) %= P;
        (res *= deg[n - s - p][s]) %= P;
        (res *= deg[n - 1][p]) %= P;
        int f = n - p - s;
        (res *= fact[f] * cnk[f - 1][p - 1] % P) %= P;
        (ans += res) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}