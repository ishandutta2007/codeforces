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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXL = 300001;
const int MAXK = 5001;

i64 dp[MAXK][MAXK];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, K;
    cin >> N >> K;
    vi a(N);
    forn(i, N) cin >> a[i];
    sort(all(a));
    int s0 = N / K, s1 = s0 + 1;
    int q1 = N % K, q0 = K - q1;
    cerr << q0 << ' ' << q1 << '\n';
    forn(i, K + 1) forn(j, K + 1) dp[i][j] = 1e18;
    dp[0][0] = 0;
    forn(i, K) forn(j, K) {
        if (dp[i][j] > 1e17) continue;
        int u = i * s0 + j * s1;
        if (i < q0) uin(dp[i + 1][j], dp[i][j] + a[u + s0 - 1] - a[u]);
        if (j < q1) uin(dp[i][j + 1], dp[i][j] + a[u + s1 - 1] - a[u]);
    }
    cout << dp[q0][q1] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}