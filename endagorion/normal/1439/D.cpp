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

i64 P;

const int maxn = 501;
i64 cnk[maxn][maxn];

pi64 operator*(pi64 a, pi64 b) {
    return {
        (a.fi * b.se + a.se * b.fi) % P,
        a.se * b.se % P
    };
}

pi64 operator*(pi64 a, i64 x) {
    return {a.fi * x % P, a.se * x % P};
}

pi64 operator+(pi64 a, pi64 b) {
    return {(a.fi + b.fi) % P, (a.se + b.se) % P};
}

pi64 seg[maxn];
pi64 dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m >> P;
    cnk[0][0] = 1;
    forn(i, m) forn(j, i + 1) forn(k, 2) (cnk[i + 1][j + k] += cnk[i][j]) %= P;

    seg[0] = {0, 1};
    for1(l, m) {
        forn(i, l) {
            pi64 r = {i * (i + 1) / 2 + (l - i) * (l - i - 1) / 2, l + 1};
            seg[l] = seg[l] + seg[i] * seg[l - i - 1] * r * cnk[l - 1][i];
        }
//        cerr << seg[l].fi << ' ' << seg[l].se << '\n';
    }

    forn(i, m + 1) dp[i][i] = seg[i];
    forn(i, n) forn(j, m + 1) {
        if (dp[i][j] == (pi64)mp(0, 0)) continue;
        if (j + n - i - 1 < m) continue;
        forn(l, m - j + 1) {
            int ni = i + 1 + l, nj = j + l;
            if (ni > n) break;
            dp[ni][nj] = dp[ni][nj] + dp[i][j] * seg[l] * cnk[nj][l];
        }
    }

    cout << dp[n][m].fi << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}