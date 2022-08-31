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

int a[101];
double dp[201][30][30];

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
    forn(i, N) cin >> a[i];
    forn(i, N) forn(j, N) {
        if (a[i] < a[j]) ++dp[0][i][j];
    }
    forn(k, K) {
        forn(i, N) forn(j, N) {
            if (dp[k][i][j] < 1e-9) continue;
            forn(r, N) forn(l, r + 1) {
                int ii = (l <= i && i <= r ? r + l - i : i);
                int jj = (l <= j && j <= r ? r + l - j : j);
                dp[k + 1][ii][jj] += dp[k][i][j] / (0.5 * N * (N + 1));
            }
        }
    }

    double ans = 0.0;
    forn(i, N) forn(j, i) ans += dp[K][i][j];
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}