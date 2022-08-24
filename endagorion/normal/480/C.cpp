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

int dp[5001][5001], sdp[5001][5001];
const int P = 1000000000 + 7;

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, A, B, K;
    cin >> N >> A >> B >> K;
    --A; --B;
    dp[0][A] = 1;
    forn(i, N) sdp[0][i + 1] = (sdp[0][i] + dp[0][i]) % P;
    for1(i, K) {
        forn(j, N) {
            if (j == B) continue;
            int l, r;
            if (j < B) {
                l = 0;
//                l = max(0, j - abs(j - r));
                r = (j + B - 1) / 2;
            } else {
                r = N - 1;
//                r = min(N - 1, j + abs(j - l));
                l = (j + B) / 2 + 1;
            }
            dp[i][j] = sdp[i - 1][r + 1] - sdp[i - 1][l] - dp[i - 1][j];
            while (dp[i][j] < 0) dp[i][j] += P;
            sdp[i][j + 1] = (sdp[i][j] + dp[i][j]) % P;
        }
    }
    i64 ans = 0;
    forn(i, N) ans += dp[K][i];
    ans %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}