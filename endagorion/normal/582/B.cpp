#include <iostream>
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

vvi mul(const vvi &a, const vvi &b) {
    int n = a.size();
    vvi c(n, vi(n, -1e9));
    forn(i, n) forn(j, n) forn(k, n) uax(c[i][k], a[i][j] + b[j][k]);
    return c;
}

vvi deg(vvi a, int d) {
    int n = a.size();
    vvi c(n, vi(n, -1e9));
    forn(i, n) c[i][i] = 0;
    while (d) {
        if (d & 1) c = mul(c, a);
        a = mul(a, a);
        d /= 2;
    }
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

    int N, T;
    cin >> N >> T;
    vi a(N);
    forn(i, N) cin >> a[i];
    vvi A(N, vi(N, -1e9)), B(N, vi(N, -1e9));
    forn(i, N) forn(j, N) if (a[j] >= a[i]) B[i][j] = 1;
    forn(i, N) {
        vi dp(N, -1e9);
        dp[i] = 0;
        for (int j = i + 1; j < N; ++j) {
            forn(k, j) if (a[k] <= a[j]) uax(dp[j], dp[k] + 1);
        }
        forn(j, N) A[i][j] = dp[j];
    }
    vvi C = mul(deg(mul(A, B), T - 1), A);
    int ans = 0;
    forn(i, N) forn(j, N) uax(ans, C[i][j]);
    cout << ans + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}