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

int dp[2001][2001];
const int P = 1000000000 + 7;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    dp[0][1] = 1;
    int N, K;
    cin >> N >> K;
    forn(i, K) {
        for (int j = 1; j <= N; ++j) {
            for (int l = 1; l * j <= N; ++l) {
                dp[i + 1][l * j] += dp[i][j];
                dp[i + 1][l * j] %= P;
            }
        }
    }
    int ans = 0;
    for (int j = 1; j <= N; ++j) {
        ans += dp[K][j];
        ans %= P;
    }            
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}