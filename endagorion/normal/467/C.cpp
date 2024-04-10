#include <iostream>
#include <vector>
#include <cassert>
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
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)((n) - 1); i >= 0; --i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define debugv(a) forn(i, a.size()) cerr << a[i] << ' '; cerr << '\n'

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

typedef long double ld;

i64 dp[5100][5100], s[10000];

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    forn(i, N) {
        int x;
        cin >> x;
        s[i + 1] = s[i] + x;
        if (i + 1 >= M) {
            forn(j, K + 1) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i - M + 1][j] + s[i + 1] - s[i - M + 1]);
            }
        }
    }
    cout << dp[N][K] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}