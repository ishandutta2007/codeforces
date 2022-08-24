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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 3000;
const i64 P = 1000000000 + 7;

i64 dp[maxn][maxn][2];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    string s;
    cin >> N >> K >> s;
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dp[i + 1][j][0] += (dp[i][j][0] + dp[i][j][1]) * (s[i] - 'a');
            dp[i + 1][j][0] %= P;
            dp[i + 1][j][1] += (dp[i][j][0] + dp[i][j][1]);
            dp[i + 1][j][1] %= P;
            int k;
            for (k = 0; k + i < N && j + (k + 1) * (N - k - i) <= K; ++k) {
                dp[i + k + 1][j + (k + 1) * (N - k - i)][0] += dp[i][j][0] * ('z' - s[i + k]);
                dp[i + k + 1][j + (k + 1) * (N - k - i)][0] %= P;
            }
            if (k + i < N) {
                for (k = N - i - 1; k >= 0 && j + (k + 1) * (N - k - i) <= K; --k) {
                    dp[i + k + 1][j + (k + 1) * (N - k - i)][0] += dp[i][j][0] * ('z' - s[i + k]);
                    dp[i + k + 1][j + (k + 1) * (N - k - i)][0] %= P;
                }
            }
        }
    }

    i64 ans = (dp[N][K][0] + dp[N][K][1]) % P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}