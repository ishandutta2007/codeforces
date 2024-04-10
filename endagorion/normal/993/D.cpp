#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef long double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxa = 110, maxn = 51;
vector<pi64> a;
i64 dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    a.resize(n);
    forn(i, n) cin >> a[i].fi, a[i].fi *= 1000;
    forn(i, n) cin >> a[i].se;

    sort(rall(a));
    i64 L = 0, R = 1.1e11;
    while (R - L > 1) {
        i64 M = (L + R) / 2;
        forn(i, n + 1) forn(j, n + 1) dp[i][j] = 1e18;
        dp[0][0] = 0.0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[i].fi == a[j].fi) ++j;
            int l = j - i;
            i64 total = 0.0;
            forn(z, l + 1) {
                forn(k, n + 1) if (dp[i][k] < 1e17 && k >= l - z) uin(dp[j][k - (l - z) + z], dp[i][k] + total);
                if (z < l) total += a[i + z].fi - a[i + z].se * M;
            }
            i = j;
        }
        bool ok = false;
//        cerr << M << ' ' << *min_element(dp
        forn(i, n + 1) ok |= dp[n][i] <= 0;
        (ok ? R : L) = M;
    }

    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}