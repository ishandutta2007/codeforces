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

i64 dp[501][501];
i64 d2[501 * 500];
const i64 P = 1000000000 + 7;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K;
    cin >> N >> K;
    dp[0][0] = 1;
    d2[0] = 1;
    forn(i, 500 * 500) {
        d2[i + 1] = d2[i] * 2 % P;
    }
    i64 ans = 0;
    forn(r, N) {
        forn(k, K) {
            for (int rr = r + 1; rr <= N; ++rr) {
                i64 Q = d2[(rr - r - 1) * r];
                Q *= d2[rr] - d2[r] + P;
                Q %= P;
                dp[rr][k + 1] += dp[r][k] * Q % P;
                dp[rr][k + 1] %= P;
            }
        }
    }
    forn(r, N + 1) {
        ans += dp[r][K] * d2[(N - r) * r] % P;
    }
    ans %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}