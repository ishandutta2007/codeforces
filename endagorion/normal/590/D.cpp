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

int dp[2][76][25000];
int a[200];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, K, S;
    cin >> N >> K >> S;
    forn(i, N) cin >> a[i];
    bool sw = false;
    if (K > N / 2) {
        K = N - K;
        reverse(a, a + N);
        forn(i, N) a[i] = -a[i];
        sw = true;
    }
    dp[0][0][0] = 0;
    forn(i, N) {
        forn(j, min(i + 1, K) + 1) forn(l, (i + 1) * N + 1) dp[1][j][l] = 1e9;
        forn(j, min(i, K) + 1) forn(l, i * N + 1) {
            if (j < K) uin(dp[1][j + 1][l + abs(i - j)], dp[0][j][l] + a[i]);
            uin(dp[1][j][l + abs(i - (K + i - j))], dp[0][j][l]);
        }
        forn(j, min(i + 1, K) + 1) forn(l, (i + 1) * N + 1) dp[0][j][l] = dp[1][j][l];
    }
    int ans = 1e9;
    forn(d, min(N * N, 2 * S) + 1) uin(ans, dp[0][K][d]);
    if (sw) forn(i, N) ans -= a[i];
    cout << ans << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}