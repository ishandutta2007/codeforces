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
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int MAXN = 1000010;
int a[MAXN];
i64 dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    scanf("%d", &N);
    forn(i, N) scanf("%d", &a[i]);
    dp[0] = dp[1] = 0;
    int extr = 0;
    bool ismin = true, ismax = true;
    for (int i = 1; i < N; ++i) {
        if (a[i] == a[i - 1]) {
            extr = i - 1;
            ismin = ismax = true;
        }
        if (a[i] < a[i - 1] && ismin) {
            extr = i - 1;
            ismax = true;
            ismin = false;
        }
        if (a[i] > a[i - 1] && ismax) {
            extr = i - 1;
            ismin = true;
            ismax = false;
        }
        dp[i + 1] = abs(a[i] - a[extr]) + dp[extr];
        dp[i + 1] = max(dp[i + 1], abs(a[i] - a[extr + 1]) + dp[extr + 1]);
    }
    cout << dp[N] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}