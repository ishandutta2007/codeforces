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

const int P = 998244353;
const int maxn = 1100;
int dp[maxn][maxn], pdp[maxn][maxn];

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        (x *= x) %= P;
        d /= 2;
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

    int n, k;
    cin >> n >> k;
    vi a(n);
    forn(i, n) cin >> a[i];
    sort(all(a));
    int A = 100000;

    i64 cnk = 1;
    forn(i, k) (cnk *= n - i) %= P, (cnk *= deg(i + 1, -1)) %= P;
    i64 ans = 0;
    i64 prv = 0;
    forn(d, A / (k - 1) + 1) {
        int j = 0;
        forn(i, n) {
            while (a[i] - a[j] > d) ++j;
            dp[i][1] = 1;
            fore(l, 2, k) dp[i][l] = pdp[j][l - 1];
            for1(l, k) pdp[i + 1][l] = (pdp[i][l] + dp[i][l]) % P;
        }
        i64 val = cnk - pdp[n][k];
        (ans += d * (val - prv)) %= P;
        prv = val;
    }
    if (ans < 0) ans += P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}