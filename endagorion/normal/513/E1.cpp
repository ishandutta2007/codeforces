#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


const int MAXN = 31000;
const int MAXK = 211;
i64 dp[MAXN][MAXK][4][2];
int a[MAXN];

int N, K;

int appr[4][4] = {{0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}};
int w[4] = {-2, 0, 2, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> K;
    forn(i, MAXN) cin >> a[i];
    forn(i, N + 1) forn(j, K + 1) forn(s, 5) forn(z, 2) dp[i][j][s][z] = -1e9;
    dp[0][0][0][0] = 0;
    forn(i, N) forn(j, K + 1) forn(s, 4) forn(z, 2) {
        if (dp[i][j][s][z] == -1e9) continue;
        i64 res = dp[i][j][s][z];
        uax(dp[i + 1][j][s][0], res);
        if (z) uax(dp[i + 1][j][s][1], res + a[i] * w[s] / ((j == 1 || j == K) ? 2 : 1));
        forn(ss, 4) {
            if ((j == 0 || j == K - 1) && (ss == 1 || ss == 3)) continue;
            if (j == 0 || appr[s][ss]) uax(dp[i + 1][j + 1][ss][1], res + a[i] * w[ss] / ((j + 1 == 1 || j + 1 == K) ? 2 : 1));
        }
    }
    i64 ans = -1e9;
    forn(s, 4) forn(z, 2) uax(ans, dp[N][K][s][z]);
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}