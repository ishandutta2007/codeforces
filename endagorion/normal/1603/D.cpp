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

const int maxn = 100000;
i64 phi[maxn + 1];
i64 cp[maxn + 1];
i64 dp[21][maxn + 1];

int ceil(int a, int b) {
    if (!a) return 0;
    return (a - 1) / b + 1;
}

i64 f(int L, int R) {
    int k = 1;
    int r = R;
    i64 ans = 0;
    while (k * k <= R && r > L) {
        int nr = R / (k + 1);
        uax(nr, L);
//        cerr << k << ' ' << nr << ' ' << r << ' ' << cp[k] << '\n';
        ans += cp[k] * (r - nr);
        r = nr;
        ++k;
    }
    fore(i, L, r) ans += cp[R / i];
//    cerr << L << ' ' << R << ' ' << ans << '\n';
    return ans;
}

void dnc(int k, int L, int R, int l, int r) {
    if (L >= R) return;
//    cerr << k << ' ' << L << ' ' << R << ' ' << l << ' ' << r << '\n';
    int M = (L + R) / 2;
    int bestp = -1;
    int ptr = min(M, r);
    i64 ff = f(ptr + 1, M);
    while (ptr >= l) {
        if (uin(dp[k][M], dp[k - 1][ptr] + ff)) {
            bestp = ptr;
        }
        if (ptr) ff += cp[M / ptr];
        --ptr;
    }
//    assert(bestp != -1);
    dnc(k, L, M, l, bestp);
    dnc(k, M + 1, R, bestp, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    for1(i, maxn) phi[i] = i;
    for1(i, maxn) fore(j, 2, maxn / i) phi[i * j] -= phi[i];
    cp[1] = 1;
    fore(i, 2, maxn) cp[i] = cp[i - 1] + phi[i];
    forn(j, 21) forn(i, maxn + 1) dp[j][i] = 1e18;
//    for1(i, 5) fore(j, i, 5) f(i, j);
    dp[0][0] = 0;
//    for1(i, maxn) dp[1][i] = f(1, i);
    fore(k, 1, 20) {
//        cerr << k << '\n';
        dnc(k, 0, maxn + 1, 0, maxn + 1);
//        for1(j, 20) cerr << dp[k][j] << ' ';
//        cerr << '\n';
    }

    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k > 20) cout << n << '\n';
        else cout << dp[k][n] << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}